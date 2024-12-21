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
//* find the total sum of bt data
//! first method
int total_sum(node* root){
    if(root==nullptr) return 0;
    return (root->data+total_sum(root->left)+total_sum(root->right));
}
//! second method
void total_sum_of_bt(node* root,int &sum){
    if(root==nullptr) return;
    sum+=root->data;
    total_sum_of_bt(root->left,sum);
    total_sum_of_bt(root->right,sum);
}
//!find the count of leaf node
void count_leaf_node(node*root,int &cnt){
    if(root==nullptr) return;

    if(root->left==nullptr && root->right==nullptr){
        cnt++;
        return;
    }

    count_leaf_node(root->left,cnt);
    count_leaf_node(root->right,cnt);
}
//! second method to find the leaf node
int countLeafNode(node* root){
    if(root==nullptr) return 0;
    if(root->left==nullptr && root->right==nullptr) return 1;
    return(countLeafNode(root->left)+countLeafNode(root->right));
}
//! count non leaf node
int count_non_leaf_node(node* root){
    if(!root) return 0;
    if(!root->left && !root->right) return 0;
    return (1+count_non_leaf_node(root->left)+count_non_leaf_node(root->right));
}
//! hight of binary tree
int height_of_bt(node*root){
    if(root==nullptr) return 0;
    return(1+max(height_of_bt(root->left),height_of_bt(root->right)));
}
int main(){
    cout<<"\nenter the root node = ";
    node* root = create_binary_tree();
    cout<<endl;
    // print_preOrder(root);
    int cnt = 0;
    // find_length_of_tree(root,cnt);
    // cout<<"\nlength of tree = "<<cnt;
    // cout<<"\n length using second method = "<<find_length_of_bt(root);

    // cout<<"\n total sum of the bt = "<<total_sum(root);
    // int sum = 0;
    // total_sum_of_bt(root,sum);
    // cout<<"\nsecond method of sum = "<<sum;
    // count_leaf_node(root,cnt);
    // cout<<"\nNumber of leaf node = "<<cnt;
    // cout<<"\ntotal leaf node = "<<countLeafNode(root);
    cout<<"\nenter the total non leaf node = "<<count_non_leaf_node(root);
}