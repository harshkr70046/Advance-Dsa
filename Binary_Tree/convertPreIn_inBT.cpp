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
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data1){
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};
int find(vector<int>&in,int target,int start,int end){
    for(int i=start;i<=end;i++){
        if(in[i]==target) return i;
    }
    return -1;
}
node* Tree(vector<int>&in,vector<int>&pre,int start,int end,int ind){
    if(start>end) return nullptr;

    node* root = new node(pre[ind]);
    int pos = find(in,pre[ind],start,end);

    root ->left = Tree(in,pre,start,pos-1,ind+1);
    root -> right = Tree(in,pre,pos+1,end,ind+(pos-start)+1);
    return root;   
}
node* create_bt(vector<int>&in,vector<int>&pre,int n){
    return Tree(in,pre,0,n-1,0);
}
node* Tree(vector<int>&in,vector<int>&post,int start,int end,int ind){
    if(start>end) return nullptr;

    node* root = new node(post[ind]);
    int pos = find(in,post[ind],start,end);

    root -> right = Tree(in,post,pos+1,end,ind-1);
    root ->left = Tree(in,post,start,pos-1,ind-(end-pos)-1);
    return root;   
}
node* create_bt_post(vector<int>&in,vector<int>&post,int n){
    return Tree(in,post,0,n-1,n-1);
}
void print_inorder(node* root){
    if(root==nullptr) return;

    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}
void print_pre(node* root){
    if(root==nullptr) return;

    cout<<root->data<<" ";
    print_pre(root->left);
    print_pre(root->right);
}
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    vector<int>arr;
    vector<int>arr1;

    cout<<"\nenter the element of inorder.";
    input_array(arr,n);
    cout<<"\nenter the elemnt for preorder.";
    input_array(arr1,n);
    cout<<endl;
    cout<<"\ninorder data:";
    print_array(arr,n);
    cout<<"\npreorder data:";
    print_array(arr1,n);

    node* root = create_bt(arr,arr1,n);
    cout<<endl;
    cout<<"\n preOrder of Bt";
    print_pre(root);

    cout<<endl;
    cout<<"\ninorder of bt";
    print_inorder(root);

}