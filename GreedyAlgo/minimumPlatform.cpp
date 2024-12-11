#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int num;
        cout<<"\n element = ";
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
int minPlatformReq(vector<int>&arr,vector<int>&arr2){
    int n = arr.size();
    int i = 0;
    int j = 0;
    int cnt = 0;
    int maxCnt = 0;
    while(i<n){
        if(arr[i]<=arr2[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt,cnt);
    }
    return maxCnt;
}
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    vector<int>arr;
    vector<int>arr1;
    input_array(arr,n);
    input_array(arr1,n);
    print_array(arr,n);
    print_array(arr1,n);
    cout<<"minimum platform = "<<minPlatformReq(arr,arr1);
}