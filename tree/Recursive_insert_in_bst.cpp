#include <iostream>

using namespace std;
// This program is about constructing BST using iterative insert function
class node
{
    public:
    int data;
    node* lchild;
    node* rchild;
    node(int data)
    {
         this->data=data;
         lchild=rchild=NULL;
    }
};
node* rinsert(node* root,int data)
{
    if(root==NULL)// if root is empty or the pointer reaches the leaf node then new node is attached and
    // its address is sent to the the parent node
    {
       root=new node(data);

    }
    else if(root->data==data)// if key alreay exit then no need to add
    {
        cout<<"\nKey already present in the tree "<<endl;

    }
    else if(data < root->data)// if data is lesser than the current node , then add node to the left of the current node
    {
        root->lchild=rinsert(root->lchild,data);
    }
    else
    root->rchild=rinsert(root->rchild,data);// if data is greater than the current node then add the node to the right of the
    // current node
    return root;// finally return the modified root


}
void inorder(node* t)
{
   if(t)
   {
       inorder(t->lchild);
       cout<<t->data<<"  ";
       inorder(t->rchild);
   }
}

int main()
{
    int a[]={5,4,3,6,7,8,9,1,2};
    node* root=NULL;

    for(int i=0;i<(sizeof(a)/(sizeof(int)));i++)
    root=rinsert(root,a[i]);

    cout<<"\nInorder traversal of the tree is: ";
    inorder(root);

    return 0;
}
