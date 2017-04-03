#include<iostream>
using namespace std;

struct node
{
 int data;
 node *next;
};

node *Create(node *head,int data)
{
    node *temp=new node();
    temp->data=data;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        return head;
    }

    node *current =head;
    while(current->next!=NULL)
    {
        current=current->next;
    }

    current->next=temp;
    return head;
}

Print(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

node *Cut_last(node *head)        //1 2 3 4 5->NULL
{
    node *t=head;
    node *temp=new node();

    while(head->next->next!=NULL)
    {
        head=head->next;
    }
    temp->data=head->next->data;
    head->next=NULL;
    temp->next=t;
    return temp;
}

int main()
{

   node *head=NULL;
   int n;
   cout<<"Enter how many number you want to enter \n";
   cin>>n;
   cout<<"Enter data into the list \n";
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       head=Create(head,x);
   }
   cout<<"Given list is \n";
   Print(head);
   cout<<"List with last moved to first are \n";
   Print(Cut_last(head));
    return 0;
}
