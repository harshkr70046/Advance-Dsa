#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class queue_using_stack{
public:
    stack<int>st1,st2;
    void push_(int data){
        while(st1.size()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(data);
        while(st2.size()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    void pop_(){
        if(st1.size()==0){
            cout<<"\nqueue is empty...";
        }
        st1.pop();
    }
    int front_(){
        if(st1.size()==0){
            cout<<"\nqueue is empty...";
            return -1;
        }
        return st1.top();
    }
    int size_(){
        return st1.size();
    }
    bool is_empty(){
        return st1.size()==0;
    }
    
};

// optimal code
class MyQueue {
  public:
    stack < int > input, output;
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
    cout << "The element pushed is " << x << endl;
    input.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    // shift input to output 
    if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();

    int x = output.top();
    output.pop();
    return x;
  }

  /** Get the front element. */
  int top() {
    // shift input to output 
    if (output.empty())
      while (input.size())
        output.push(input.top()), input.pop();
    return output.top();
  }

  int size() {
    return (output.size() + input.size()); 
  }

};
int main(){
    // queue_using_stack harsh;

    //  harsh.push_(1);
    //  harsh.push_(2);
    //  harsh.push_(3);
    //  harsh.push_(4);
    //  harsh.push_(5);

    // cout<<"\nbefore pop front element = "<<harsh.front_();
    // cout<<"\nsize before pop = "<<harsh.size_();
    // harsh.pop_();
    // cout<<"\nafter pop front element = "<<harsh.front_();
    // cout<<"\nafter pop size = "<<harsh.size_();

    // cout<<"\nis empty = "<<harsh.is_empty();

    // harsh.pop_();
    // harsh.pop_();
    // harsh.pop_();
    // harsh.pop_();

    // cout<<"\n after pop all data = "<<harsh.is_empty();

    MyQueue q;
    q.push(3);
    q.push(4);
    cout << "The element poped is " << q.pop() << endl;
    q.push(5);
    cout << "The top of the queue is " << q.top() << endl;
    cout << "The size of the queue is " << q.size() << endl;

}