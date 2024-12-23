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
node* createBinaryTree(){
    int x;
    cin>>x;
    if(x==-1) return nullptr;
    node* temp = new node(x);
    cout<<"\nenter the left child of "<<temp->data<<" = ";
    temp->left = createBinaryTree();
    cout<<"\nenter the right child of "<<temp->data<<" = ";
    temp->right = createBinaryTree();
    return temp;
}
void print_bt(node* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    print_bt(root->left);
    print_bt(root->right);
}
void printbt_level(node* root){
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
int height_of_bt(node* root){
    if(root==nullptr) return 0;
    return (1+max(height_of_bt(root->left),height_of_bt(root->right)));
}
int helper(node* root,bool &valid){
    if(root==nullptr) return 0;
    if(valid){
        int l = helper(root->left,valid);
        int r = helper(root->right,valid);
        if(abs(l-r)>1) valid = 0;
        return (1+max(l,r));
    }
    return -1;
}
bool check_for_bbt(node* root){
    bool vaild  = 1;
    helper(root,vaild);
    return vaild;
}
vector<int> spiralForm(node* root){
    queue<node*>q;
    q.push(root);
    vector<int>ans;
    int cnt = 0;
    ans.push_back(root->data);
    while(!q.empty()){
        cnt++;
        int t = q.size();
        vector<int>temp;
        while(t--){
            node* t = q.front();
            q.pop();
            if(t->left){
                q.push(t->left);
                temp.push_back(t->left->data);
            }
            if(t->right){
                q.push(t->right);
                temp.push_back(t->right->data);
            }
        }
        if(cnt%2==0){
            for(int i=temp.size()-1;i>=0;i--){
                ans.push_back(temp[i]);
            }
        }
        else{
            for(int i=0;i<temp.size();i++){
                ans.push_back(temp[i]);
            }
        }
    }
    return ans;
}
int main(){
    cout<<"\nenter the root node = ";
    node* root = createBinaryTree();
    printbt_level(root);
    cout<<endl;
    // cout<<"\n height of bt = "<<height_of_bt(root);
    vector<int>ans = spiralForm(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}