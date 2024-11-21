#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class stack_using_queue{
public:
    queue<int>q;
    void push_function(int data){
        int s = q.size();
        q.push(data);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop_function(){
        if(q.size()==0){
            cout<<"\nstack is empty..";
            return;
        }
        q.pop();
    }
    int top_function(){
        if(q.size()==0){
            cout<<"\nstack is empty..";
            return -1;
        }
        return q.front();
    }
    int size_(){
        q.size();
    }
    bool is_empty(){
        return q.size()==0;
    }

};
int main(){
    stack_using_queue harsh;
    harsh.push_function(1);
    harsh.push_function(2);
    harsh.push_function(3);
    harsh.push_function(4);
    harsh.push_function(5);
    cout<<"\ntop element = "<<harsh.top_function();
    cout<<"\nstack size = "<<harsh.size_();

    harsh.pop_function();
    cout<<"\nafter pop top element = "<<harsh.top_function();
    cout<<"\nafter pop stack size = "<<harsh.size_();

    cout<<"\nEmpty or not = "<<harsh.is_empty();
    harsh.pop_function();
    harsh.pop_function();
    harsh.pop_function();
    cout<<"\nafter pop = "<<harsh.is_empty();

    harsh.pop_function();
    cout<<"\nafter pop = "<<harsh.is_empty();

    harsh.pop_function();
}