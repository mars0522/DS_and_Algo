#include <iostream>

using namespace std;
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
node* bst_insertion(node* t,int key)
{
    node *root=t,*r=NULL,*p;
    if(t==NULL)// initially when there is no node in the tree
    {
        t=new node(key);
        return t;
    }
    else
    {
        while(t)  // when tree is not empty
        {
            if(t->data==key)
            {
                // if key already present then return
                cout<<"\nKey already exists"<<endl;
                return t;
            }
            else if(t->data < key)// else traverse the tree to find suitable leaf node
            {
                r=t;
                t=t->rchild;
            }
            else
            {
                r=t;
                t=t->lchild;
            }
        }
        // here t becomes null and r is pointing to the node to which new key node is to be added
        p=new node(key);
        if(key > r->data)
            r->rchild=p;// if key is greater than the last node then add key right side of the last node
        else
            r->lchild=p;// if key is smaller than the last node then add key left side of the last node
        return root;// finally return the modified root node of the tree
    }
}
void inorder_traversal(node* t)
{
    if(t)
    {
        inorder_traversal(t->lchild);
        cout<<t->data<<" ";
        inorder_traversal(t->rchild);
    }
}
void preorder_traversal(node* t)
{
    if(t)
    {
        cout<<t->data<<" ";
        preorder_traversal(t->lchild);
        preorder_traversal(t->rchild);
    }
}
void postorder_traversal(node* t)
{
    if(t)
    {
        postorder_traversal(t->lchild);
        postorder_traversal(t->rchild);
        cout<<t->data<<"  ";
    }
}
node* recursive_insert(node* t, int data)
{
    if(t==NULL)
    {

    }
    else

}

int main()
{
    node* root=NULL;
    int a[]= {1,2,3,4,5,6,7,8};

    for(int i=0; i<8; i++)
        root= bst_insertion(root,a[i]);

    cout<<"\npreorder traversal of the bst is: ";
    preorder_traversal(root);
    cout<<"\nInorder traversal of the bet is:  ";
    inorder_traversal(root);
    cout<<"\nPostorder traversal of the bst is:  ";
    postorder_traversal(root);
    return 0;
}
