#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int num;
        cout<<"\nenter the element of the array = ";
        cin>>num;
        arr.push_back(num);
    }
}
void print_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
int maxiPointObtainCard(vector<int>&arr,int n,int k){
    int l = 0;
    int r = n-1;
    int maxi = 0;
    int currPoint = 0;
    while(l<k){
        currPoint+=arr[l];
        l++;
    }
    maxi = max(maxi,currPoint);
    l--;
    int cnt = 0;
    while(cnt<k){
        currPoint-=arr[l];
        currPoint+=arr[r];
        maxi = max(maxi,currPoint);
        l--;
        r--;
        cnt++;
    }
    return maxi;
}

//! maximum length of unique char subarray.
int maxi_unique_len(vector<char>&arr,int n){
    int l = 0;
    int r = 0;
    int maxi = 0;
    vector<int>v(256,-1);
    while(r<n){
        if(v[arr[r]]!=-1){
            if(v[arr[r]]>=l){
                l = v[arr[r]]+1;
            }
        }
        int len = r-l+1;
        maxi = max(maxi,len);
        v[arr[r]] = r;
        r++;
    }
    return maxi;
}
//! maximum consecutive one after fliping k zero
int maximum_consecutiveOne(vector<int>&arr,int n,int k){
    int l = 0;
    int r = 0;
    int cnt = 0;
    int maxi = 0;
    while(r<n){
        if(arr[r]==0) cnt++;
        while(cnt>k){
            if(arr[l]==0) cnt--;
            l++;
        }
        
        maxi = max(maxi,r-l+1);
        r++;
    }
    return maxi;
}
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    vector<int>arr;
    // vector<char>arr;
    // input_array(arr,n);
    // print_array(arr,n);
    // cout<<"\nMaxlen = "<<maxi_unique_len(arr,n);
    // cout<<"\nMaximum point can obtain from k card = "<<maxiPointObtainCard(arr,n,4);
    input_array(arr,n);
    print_array(arr,n);
    cout<<"\nMaximum length of consecutive one = "<<maximum_consecutiveOne(arr,n,2);
}