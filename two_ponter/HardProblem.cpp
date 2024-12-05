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
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
}
//! count the total subarray whose sum is lesser then equal to sum
int sum_count_subarray(vector<int>&arr,int n,int sum){
    if(sum<0) return 0;
    int i =0 ;
    int j = 0;
    int s = 0;
    int cnt = 0;
    while(j<n){
        s+=arr[j];
        while(s>sum){
            s-=arr[i];
            i++;
        }
        if(s<=sum){
            cnt+=j-i+1;
        }
        j++;
    }
    return cnt;
}
//! find the subarray whose sum is == goal;
int subarray_count(vector<int>&arr,int n,int s){
    int s1 = sum_count_subarray(arr,n,s-1);
    int s2 =sum_count_subarray(arr,n,s);
    return s2-s1;

}

int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    vector<int>arr;
    input_array(arr,n);
    print_array(arr,n);
    cout<<"\n total count of subarray whose sum == goal => "<<subarray_count(arr,n,2);
}