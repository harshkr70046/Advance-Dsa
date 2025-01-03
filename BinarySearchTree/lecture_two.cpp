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
        left = nullptr;
        right = nullptr;
    }
};
node* createBST(){
    int x;
    cin>>x;
    if(x==-1) return nullptr;
    node * temp = new node(x);
    cout<<"\nenter the left child of the "<<temp->data<<" = ";
    temp->left = createBST();
    cout<<"\nenter the right child of the "<<temp->data<<" = ";
    temp->right = createBST();
    return temp;
}
void inorder_(node* root){
    if(root==nullptr) return;
    inorder_(root->left);
    cout<<root->data<<" ";
    inorder_(root->right);
}
void solve(vector<int>&arr,node* root){
    if(root ==nullptr) return;
    solve(arr,root->left);
    arr.push_back(root->data);
    solve(arr,root->right);
}
bool checkBST(node* root){
    vector<int>arr;
    solve(arr,root);
    for(int i=1;i<arr.size();i++){
        if(arr[i-1]>=arr[i]) return false;
    }
    return true;
}
//! optimal code
bool s(node* root,int &prev){
    if(root==nullptr) return true;
    bool l = s(root->left,prev);
    if(l==0) return false;
    if(root->data<=prev) return false;
    prev = root->data;
    return s(root->right,prev);
}
bool checkbst(node* root){
    int prev = INT_MIN;
    return s(root,prev);
}
//! find the minimum distance between two node;
void helper(node* root,int &prev,int &ans){
    if(root==nullptr) return;
    helper(root->left,prev,ans);
    if(prev!=INT_MIN)
    ans = min(ans,root->data-prev);
    prev = root->data;
    helper(root->right,prev,ans);
}
int minimumDIs(node* root){
    int ans = INT_MAX;
    int prev = INT_MIN;
    helper(root,prev,ans);
    return ans;
}
//! find the sum of first k element;
void SUm(node* root,int &ans,int &k){
    if(root==nullptr) return;
    SUm(root->left,ans,k);
    k--;
    if(k>=0){
        ans+=root->data;
    }
    if(k<=0){
        return;
    }
    SUm(root->right,ans,k);
}
int sumK(node* root,int k){
    int ans = 0;
    SUm(root,ans,k);
    return ans;
}
//! find the k larget  element;
void larget(node* root,int &ans,int &k){
    if(root==nullptr) return;
    larget(root->right,ans,k);
    k--;
    if(k>=0){
        ans = min(ans,root->data);
    }
    if(k<=0){
        return;
    }
    larget(root->left,ans,k);
}
int largetK(node* root,int k){
    int ans = INT_MAX;
    larget(root,ans,k);
    return ans;
}
void ArraytoBst(vector<int>&arr,int start,int end,vector<int>&ans){
    if(start>end) return;
    int mid = (start+end)/2;
    ans.push_back(arr[mid]);
    ArraytoBst(arr,start,mid-1,ans);
    ArraytoBst(arr,mid+1,end,ans);
}
vector<int> sortedArayToBst(vector<int>&arr){
    vector<int>ans;
    ArraytoBst(arr,0,arr.size()-1,ans);
    return ans;
}
int main(){
    cout<<"\nenetr the root node = ";
    node* root = createBST();
    inorder_(root);
    // if(checkbst(root)){
    //     cout<<"\nyes";
    // }
    // else{
    //     cout<<"\nNo";
    // }
    // cout<<"\nmin dis = "<<minimumDIs(root);
    cout<<"\nSum k elemnt = "<<largetK(root,3);
}