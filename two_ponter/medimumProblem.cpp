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
void print_array(vector<int>&arr,int n)
{
    for(int j=0;j<n;j++){
        cout<<arr[j]<<"     ";
    }
    cout<<endl;
}
//! we have two basket each backet conatin unique frute return the maximum length of the sub-arrray
//! brute
int max_len_of_subarry_with_2type_fruite(vector<int>&arr,int n,int k){
    int maxi = 0;
    
    for(int i=0;i<n;i++){
        unordered_set<int>st;
        for(int j=i;j<n;j++){
            st.insert(arr[j]);
            if(st.size()<=2){
                maxi = max(maxi,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxi;
}
//!Optimal
int maximumFruteInTwoBasket(vector<int>&arr,int n,int k){
    int j = 0,i=0,maxi = 0;
    unordered_map<int, int> fruitCount;

    while (j < n) {
        // Add the current fruit to the map
        fruitCount[arr[j]]++;

        // If we have more than 2 types of fruits, shrink the window
        while (fruitCount.size() > 2) {
            fruitCount[arr[i]]--;
            if (fruitCount[arr[i]] == 0) {
                fruitCount.erase(arr[i]); // Remove the fruit type from the map
            }
            i++; // Move the left pointer
        }

        // Update the maximum length of the window
        maxi = max(maxi, j - i + 1);
        j++; // Move the right pointer
    }

    return maxi;
}
//! more optimal
int max_len_of_fruite(vector<int>&arr,int n,int k){
    int i = 0;
    int j = 0;
    int maxi = 0;
    unordered_map<int,int>mp;
    while(j<n){
        mp[arr[j]]++;
        if(mp.size()>2){
            mp[arr[i]]--;
            if(mp[arr[i]]==0){
                mp.erase(arr[i]);
            }
            i++;
        }
        if(mp.size()<=2){
            maxi = max(maxi,j-i+1);
        }
        j++;
    }
    return maxi;
}
//! we have a string find out the longest subarray with k distint character
//! brute
int maxi_len_of_k_distinct_char(string s,int k){
    int maxi = 0;
    for(int i=0;i<s.size();i++){
        unordered_set<int>st;
        for(int j=i;j<s.size();j++){
            st.insert(s[j]);
            if(st.size()<=2){
                maxi = max(maxi,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxi;
}
//! better approch
int maxLenofKdistinctCHar(string s,int k){
    int i=0;
    int j = 0;
    int maxi = 0;
    unordered_map<int,int>mp;
    while(j<s.size()){
        mp[s[j]]++;
        while(mp.size()>2){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }
        if(mp.size()<=2){
            maxi = max(maxi,j-i+1);
        }
        j++;
    }
    return maxi;
}
//! opimal code
int max_Len_ofKdistinctChar(string s,int k){
    int i=0;
    int j = 0;
    int maxi = 0;
    unordered_map<int,int>mp;
    while(j<s.size()){
        mp[s[j]]++;
        if(mp.size()>2){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }
        if(mp.size()<=2){
            maxi = max(maxi,j-i+1);
        }
        j++;
    }
    return maxi;
}
int main(){
    // int n;
    // cout<<"\nenter the size of the array = ";
    // cin>>n;
    // vector<int>arr;
    // input_array(arr,n);
    // print_array(arr,n);
    //cout<<"\nMaximum frute of 2 type is = "<<max_len_of_fruite(arr,n,2);
    string s = "aaabbccd";
    cout<<"\n maximum len of k chr = "<<max_Len_ofKdistinctChar(s,2);
}