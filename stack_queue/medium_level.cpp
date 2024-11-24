#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//! make a min stack : min stack means their is a getmin function that return the minimum element 
//! among whtever we are pushing in it.
class impliment_stack{
    int top;
    int count;
    int arr[10][2];
    int capacity = 10;
public:
    impliment_stack():top(-1),count(0){};
    void push(int x){
        if(count>=capacity){
            cout<<"\nstack is full.";
            return;
        }
        top++;
        arr[top][0] = x;
        if(top==0) arr[top][1] = x;
        if(top!=0){
            if(arr[top-1][1]<x){
                arr[top][0] = x;
                arr[top][1] = arr[top-1][1];
            }
            else{
                arr[top][0] = x;
                arr[top][1] = x;
            }
        }
        count++; 
    }
    void pop(){
        if(count==0){
            cout<<"\nstack is empty.";
            return;
        }
        top--;
        count--;
    }
    int top_(){
        if(count==0){
            cout<<"\nstack is empty.";
            return -1;
        }
        return arr[top][0];
    }
    int getmin(){
        if(count==0){
            cout<<"\nstack is empty.";
            return -1;
        }
        return arr[top][1];
    }
    int size(){
        return count;
    }
};

//!optimal code without using any extra space only O(n) space
class implimentStack{
public:
    stack<int>st;
    int mini = INT_MAX;
    int push_element(int val){
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if(val>mini) st.push(val);
            else{
                st.push(2*val-mini);
                mini = val;
            }
        }
    }
    void pop_element(){
        if(st.empty()){
            cout<<"\nstack is empty.";
            return;
        }
        int x = st.top();
        st.pop();
        if(x<mini){
            mini =  2*mini-x;
        }
    }
    int top_function(){
        if(st.empty()){
            cout<<"\nstack is empty.";
            return -1;
        }
        int x = st.top();
        if(mini<x) return x;
        return mini;
    }
    int get_min(){
        return mini;
    }
};
int main(){
    // impliment_stack harsh;
    // harsh.push(12);
    // harsh.push(15);
    // harsh.push(10);

    // cout<<"\ntop element of the stack = "<<harsh.top_();
    // cout<<"\nsize of the stack = "<<harsh.size();
    // cout<<"\nminimum element of the stack = "<<harsh.getmin();

    // harsh.pop();
    // harsh.pop();
    // cout<<"\ntop element of the stack = "<<harsh.top_();
    // cout<<"\nsize of the stack = "<<harsh.size();
    // cout<<"\nminimum element of the stack = "<<harsh.getmin();

    
    // harsh.pop();

    // cout<<"\ntop element of the stack = "<<harsh.top_();
    // cout<<"\nsize of the stack = "<<harsh.size();
    // cout<<"\nminimum element of the stack = "<<harsh.getmin();

    implimentStack harsh;
    harsh.push_element(12);
    harsh.push_element(15);
    harsh.push_element(10);

    cout<<"\ntop element of the stack = "<<harsh.top_function();
    cout<<"\nsize of the stack = "<<harsh.st.size();
    cout<<"\nminimum element of the stack = "<<harsh.get_min();

    harsh.pop_element();
    cout<<"\ntop element of the stack = "<<harsh.top_function();
    cout<<"\nsize of the stack = "<<harsh.st.size();
    cout<<"\nminimum element of the stack = "<<harsh.get_min();
    harsh.pop_element();
    
    cout<<"\ntop element of the stack = "<<harsh.top_function();
    cout<<"\nsize of the stack = "<<harsh.st.size();
    cout<<"\nminimum element of the stack = "<<harsh.get_min();

    harsh.pop_element();
    harsh.top_function();
    harsh.get_min();
}