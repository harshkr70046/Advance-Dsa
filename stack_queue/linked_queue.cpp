#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int data1,node* next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
    }
};

class Impliment_queue{
    node* front;
    node* back;
    int size;

public:
    Impliment_queue():front(nullptr),back(nullptr),size(0){};

    void push(int x){
        node* new_node = new node(x);
        
        if(back==nullptr) {
            back = new_node;
            front = new_node;
        }
        else{
            back->next = new_node;
            back = back->next;
            
        }
        size++;
    }

    void pop(){
        if(front==nullptr){
            cout<<"\nqueue is empty..";
            return;
        }
        node* temp = front;
        front = front->next;
        if(front==nullptr){
            back = nullptr;
        }
        delete temp;
        size--;
    }
    int front_element(){
        if(front==nullptr){
            cout<<"\nqueue is empty..";
            return -1;
        }
        return front->data;
    }
    int back_element(){
        if(back==nullptr){
            cout<<"\nqueue is empty..";
            return -1;
        }
        return back->data;
    }
    int size_(){
        return size;
    }
    bool is_empty(){
        return size==0;
    }

};

int main(){
    Impliment_queue harsh;
    harsh.push(1);
    harsh.push(2);
    harsh.push(3);
    harsh.push(4);
    harsh.push(5);

    cout<<"\nbefore pop front element = "<<harsh.front_element();
    cout<<"\nbefore pop back element = "<<harsh.back_element();
    cout<<"\nsize before pop = "<<harsh.size_();
    harsh.pop();
    cout<<"\nafter pop front element = "<<harsh.front_element();
    cout<<"\nafter pop back element = "<<harsh.back_element();
    cout<<"\nafter pop size = "<<harsh.size_();

    cout<<"\nis empty = "<<harsh.is_empty();

    harsh.pop();
    harsh.pop();
    harsh.pop();
    harsh.pop();

    cout<<"\n after pop all data = "<<harsh.is_empty();
}