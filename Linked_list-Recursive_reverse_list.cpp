#include<iostream>
using namespace std;

struct node
{
int data;
struct node* next;
};

struct node *head;

struct node *Create(node *head,int data)
{
    node *temp=new node();
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    head=temp;
    else
    {
        node *temp1=head;
        while(temp1->next!=NULL)
          temp1=temp1->next;
          temp1->next=temp;
    }
    return head;
}
Print(struct node *p)
{
    if(p==NULL)
    return 0;
    cout<<p->data<<" ";
    Print(p->next);

}
Reverse(struct node *p)
{
        if(p==NULL)
        return 0;
        Reverse(p->next);
        cout<<p->data<<" ";
}
int main()
{
    cout<<"Enter how many number you wants to enter\n";
    int n;
    struct node* head=NULL;
cin>>n;
for(int i=0;i<n;i++)
{
    cout<<"enter data\n";
    int d;
    cin>>d;
    head=Create(head,d);
}
    cout<<"Entered data is\n";
    Print(head);
    cout<<"\nReverse data is \n";               //NOW ITS TIME TO SHOW THE POWER OF RECURSIVE CALL ON STACK
    Reverse(head);
    return 0;
}
