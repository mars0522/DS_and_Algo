// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class obj
{
public:
    long long inc;
    long long exc;
    obj(int inc, int exc)
    {
        this->inc = inc;
        this->exc = exc;
    }
};

class Solution {
public:
    //Function to return the maximum sum of non-adjacent nodes.

    obj fun(Node*  root)
    {
        obj p(0, 0);

        if (root == NULL)
            return p;

        obj left = fun(root->left);
        obj right = fun(root->right);

        p.inc = root->data + left.exc + right.exc;
        p.exc = max(left.inc, left.exc) + max(right.inc, right.exc);

        return p;
    }
    int getMaxSum(Node *root)
    {
        // Add your code here

        obj ans = fun(root);

        return max(ans.inc, ans.exc);
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.getMaxSum(root) << endl;
    }
    return 0;
}  // } Driver Code Ends