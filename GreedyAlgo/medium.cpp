#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<vector<int>>&arr,int n){
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<3;j++){
            int num;
            cout<<"\nenter the element of the array = ";
            cin>>num;
            temp.push_back(num);
        }
        arr.push_back(temp);
    }
}
void print_array(vector<vector<int>>&arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}
bool comp(vector<int>&a,vector<int>&b){
    return a[2]>b[2];
}
pair<int,int> maximum_profit_after_unique_job(vector<vector<int>>&arr,int n){
    sort(arr.begin(),arr.end(),comp);
    int maxProfit = 0;
    int cntJob = 0;
    int max_dedline = -1;
    for(int i=0;i<n;i++){
        if(max_dedline<arr[i][1]) max_dedline = arr[i][1];
    }
    vector<int>track(max_dedline+1,-1);
    for(int i=0;i<n;i++){
        int dedline = arr[i][1];
        for(int j=min(dedline,max_dedline);j>=0;j--){
            if(track[j]==-1){
                maxProfit+=arr[i][2];
                cntJob++;
                track[j] = 1;
                break;
            }
        }
    }
    return {cntJob,maxProfit};
}
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    vector<vector<int>>arr;
    input_array(arr,n);
    cout<<endl;
    print_array(arr,n);
    cout<<endl;
    pair<int,int>ans = maximum_profit_after_unique_job(arr,n);
    cout<<"\n job cnt = "<<ans.first<<"\n maxprofit = "<<ans.second;
}