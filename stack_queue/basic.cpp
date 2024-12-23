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

class impliment_stack{
    private:
    int top;
    int st[10];
    const int capacity = 10;
public:
    impliment_stack() : top(-1){}

    void push(int x){
        if(top>=capacity-1){
            cout<<"\nstack overflow..";
            return;
        }
        top++;
        st[top] = x;
    }
    int topElement(){
        if(top==-1){
            cout<<"\nstack is empty";
            return -1;
        }
        return st[top];
    }
    void pop(){
        if(top==-1){
            cout<<"\nstack is empty..";
            return;
        }
        top--;
    }
    int size(){
        return top+1;
    }
    bool isEmpty(){
        return top==-1;
    }

};


class Impliment_queue {
    int front;
    int back;
    int q[10];
    const int capacity = 10;
    int count;
public:
    Impliment_queue () : front(0),back(0),count(0){};
    void push(int x){
        if(count==capacity){
            cout<<"\nqueue is full..";
            return;
        }
        q[back] = x;
        back = (back+1)%capacity;
        count++;
    }
    void pop(){
        if(count==0){
            cout<<"\nqueue is empty..";
            return;
        }
        front = (front+1)%capacity;
        count--;
    }

    int front_(){
        if(count==0){
            cout<<"\nqueue is empty..";
            return -1;
        }
        return q[front];
    }
    int back_(){
        if(count==0){
            cout<<"\nqueue is empty..";
            return -1;
        }
        return q[(back-1+capacity)%capacity];
    }
    int size(){
        return count;
    }
    bool empty(){
        return count==0;
    }
};
int main(){
    // int n;
    // cout<<"\nenter the size of the array = ";
    // cin>>n;
    // vector<int>arr;
    // input_array(arr,n);
    // print_array(arr,n);
    // use_stack(arr,n);
    // use_queue(arr,n);
    // impliment_stack harsh;
    // harsh.push(1);
    // harsh.push(2);
    // harsh.push(3);
    // harsh.push(4);
    // cout<<"\ntop element = "<<harsh.topElement();
    // cout<<"\nstack size = "<<harsh.size();

    // harsh.pop();
    // cout<<"\nafter pop top element = "<<harsh.topElement();
    // cout<<"\nafter pop stack size = "<<harsh.size();

    // cout<<"\nEmpty or not = "<<harsh.isEmpty();
    // harsh.pop();
    // harsh.pop();
    // harsh.pop();
    // cout<<"\nafter pop = "<<harsh.isEmpty();

    // harsh.pop();

    Impliment_queue harsh;
    harsh.push(1);
    harsh.push(2);
    harsh.push(3);
    harsh.push(4);
    harsh.push(5);

    cout<<"\nbefore pop front element = "<<harsh.front_();
    cout<<"\nbefore pop back element = "<<harsh.back_();
    cout<<"\nsize before pop = "<<harsh.size();
    harsh.pop();
    cout<<"\nafter pop front element = "<<harsh.front_();
    cout<<"\nafter pop back element = "<<harsh.back_();
    cout<<"\nafter pop size = "<<harsh.size();

    cout<<"\nis empty = "<<harsh.empty();
    
}