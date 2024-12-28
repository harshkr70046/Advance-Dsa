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
node* createBt(){
    int x;
    cin>>x;
    if(x==-1) return nullptr;
    node* root = new node(x);
    cout<<"\nenter the left child of "<<root->data<<" = ";
    root->left = createBt();
    cout<<"\nenter the right child of "<<root->data<<" = ";
    root->right = createBt();
    return root;
}
void preOrder(node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
vector<int> MorriesTraversalInorder(node* root){
    vector<int>ans;
    while(root){
        //! left part doesn't exist
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }
        //! left Part exist
        else{
            node* curr = root->left;
            while(curr->right && curr->right!=root){
                curr = curr->right;
            }
            // left subtree not traversal

            if(curr->right == nullptr){

                curr->right = root;
                root = root->left;
            }
            else{//already traversal
                curr->right = nullptr;
                ans.push_back(root->data);

                root = root->right;
            }
        }
    }
    return ans;
}
vector<int> MorriesTraversalPeorder(node* root){
    vector<int>ans;
    while(root){
        //! left part doesn't exist
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }
        //! left Part exist
        else{
            node* curr = root->left;
            while(curr->right && curr->right!=root){
                curr = curr->right;
            }
            // left subtree not traversal

            if(curr->right == nullptr){
                ans.push_back(root->data);
                curr->right = root;
                root = root->left;
            }
            else{//already traversal
                curr->right = nullptr;
                root = root->right;
            }
        }
    }
    return ans;
}
void flatenIntoLl(node* root){
    while(root){
        //! left part doesn't exist
        if(!root->left){
            root = root->right;
        }
        //! left Part exist
        else{
            node* curr = root->left;
            while(curr->right && curr->right!=root){
                curr = curr->right;
            }
            // left subtree not traversal

            
                curr->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;

        }
    }
}
int main(){
    cout<<"\nenter the root node = ";
    node* root = createBt();
    // preOrder(root);
    vector<int>ans = MorriesTraversalInorder(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}