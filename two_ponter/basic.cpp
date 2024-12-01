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
//! for constant window implimanting sliding window technique
//! find is their sub array presenent in the array of k size or not
bool find_subarray(vector<int>&arr,int n,int k,int s){
    int i = 0;
    int j = k;
    int sum = 0;
    for(i=0;i<j;i++){
        sum+=arr[i];
    }
    if(sum==s) return true;
    i = 0;
    while(j<n){
        sum-=arr[i];
        sum+=arr[j];
        if(sum==s) return true;
        i++;
        j++;
    }
    return false;
}
//! find the maximum subarray sum of length k
int max_sum_subarray(vector<int>&arr,int n,int k){
    int i = 0;
    int j = k;
    int Msum = 0;
    int k_sum = 0;
    for(i=0;i<j;i++){
        k_sum+=arr[i];
    }
    Msum = max(Msum,k_sum);
    i = 0;
    while(j<n){
        k_sum-=arr[i];
        k_sum+=arr[j];
        Msum = max(Msum,k_sum);
        i++;
        j++;
    }
    return Msum;
}
//! return the total subarray in the vector whose sum is equal to s
vector<vector<int>> total_subarray(vector<int>&arr,int n,int k,int s){
    int l = 0, r = 0, curr_sum = 0;
    vector<vector<int>> ans;

    // Create the first window and check its sum
    for (r = 0; r < k; r++) {
        curr_sum += arr[r];
    }
    if (curr_sum == s) {
        ans.push_back(vector<int>(arr.begin(), arr.begin() + k));
    }

    // Slide the window across the array
    while (r < n) {
        curr_sum -= arr[l]; // Remove the leftmost element of the window
        curr_sum += arr[r]; // Add the rightmost element of the window
        l++;                // Move the window
        r++;

        if (curr_sum == s) {
            ans.push_back(vector<int>(arr.begin() + l, arr.begin() + r));
        }
    }

    return ans;
}
//! pattern second
//! return the longest subarray whose sum is lesser then k
int max__length_of_subarray(vector<int>&arr,int n,int s){
    int sum = 0;
    int l = 0;
    int r = 0;
    int maxi = 0;
    while(r<n){
        sum+=arr[r];
        while(sum>s){
            sum-=arr[l];
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
    input_array(arr,n);
    print_array(arr,n);
    // cout<<endl;
    // if(find_subarray(arr,n,4,7)){
    //     cout<<"yes it is present.";
    // }
    // else{
    //     cout<<"\nNop!,it is not present.";
    // }
    // cout<<"\n Maximum sum subarray of length 4 = "<<max_sum_subarray(arr,n,4);
    // vector<vector<int>>ans = total_subarray(arr,n,3,5);
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[0].size();j++){
    //         cout<<ans[i][j]<<"  ";
    //     }
    //     cout<<endl;
    // }
    cout<<"\nMaximum length subarray whose sum is less then equal to s = "<<max__length_of_subarray(arr,n,14);
}