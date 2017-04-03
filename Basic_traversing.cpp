#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *temp1;

struct node *Create(node *head, int x)
{                                              //my code
   /* node *temp=new node();
    if(head!=NULL)
    {
        temp->data=x;
        head->next=temp;
        temp->next=NULL;
        head=temp;
    }
    else
    {
        temp->data=x;
        temp->next=NULL;
        head=temp;
        temp1=temp;
    }
 return head; */
  node *tmp = new  node();                 //new code
  tmp->data = x;
  tmp->next = NULL;

    if(head == NULL)
    {
    head=tmp;
    temp1=tmp;
    return head;
    }

  node *current = head;
  while(current->next != NULL)
    {
    current = current->next;
    }
   current->next = tmp;
return head;
}

void Print(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
}


struct node* Reverse(struct node* head)
{
    struct node *prev,*current ,*next;
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}


int main()
{
    struct node* head=NULL;
    int n;

    cout<<"Enter how many number you want to enter "<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int t;
        cout<<"Enter "<<i+1<<" data"<<"\n";
        cin>>t;
        head=Create(head,t);
    }

    cout<<"\nGiven List is\n";
     Print(temp1);
     cout<<endl;

    head=Reverse(temp1);

    cout<<"\nReverse list is\n";
    Print(head);
return 0;
}
