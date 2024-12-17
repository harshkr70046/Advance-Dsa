#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data1){
        data = data1;
        node* left = nullptr;
        node* right = nullptr;
    }
};
node* create_binary_tree(){
    int x;
    cin>>x;
    if(x==-1) return nullptr;
    node* temp = new node(x);
    cout<<"\nenter the left node of "<<temp->data<<" = ";
    temp->left = create_binary_tree();
    cout<<"\nenter the right node of "<<temp->data<<" = ";
    temp->right = create_binary_tree();
    return temp;
}
void print_preOrder(node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    print_preOrder(root->left);
    print_preOrder(root->right);
}
//! first method
void find_length_of_tree(node* root, int &cnt){
    if(root==nullptr) return;
    cnt++;
    find_length_of_tree(root->left,cnt);
    find_length_of_tree(root->right,cnt);
    
}
//! second method
int find_length_of_bt(node* root){
    if(root==nullptr) return 0;
    return (1+find_length_of_bt(root->left)+find_length_of_bt(root->right));
}

int main(){
    cout<<"\nenter the root node = ";
    node* root = create_binary_tree();
    cout<<endl;
    print_preOrder(root);
    int cnt = 0;
    find_length_of_tree(root,cnt);
    cout<<"\nlength of tree = "<<cnt;
    cout<<"\n length using second method = "<<find_length_of_bt(root);
}