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
//* function to build binary tree using queue data structure
void binaray_tree_in_queue(){
    int x;
    cout<<"\nenter the root node of the binary tree = ";
    cin>>x;
    queue<Node*>q;
    Node* root = new Node(x);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        int first;
        cout<<"\nenter the left child of "<<temp->data<<" => ";
        cin>>first;
        if(first!=-1){
            temp->left = new Node(first);
            q.push(temp->left);
        }
        int second;
        cout<<"\nenter the right child of "<<temp->data<<" => ";
        cin>>second;
        if(second!=-1){
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
    
}

//* create a binary tree using recursion
Node* binary_treeUsing_Rec(){
    int x;
    cin>>x;
    if(x==-1){
        return nullptr;
    }
    Node* temp = new Node(x);
    //left node
    cout<<"\nenter the left child of "<<temp->data<<" => ";
    temp->left = binary_treeUsing_Rec();
    //right
    cout<<"\nenter the right child of "<<temp->data<<" => ";
    temp->right = binary_treeUsing_Rec();

    return temp;
}
int main(){
    cout<<"\nenter the root node => ";
    Node* root = binary_treeUsing_Rec();
    //binaray_tree_in_queue();
}