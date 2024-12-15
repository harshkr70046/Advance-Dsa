#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int data1){
        data = data1;
        left = nullptr;
        right = nullptr; 
    }
};
int main(){
    int x;
    cout<<"Enter the root elemnt = ";
    cin>>x;
    int first,second;
    queue<Node*>q;
    Node*root = new Node(x);
    q.push(root);

    //!building Binary Tree
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"\nEnter the left value of "<<temp->data<<" => ";
        cin>>first;
        //left node
        if(first!=-1){
            temp->left = new Node(first);
            q.push(temp->left);
        }
        //right node
        cout<<"\nEnter the right value of "<<temp->data<<" => ";
        cin>>second;
        //left node
        if(second!=-1){
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
}