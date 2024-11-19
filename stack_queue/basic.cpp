#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int num;
        cout<<"\nenter the element of array = ";
        cin>>num;
        arr.push_back(num);
    }
}
void print_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
}

void use_stack(vector<int>&arr,int n){
    stack<int>st;
    for(int i=0;i<n;i++){
        st.push(arr[i]);
    }
    st.pop();
    cout<<"\ntop element = "<<st.top();
    st.pop();
    cout<<"\ntop element = "<<st.top();
    cout<<"\nsize of the stack = "<<st.size();
}

// use queue
void use_queue(vector<int>&arr,int n){
    queue<int>q;
    for(int i=0;i<n;i++){
        q.push(arr[i]);
    }
    q.pop();
    cout<<"\ntop element = "<<q.front();
    q.pop();
    cout<<"\ntop element = "<<q.back();
    cout<<"\nsize of the queue = "<<q.size();
}
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    vector<int>arr;
    input_array(arr,n);
    print_array(arr,n);
    use_stack(arr,n);
    use_queue(arr,n);
}