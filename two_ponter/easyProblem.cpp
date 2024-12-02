#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<char>&arr,int n){
    for(int i=0;i<n;i++){
        char num;
        cout<<"\nenter the element of the array = ";
        cin>>num;
        arr.push_back(num);
    }
}
void print_array(vector<char>&arr,int n){
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
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    // vector<int>arr;
    vector<char>arr;
    input_array(arr,n);
    print_array(arr,n);
    cout<<"\nMaxlen = "<<maxi_unique_len(arr,n);
    // cout<<"\nMaximum point can obtain from k card = "<<maxiPointObtainCard(arr,n,4);
}