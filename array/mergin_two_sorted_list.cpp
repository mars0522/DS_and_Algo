#include <iostream>

using namespace std;
class node
{
   public:
   int data;
   node* next;
   node(int data)// constructor of the node
   {
      this->data=data;
      next=NULL;
   }
};
void add_node(node** head,node** last,int data)// adding node at the end the list i.e. O(1)
{
     node* new_node=new node(data);
       if(*head==NULL)// code for very first element to be added
       {
           *head=new_node;
           *last=new_node;
       }
       else
       {
           (*last)->next=new_node;// when list has already elements
           *last = (*last)->next;
       }

}
node* Merging(node* head1,node* head2)
{
     node *head3,*last;
     head3=last=NULL;
     if(head1==NULL && head2)
     return head2;
     else if(head2==NULL && head1)
     return head1;
     else
     {
         if(head1->data < head2->data)
         {
              head3=last=head1;
              head1=head1->next;
              last->next=NULL;
         }
         if(head2->data < head1->data)
         {
              head3=last=head2;
              head2=head2->next;
              last->next=NULL;
         }

         while(head1 && head2)
         {

            if(head1->data < head2->data)

           {
            last->next=head1;
            head1=head1->next;
            last=last->next;
            last->next=NULL;
           }
             if(head2->data < head1->data)

           {
             last->next=head2;
             head2=head2->next;
             last=last->next;
             last->next=NULL;
           }
        }
    if(head1)
    last->next=head1;
    if(head2)
    last->next=head2;
    return head3;


      }

}
void print_list(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
   node* head1=NULL,*head2=NULL,*last=NULL;
   /*add_node(&head1,&last,2);
   add_node(&head1,&last,4);
   add_node(&head1,&last,6);
   add_node(&head1,&last,8);
   last=NULL;*/
   add_node(&head2,&last,1);
   add_node(&head2,&last,3);
   add_node(&head2,&last,5);
   add_node(&head2,&last,7);
   print_list(head1);
   print_list(head2);
   node* head3=Merging(head1,head2);
   print_list(head3);

    return 0;
}
