/*

 author - Mohammad Chand Alam
 from - Aligarh Muslim University, India.
*/


// # Stack #Balanced Parenthesis


#include <bits/stdc++.h>
using namespace std;
const int M = (int) 1e9 + 7;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

bool check_stack_symbol(string str){

stack <char> s;
for(int i=0;i<str.size();i++){
    if(str[i]=='[' || str[i]=='{' || str[i]=='(')
        s.push(str[i]);

    if(s.empty())
        return false;

    if(str[i]==')'){

        char x = s.top();
        s.pop();
        if(x=='{' || x=='[')
        return false;
    }


    if(str[i]==']'){

        char x = s.top();
        s.pop();
        if(x=='{' || x=='(')
        return false;
    }

    if(str[i]=='}'){

        char x = s.top();
        s.pop();
        if(x=='(' || x=='[')
        return false;
    }

}
  return(s.empty());

}

int main(){

    fastio;
    string str;
    cin>>str;
    if(check_stack_symbol(str))
    cout<<"Balanced";
    else
    cout<<"Unbalanced";

    return 0;
}
