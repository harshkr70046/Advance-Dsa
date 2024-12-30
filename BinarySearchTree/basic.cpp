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
void create_Bt(){
    int x;
    cout<<"\nenetr the root node = ";
    cin>>x;
    queue<node*>q;
    node* root = new node(x);
    q.push(root);
    while(!q.empty()){
        int first;
        cout<<"\nenter the ";
    }

}
int main(){

}