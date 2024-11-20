#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* next;

    node(int data1,node*next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
    }

};
class Impliment_stack{
    node* top;
    int size;
public:
    Impliment_stack():top(nullptr),size(0){};
    void push(int x){
        node* temp = new node(x,top);
        top = temp;
        size++;
    }

    void pop(){
        if(size==0) {
            cout<<"\nstack is empty..";
            return;
        }
        node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int top_(){
        if(size==0){
            cout<<"\nstack is empty..";
            return -1;
        }
        return top->data;
    }
    int size_(){
        return size;
    }
    bool is_empty(){
        return size==0;
    }
};
int main(){
    Impliment_stack harsh;
    harsh.push(1);
    harsh.push(2);
    harsh.push(3);
    harsh.push(4);
    harsh.push(5);
    cout<<"\ntop element = "<<harsh.top_();
    cout<<"\nstack size = "<<harsh.size_();

    harsh.pop();
    cout<<"\nafter pop top element = "<<harsh.top_();
    cout<<"\nafter pop stack size = "<<harsh.size_();

    cout<<"\nEmpty or not = "<<harsh.is_empty();
    harsh.pop();
    harsh.pop();
    harsh.pop();
    cout<<"\nafter pop = "<<harsh.is_empty();

    harsh.pop();
    cout<<"\nafter pop = "<<harsh.is_empty();

}