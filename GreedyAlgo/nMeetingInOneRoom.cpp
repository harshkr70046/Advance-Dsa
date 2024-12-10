#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<vector<int>>&arr,int n,int m){
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<m;j++){
            int num;
            cout<<"\nenter the element of the array = ";
            cin>>num;
            temp.push_back(num);
        }
        arr.push_back(temp);
    }
}
void print_array(vector<vector<int>>&arr){
    for(auto val:arr){
        for(auto v:val){
            cout<<v<<"->";
        }
        cout<<endl;
    }
}
bool comp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
int totalMeating(vector<vector<int>>&arr){
    int count = 0;
    int lastEnd = -1;
    sort(arr.begin(),arr.end(),comp);
    for(int i=0;i<arr.size();i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(start>=lastEnd){
            count++;
            lastEnd = end;
        }
        
    }
    return count;
}
int main(){
    int n;
    cout<<"\nRow size   = ";
    cin>>n;
    int m;
    cout<<"\nColum size  = ";
    cin>>m;
    vector<vector<int>>arr;
    input_array(arr,n,m);
    print_array(arr);
    cout<<"Total  Meating = "<<totalMeating(arr);
}