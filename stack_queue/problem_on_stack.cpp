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
//! infix to post_fix

int priority(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}
string infix_to_post_fix(string s){
    stack<char>st;
    string ans = "";
    for(int i=0;i<s.size();i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')
        || (s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else{
            while (!st.empty() && priority(s[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

//! infix to prifix

int priority_check__(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return 0;
}
string infix_to_prifix(string s){
    // step1 reverse the infix
    reverse(s.begin(),s.end());
    // Step2: fixing the bricket
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }
    //step3 convert infix to post fix

    stack<char>st;
    string ans = "";
    for(int i=0;i<s.size();i++){
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
             while (!st.empty() && priority_check__(s[i]) < priority_check__(st.top()) ||
                   (!st.empty() && priority_check__(s[i]) == priority_check__(st.top()) && s[i] != '^')) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    // step4 reverse the ans;
    reverse(ans.begin(),ans.end());
    return ans;
}

//! post fix to infix
string post_fix_to_infix(string s){
    stack<string>st;
    for(int i=0;i<s.size();i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')
        || (s[i]>='0' && s[i]<='9')){
            string temp = "";
            temp+=s[i];
            st.push(temp);
        }
        else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            string final = '('+top2+s[i]+top1+')';
            st.push(final);
        }
        
    }
    return st.top();
}

//! prefix to infix
string prefix_infix(string s){
    stack<string>st;
    for(int i=s.size()-1;i>=0;i--){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')
        || (s[i]>='0' && s[i]<='9')){
            string temp = "";
            temp+=s[i];
            st.push(temp);
        }
        else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            string final = '('+top1+s[i]+top2+')';
            st.push(final);
        }
    }
    return st.top();
}

//! postfix to prefix
string postfix_to_prefix(string s){
    stack<string>st;
    for(int i=0;i<s.size();i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')
        || (s[i]>='0' && s[i]<='9')){
            string temp = "";
            temp+=s[i];
            st.push(temp);
        }
        else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            string final = s[i]+top2+top1;
            st.push(final);
        }
    }
    return st.top();
}

//!prefix to postfix
string prefix_to_postfix(string s){
    stack<string>st;
    for(int i=s.size()-1;i>=0;i--){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')
        || (s[i]>='0' && s[i]<='9')){
            string temp = "";
            temp+=s[i];
            st.push(temp);
        }
        else{
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            string final = top1+top2+s[i];
            st.push(final);
        }
    }
    return st.top();
}
int main(){
    string s;
    cout<<"\nenter the string = ";
    cin>>s;
    // if(is_balance_parantheses(s)){
    //     cout<<"\nyes it is balance.";
    // }
    // else{
    //     cout<<"\nno it is not balance.";
    // }
    // string infixToPostFix = infix_to_post_fix(s);
    // cout<<"\n Infix to post fix = "<<infixToPostFix;

    // string InfixToPrifix = infix_to_prifix(s);
    // cout<<"\n Infix to pre fix = "<<InfixToPrifix;

    // string PostfixToinfix = post_fix_to_infix(s);
    // cout<<"\n post fix to infix = "<<PostfixToinfix;

    // string PrefixInfix = prefix_infix(s);
    // cout<<"\n prefix to infix = "<<PrefixInfix;

    // string PostfixPrefix = postfix_to_prefix(s);
    // cout<<"\n postfix to prefix = "<<PostfixPrefix;

    string PrefixPostfix = prefix_to_postfix(s);
    cout<<"\n prefix to postfix = "<<PrefixPostfix;
}