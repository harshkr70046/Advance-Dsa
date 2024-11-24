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
int main(){
    impliment_stack harsh;
    harsh.push(12);
    harsh.push(15);
    harsh.push(10);

    cout<<"\ntop element of the stack = "<<harsh.top_();
    cout<<"\nsize of the stack = "<<harsh.size();
    cout<<"\nminimum element of the stack = "<<harsh.getmin();

    harsh.pop();
    harsh.pop();
    cout<<"\ntop element of the stack = "<<harsh.top_();
    cout<<"\nsize of the stack = "<<harsh.size();
    cout<<"\nminimum element of the stack = "<<harsh.getmin();

    
    harsh.pop();

    cout<<"\ntop element of the stack = "<<harsh.top_();
    cout<<"\nsize of the stack = "<<harsh.size();
    cout<<"\nminimum element of the stack = "<<harsh.getmin();
}