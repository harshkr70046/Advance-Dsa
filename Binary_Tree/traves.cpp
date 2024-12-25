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
node* createBT(){
    int x;
    cin>>x;
    if(x==-1) return nullptr;
    node* temp = new node(x);
    cout<<"\nenter the left child "<<temp->data<<" = ";
    temp->left = createBT();
    cout<<"\nenter the right child "<<temp->data<<" = ";
    temp->right = createBT();
    return temp;
}
void preorder(node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void preordered_itterative(node* root){
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        int t = st.size();
        while(t--){
            node* temp = st.top();
            st.pop();
            cout<<temp->data<<" ";
            if(temp->right){
                st.push(temp->right);
            }
            if(temp->left){
                st.push(temp->left);
            }
        }
    }
}

void postorder(node* root){
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
vector<int> postordered_itterative(node* root){
    stack<node*>st;
    st.push(root);
    vector<int>v;
    while(!st.empty()){
        int t = st.size();
        while(t--){
            node* temp = st.top();
            st.pop();
            v.push_back(temp->data);
            if(temp->left){
                st.push(temp->left);
            }
            if(temp->right){
                st.push(temp->right);
            }
        }
    }
    reverse(v.begin(),v.end());
    return v;
}
void inordered(node* root){
    if(root==nullptr) return;
    inordered(root->left);
    cout<<root->data<<" ";
    inordered(root->right);
}
vector<int> inorder_itterator(node* root){
    stack<node*>st;
    stack<bool>visited;
    vector<int>ans;
    st.push(root);
    visited.push(0);
    while(!st.empty()){
        node* temp = st.top();
        bool flag = visited.top();
        st.pop();
        visited.pop();

        if(flag==0){
            if(temp->right){
                st.push(temp->right);
                visited.push(0);
            }
            st.push(temp);
            visited.push(1);
            if(temp->left){
                st.push(temp->left);
                visited.push(0);
            }
        }
        else{
            ans.push_back(temp->data);
        }
    }
    return ans;
}
int main(){
    cout<<"\nenter the root node = ";
    node* root = createBT();
    inordered(root);
    cout<<endl;
    vector<int> ans = inorder_itterator(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}