#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_arrray(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int num;
        cout<<"\nenter the element of the array = ";
        cin>>num;
        arr.push_back(num);
    }
}
void print_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
}
//! write a code for assign cookies
//* in this question we have given two array greedy this is parent and 
//* every parient has its own cookies with a array we have to written the
//* maximum number of student
int assignCookies(vector<int>&greedy,vector<int>&s){
    int n = greedy.size();
    int m = s.size();
    sort(greedy.begin(),greedy.end());
    sort(s.begin(),s.end());
    int i = 0;
    int j = 0;
    while(i<m){
        if(s[i]>=greedy[j]){
            j++;
        }
        i++;
    }
    return j;
}
int main(){
    int n;
    cout<<"\nenter the size of the array  = ";
    cin>>n;
    int m;
    cout<<"\nenter the size of the second array = ";
    cin>>m;
    vector<int>arr;
    vector<int>arr1;
    input_arrray(arr,n);
    input_arrray(arr1,m);
    print_array(arr,n);
    print_array(arr1,m);
    cout<<"\nmaximum student = "<<assignCookies(arr,arr1);
}