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
node* create_Bt(){
    int x;
    cout<<"\nenetr the root node = ";
    cin>>x;
    queue<node*>q;
    node* root = new node(x);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        int first;
        cout<<"\nenter the left child of "<<temp->data<< " = ";
        cin>>first;
        if(first!=-1){
            node* newNode = new node(first);
            q.push(newNode);
            temp->left = newNode;
        }
        int second;
        cout<<"\nenter the right child of "<<temp->data<<" = ";
        cin>>second;
        if(second!=-1){
            node* newNode = new node(second);
            q.push(newNode);
            temp->right = newNode;
        }
    }
    return root;
}
void print_level(node* root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
void input_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int num;
        cout<<"\nenter the element of the array = ";
        cin>>num;
        arr.push_back(num);
    }
}
node* insert(node* root,int target){
    if(!root) {
        node* temp = new node(target);
        return temp;
    }
    if(target<root->data){
        root->left = insert(root->left,target);
    }
    else{
        root->right = insert(root->right,target);
    }
    return root;
}
node* createBinarySearchTree(vector<int>&arr,int n){
    node* root = nullptr;
    for(int i=0;i<n;i++){
        root = insert(root,arr[i]);
    }
    return root;
}
void inorder(node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
bool BST(node* root,int target){
    if(root==nullptr) return false;
    if(root->data==target) return true;
    if(target<root->data){
        return BST(root->left,target);
    }
    else{
        return BST(root->right,target);
    }
   
}
node* delete_node(node* root,int target){
    if(!root) return nullptr;
    if(root->data>target){
        root->left = delete_node(root->left,target);
        return root;
    }
    else if(root->data<target){
        root->right = delete_node(root->right,target);
        return root;
    }
    else{
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            return nullptr;
        }
        else if(root->right==nullptr){
            node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left==nullptr){
            node* temp = root->right;
            delete root;
            return temp;
        }
        else{
            // find the greatest element from left
            node* child = root->left;
            node* parent = root;
            while(child->right){
                parent = child;
                child = child->right;
            }
            if(root!=parent){
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else{
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
    
}
int main(){
    node* root = create_Bt();
    print_level(root);
    cout<<endl;
    // int n;
    // cout<<"\nenter the size of the array  = ";
    // cin>>n;
    // vector<int>arr;
    // input_array(arr,n);
    // node* root = createBinarySearchTree(arr,n);
    // inorder(root);
    // if(BST(root,14)){
    //     cout<<"\nYes it is present";
    // }
    // else cout<<"\nNo it is not present.";
    node* uroot = delete_node(root,5);
    print_level(uroot);

    
}