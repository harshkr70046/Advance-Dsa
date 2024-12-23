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
    cout<<"\nenter the first root left node of "<<temp->data<<" = ";
    temp->left = create_binary_tree();
    cout<<"\nenter the first root right node of "<<temp->data<<" = ";
    temp->right = create_binary_tree();
    return temp;
}
node* create_binary_tree2(){
    int x;
    cin>>x;
    if(x==-1) return nullptr;
    node* temp = new node(x);
    cout<<"\nenter the second root left node of "<<temp->data<<" = ";
    temp->left = create_binary_tree();
    cout<<"\nenter the second root right node of "<<temp->data<<" = ";
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
//! level order transveral
void level_order(node* root){
    queue<node*>q;
    q.push(root);
    int cnt = 1;
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        cout<<"\nstep:"<<cnt<<temp->data<<" ";
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
        cnt++;
    }
}
//! larget value in each level.
vector<int> largestValInEachLevel(node* root){
    queue<node*>q;
    vector<int>ans;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            node* temp = q.front();
            q.pop();
            maxi = max(maxi,temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        ans.push_back(maxi);
    }
    return ans;
}
//! is both the tree is same or not
bool isIdentical(node* root1,node* root2){
    if(root1==nullptr && root2==nullptr) return true;
    if((root1 && !root2) || (!root1 && root2)) return false;
    if(root1->data!=root2->data) return false;
    return isIdentical(root1->left,root2->left)&&isIdentical(root1->right,root2->right);
}
//! convert tree into mirror form
void convertIntoMirrorImage(node* root){
    if(root==nullptr) return;
    swap(root->left,root->right);
    convertIntoMirrorImage(root->left);
    convertIntoMirrorImage(root->right);
}

int main(){
    cout<<"\nenter the first root node = ";
    node* root1 = create_binary_tree();
    cout<<endl;
    // cout<<"\nenter the second root node = ";
    // node* root2 = create_binary_tree2();
    print_preOrder(root1);
    // int cnt = 0;
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
    // cout<<"\nenter the total non leaf node = "<<count_non_leaf_node(root);
    // level_order(root);
    // vector<int>ans = largestValInEachLevel(root);
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // if(isIdentical(root1,root2)){
    //     cout<<"\nyes it is identical.";
    // }
    // else{
    //     cout<<"\n no it is not identical.";
    // }
    convertIntoMirrorImage(root1);
    print_preOrder(root1);
}