#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<char>&arr,int n){
    for(int i=0;i<n;i++){
        char c;
        cout<<"\nenter the array element = ";
        cin>>c;
        arr.push_back(c);
    }
}
void print_array(vector<char>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
}
//! find the smallest number after removing k element.
vector<char> smallest_number(vector<char>&arr,int n,int k){
    stack<char>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && st.top()-'0'>arr[i]-'0'){
            st.pop();
            k=k-1;
        }
        st.push(arr[i]);
    }
    while(k>0){
        st.pop();
        k--;
    }
    if(st.empty()) return {'0'};
    vector<char>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    for(int i=ans.size()-1;i>=0;i--){
        if(ans[i]=='0') ans.pop_back();
        else break;
    }
    reverse(ans.begin(),ans.end());
    if(ans.empty()) return {'0'};
    return ans;
}
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    vector<char>v;
    input_array(v,n);
    cout<<endl;
    print_array(v,n);
    vector<char>ans = smallest_number(v,n,3);
    cout<<endl;
    print_array(ans,ans.size());
}