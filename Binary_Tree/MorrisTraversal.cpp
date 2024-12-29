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
int Burn(node* root,int &time,int target){
    if(!root) return 0;
    if(root->data==target) return -1;

    int left = Burn(root->left,time,target);
    int right = Burn(root->right,time,target);

    if(left<0){
        time = max(time,abs(left)+right);
        return left-1;
    }
    if(right<0){
        time = max(time,left+abs(right));
        return right-1;
    }
    return 1+max(left,right);
}
void find(node* root,int target,node*& BurnNode){
    if(!root) return;
    if(root->data==target){
        BurnNode = root;
        return;
    }
    find(root->left,target,BurnNode);
    find(root->right,target,BurnNode);
}
int Height(node* root){
    if(!root) return 0;

    return 1+max(Height(root->left),Height(root->right));
}
int minTime(node* root,int target){
    int time = 0;
    Burn(root,time,target);
    //! hight of target
    node* BurnNode = nullptr;
    find(root,target,BurnNode);
    int high = Height(BurnNode)-1;
    return max(time,high);
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