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

node* create_bt(){
    int x;
    cout<<"\nenter the root node = ";
    cin>>x;
    queue<node*>q;
   
    node* root = new node(x);
    q.push(root);

    int first;
    int second;
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"\nenter the left child of "<<temp->data<<" = ";
        cin>>first;
        if(first!=-1){
            temp->left = new node(first);
            q.push(temp->left);
        }
        cout<<"\nenter the right child of "<<temp->data<<" = ";
        cin>>second;
        if(second!=-1){
            temp->right = new node(second);
            q.push(temp->right);
        }
    }
    return root;
}
void print_bt(node* root){
    if(root==nullptr){
        cout<<"\nNull";
        return;
    }
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
void find(node* root,int pos,int &l,int &r){
    if(root==nullptr) return;

    l = min(l,pos);
    r = max(r,pos);

    find(root->left,pos-1,l,r);
    find(root->right,pos+1,l,r);
}
vector<int> verticalTraversal(node* root){
    if(root==nullptr) return {};
    int l = 0, r = 0;
    find(root,0,l,r);

    vector<vector<int>>negative(abs(l)+1);
    vector<vector<int>>positive(r+1);

    queue<node*>q;
    q.push(root);

    queue<int>ind;
    ind.push(0);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        int pos = ind.front();
        ind.pop();
        if(pos>=0){
            positive[pos].push_back(temp->data);
        }
        else negative[abs(pos)].push_back(temp->data);

        if(temp->left) {
            q.push(temp->left);
            ind.push(pos-1);
        }
        if(temp->right){
            q.push(temp->right);
            ind.push(pos+1);
        }
    }
    vector<int>ans;
    for(int i=negative.size()-1;i>=0;i--){
        for(int j=0;j<negative[i].size();j++){
            ans.push_back(negative[i][j]);
        }
    }
    for(int i=0;i<positive.size();i++){
        for(int j=0;j<positive[i].size();j++){
            ans.push_back(positive[i][j]);
        }
    }
    return ans;
}
int main(){
    node* root = create_bt();
    cout<<endl;
    print_bt(root);
    vector<int>ans = verticalTraversal(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}