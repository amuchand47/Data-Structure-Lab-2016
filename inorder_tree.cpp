/*

author : Mohammad Chand Alam
Aligarh Muslim University

*/

#include <bits/stdc++.h>
using namespace std;

struct node {
int data;
node *left;
node *right;
};

struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));

  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

void inorder(node *tmp){
  if (tmp == NULL)
    return ;
  inorder(tmp->left);
  cout<<tmp->data<<" ";
  inorder(tmp->right);
}

int main(int num, char *agrv[]){

    cout<<"Enter the root node \n";
    int x;
    cin>>x;
    struct node *root = newNode(x);
    struct node *temp = root;
    while(1){
        cout<<"Do u want to enter the node again \n";
        cout<<"Enter Y for Yes or enter N for No \n";
        char cc;
        cin>>cc;
        if (cc=='Y'){
        int x;
        cout<<"Enter the node value \n";
        cin>>x;
        struct node *crt = newNode(x);
        cout<<"Where do you want to enter this node \n";

        cout<<"Left or Right \n";
        cout<<"L for left entering , R for right entering  \n";
        char ch;
        cin>>ch;

        /*
        if (root->left == NULL && root ->right ==NULL){
            cout<<"Your both right and left nodes are free Enter where you want to Enter \n";


        if (ch =='L'){
          temp ->left = crt ;
          temp = crt ;
        }
        else{
          temp ->right = crt;
          temp = crt ;
        }

        }
        else if (root->left != NULL && root ->right ==NULL){
            cout<<"Here your Left node is free Enter if you wants to enter here or "
        }

        */

        if (ch =='L'){
          temp ->left = crt ;
          temp = crt ;
        }
        else{
          temp ->right = crt;
          temp = crt ;
        }

        }
        else
        break;
    }
    cout<<"The inorder of the tree is \n";
    inorder(root);

    return 0;
}
