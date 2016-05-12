#include <iostream>
#include <stdlib.h>
#include <string>
int count;
using namespace std;
struct node
{
    string info;
    node *next;
}*start,*last,*var,*pri,*sort_pri;
struct node *create_new(string str )
{
    node *temp;
    temp=new node;
    temp->info=str;
    temp->next=NULL;
    if(temp==NULL)
    {
        cout<<"!!!! Aborting No Space avail in Memory ";
        exit(0);
    }
    return temp;
}

void del(node *n)
{
    if(n)
        del(n->next);
    delete n;
}

void search(node *p, string s)
{
    if(p)
    {
        if(s==p->info){var=p; count++;}
        else
            pri=p;
            search(p->next,s);
    }
}

void end(node *p)
{
    if(p->next==NULL)
        last=p;
    else
    {
        pri=p;
        end(p->next);
    }
}

void display(node * np)
{
    if(np)
    {
        cout<<np->info<<"->";
        display(np->next);
    }
}
void Insertion (int n)
{
    node *np,*temp;;
    string str;
    switch(n)
    {
    case 1:
    {
        cout<<"\n Enter info that you want insert\n";
        cin>>str;
        np=create_new(str);
        if(start==NULL)
            start=last=np;
        else
        {
            np->next =start;
            start=np;
        }
        break;
    }
    case 2:
    {
        cout<<"\n Enter info that you want insert\n";
        cin>>str;
        np=create_new(str);
        if(start==NULL)
            start=last=np;
        else
        {
            end(start);
            last->next=np;
            last=last->next;
        }
        break;
    }
    case 3:
    {
        cout<<"\n Enter info after which you want insert\n";
        cin>>str;
        var=NULL;
        search(start,str);
        if(var!=NULL)
        {
            cout<<"\n Enter info that you want insert\n";
            cin>>str;
            np=create_new(str);
            np->next=var->next;
            var->next=np;
        }
        else cout<<"\n Not Found";
        break;
    }
    }
}
void Deletion (int n)
{
    node *temp;
    string str;
    switch(n)
    {
    case 4:
    {
        if(start==NULL)
            cout<<"List is Already  Empty ";
        else
        {
            temp=start->next;
            delete start;
            start=temp;
        }
        break;
    }
    case 5:
    {
        if(start==NULL)
            cout<<"List is Already  Empty ";
        else
        {
            end(start);
            pri->next=NULL;
            delete last;
        }
        break;
    }
    case 6:
    {
        if(start==NULL)
            cout<<"List is Already  Empty ";
        else
        {
            cout<<"\n Enter info of Node that you want to Delete\n";
            cin>>str;
            var=NULL;
            pri=NULL;
            search(start,str);
            if(var!=NULL)
            {
                if(pri!=NULL)
                {
                    pri->next=var->next;
                    delete var;
                }
                else
                {
                    temp=start->next;
                    delete start;
                    start=temp;
                }
            }
            else cout<<"\n Not Found";
        }
        break;
    }
    }
}

void Menu()
{
    cout<<"\n\n\t\t\t ****MAIN MENU****";
    cout<<"\n 1. Create/Add Link List ";
    cout<<"\n 2. Insertion / Deletion Link list ";
    cout<<"\n 3. Searching element ";
    cout<<"\n 4. Sorting of link list (Lexicography Only) ";
    cout<<"\n 5. Delete Whole Link list ";
    cout<<"\n 6. Exit\n\n ";
    display(start);
    cout<<"\n";

}
void Menu2()
{
    cout<<"\n\n\t\t\t ****Edit Link List****";
    cout<<"\n 1. Insert At Beginning ";
    cout<<"\n 2. Insert At End ";
    cout<<"\n 3. Insert At your choice ";
    cout<<"\n 4. Delete First Node ";
    cout<<"\n 5. Delete Last Node ";
    cout<<"\n 6. Delete Node that you want";
    cout<<"\n 7. Back To Main Menu ";
    cout<<"\n 8. Exit\n\n";

    display(start);
    cout<<"\n";
}
void editing()
{
    string str;
    node *curr;

    cout<<"\n Enter Info\n ";
    cin>>str;
    curr=create_new(str);
    if(start==NULL)
        start=last=curr;
    else
    {
        end(start);
        last->next=curr;
        last=last->next;
    }
    cout<<"\n Successful \n\n List : ";
    display(start);

}

void min(node *last,node *p,string ss)
{
    if(p)
    {
        if(ss>p->info)
        {
            var=p;
            ss=p->info;
            pri=last;

        }
        min(p,p->next,ss);
    }
}
void sort(node *pt)
{
    if(pt->next)
    {
        var=pt;
        if(pt==start)
            pri=NULL;
        min(pt,pt->next,pt->info);
        if(var!=pt)
        {
            pri->next=var->next;
            var->next=pt;
            if(pt==start)
                start=var;
            else sort_pri->next=var;
            pt=var;
        }
        sort_pri=pt;
        sort(sort_pri->next);
    }
}

int main()
{char ch_1;
    string srch;
    int n,n2;
    do
    {
        Menu();
        cin>>n;
        switch(n)
        {
        case 1:
        {
            do
            {
                editing();
                cout<<"\n\n Want to Enter More info ?(y/n)";
                cin.ignore();
                cin>>ch_1;
            }
            while((ch_1=='y')||(ch_1=='Y'));
            break;
        }
        case 2:
        {
            do
            {
                Menu2();
                cin>>n2;
                if((n2<=3)&&(n2>=1)) Insertion(n2);
                else if ((n2<=6)&&(n2>=4)) Deletion(n2);
                else if (n2==8) exit(0);
                else if(n2!=7) cout<<"\nWrong Choice....";
                cout<<endl;
                display(start);


            }
            while(n2!=7);
            break;
        }

        case 3:
        {
            if(start==NULL)
                cout<<"\nList is already Empty";
            else
            {
                cout<<"\nEnter Element that you want to search....  ";
                cin>>srch;
                var=NULL;
              count=0;
                pri=NULL;
                search(start,srch);
                if(var) cout<<" Founded... "<<count <<" times";
                else cout<<"NOT Found... ";
            }
            break;
        }
        case 4:
        {
            if(start==NULL)
                cout<<"\nList is already Empty";
            else
                sort(start);
            break;
        }
        case 5:
        {
            if(start==NULL)
                cout<<"\nList is already Empty";
            else
            {
                del(start);
                start=NULL;
                cout<<"\n Deleted....";

            }
            break;
        }
        case 6:
            exit(0);

        default :
        {
            cout<<"\n\n !! Wrong Choice...";
            break;
        }
        }
        cout<<endl<<endl;
        display(start);
    }
    while(n!=6);
    del(start);
    return 0;
}
