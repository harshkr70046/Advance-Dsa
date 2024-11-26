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
//! prefix max.
vector<int> prefix_max(vector<int>&arr,int n){
    vector<int>v(n);
    int maxi = arr[0];
    v[0] = maxi;
    for(int i=1;i<n;i++){
        maxi = max(maxi,arr[i]);
        v[i] = maxi;
    } 
    return v;
}
//! suffix max.
vector<int> suffix_max(vector<int>&arr,int n){
    vector<int>v(n);
    int maxi = arr[n-1];
    v[n-1] = maxi;
    for(int i=n-2;i>=0;i--){
        maxi = max(maxi,arr[i]);
        v[i] = maxi;
    } 
    return v;
}
//! tapping rain water
int tapping_total_water(vector<int>&arr,int n){
    vector<int>leftmax = prefix_max(arr,n);
    vector<int>rightmax = suffix_max(arr,n);

    int total = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<leftmax[i] && arr[i]<rightmax[i]){
            total+=min(leftmax[i],rightmax[i])-arr[i];
        }
    }
    return total;
}
//! better approch
int tappingTotalWater(vector<int>&arr,int n){
    
    vector<int>rightmax = suffix_max(arr,n);
    int leftmax = 0;
    int total = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<leftmax && arr[i]<rightmax[i]){
            total+=min(leftmax,rightmax[i])-arr[i];
        }
        leftmax = max(arr[i],leftmax);
    }
    return total;
}

//! optimal code for tapping rain water
int total_tapped_water(vector<int>&arr,int n){
    int leftMax = 0;
    int rightMax = 0;
    int l = 0;
    int r = n-1;
    int total = 0;
    while(l<r){
        if(arr[l]<=arr[r]){
            if(leftMax>arr[l]){
                total+=leftMax-arr[l];
            }
            else leftMax = arr[l];

            l++;
        }
        else{
            if(rightMax>arr[r]){
                total+=rightMax-arr[r];
            }
            else rightMax=arr[r];
            r--;
        }
    }
    return total;
}
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    vector<int>arr;

    input_array(arr,n);
    print_array(arr,n);

    vector<int> pmax = prefix_max(arr,n);
    vector<int> smax = suffix_max(arr,n);

    // print_array(pmax,n);
    // print_array(smax,n);

    // cout<<"\ntotal tapped rain = "<<tapping_total_water(arr,n);

    // cout<<"\ntotal tapped rain = "<<tappingTotalWater(arr,n);

    cout<<"\ntotal tapped rain = "<<total_tapped_water(arr,n);
}