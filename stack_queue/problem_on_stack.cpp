#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool is_balance_parantheses(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.top()=='(') st.pop();
        }
        else if(s[i]=='}'){
            if(st.top()=='{') st.pop();
        }
        else{
            if(st.top()=='[') st.pop();
        }
    }
    return st.size()==0;
}

int main(){
    string s;
    cout<<"\nenter the string = ";
    cin>>s;
    if(is_balance_parantheses(s)){
        cout<<"\nyes it is balance.";
    }
    else{
        cout<<"\nno it is not balance.";
    }
}