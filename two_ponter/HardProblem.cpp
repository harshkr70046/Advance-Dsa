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
//! count the total  number of subarray with k odd number
int count_odd_subarray(vector<int>&arr,int n,int k){
    int i = 0;
    int j = 0;
    int cnt = 0;
    int total = 0;
    while(j<n){
        if(arr[j]%2==1){
            cnt++;
        }
        while(cnt>k){
            if(arr[i]%2==1){
                cnt--;
            }
            i++;
        }
        if(cnt<=k){
            total = total+(j-i+1);
        }
        j++;
    }
    return total;
}
int total_subarray_of_k_odd_number(vector<int>&arr,int n,int k){
    int cnt1 = count_odd_subarray(arr,n,k-1);
    int cnt2 = count_odd_subarray(arr,n,k);
    return cnt2-cnt1;
}
//! count the total subarray of k distint integer.
int count_k_distint_integer_subarray(vector<int>&arr,int n,int k){
    int i = 0;
    int j = 0;
    unordered_map<int,int>mp;
    int cnt = 0;
    while(j<n){
        mp[arr[j]]++;
        while(mp.size()>k){
            mp[arr[i]]--;
            if(mp[arr[i]]==0) mp.erase(arr[i]);
            i++;
        }
        if(mp.size()<=k){
            cnt=cnt+j-i+1;
        }
        j++;
    }
    return cnt;
}
int total_subarray_with_k_unique_number(vector<int>&arr,int n,int k){
    int cnt1 = count_k_distint_integer_subarray(arr,n,k-1);
    int cnt2 = count_k_distint_integer_subarray(arr,n,k);
    return cnt2-cnt1;
}
//! menimum length substring which is equal to target.
int min_length_substring(string s ,string target){
    int arr[256] = {0};
    int l = 0;
    int r = 0;
    int minLen = INT_MAX;
    int startInd = -1;
    for(int i=0;i<target.size();i++){
        arr[target[i]]++;
    }
    int cnt = 0;
    while(r<s.size()){
        if(s[arr[r]]>0){
            cnt++;
            s[arr[r]]--;
        }
        if(cnt==target.size()){
            if(r-l+1<minLen){
                minLen = r-l+1;
                startInd = l;
            }
            else{
                s[arr[l]]--;
                if(s[arr[l]]>0) cnt++;
            }
        }
        r++;
    }
    return (minLen==INT_MAX)?-1:minLen;
}

int main(){
    // int n;
    // cout<<"\nenter the size of the array = ";
    // cin>>n;
    // vector<int>arr;
    // input_array(arr,n);
    // print_array(arr,n);
    // cout<<"\n total count of subarray whose sum == goal => "<<subarray_count(arr,n,2);
    // cout<<"\n total subarray of k odd number = "<<total_subarray_of_k_odd_number(arr,n,3);
    // cout<<"\n total subarray with k distint integer = "<<total_subarray_with_k_unique_number(arr,n,3);
    string s = "ddaaabbca";
    string t = "abc";
    cout<<"\n Minimum len of string = "<<min_length_substring(s,t);
}