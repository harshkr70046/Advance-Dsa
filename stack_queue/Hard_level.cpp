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

//! sum of subarray minimum.
//! next smaller element
vector<int> next_smaller_element(vector<int>&arr,int n){
    vector<int>nse(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        nse[i] = (st.empty())?n:st.top();
        st.push(i);
    }
    return nse;
}
//! previous smaller element
vector<int> previous_smaller_element(vector<int>&arr,int n){
    vector<int>pse(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        pse[i] = (st.empty())?-1:st.top();
        st.push(i);
    }
    return pse;
}
int sum_subarray(vector<int>&arr,int n){
    vector<int>nse = next_smaller_element(arr,n);
    vector<int>pse = previous_smaller_element(arr,n);
    int total = 0;
    int mod = (int)1e9+7;
    for(int i=0;i<n;i++){
        int left = i-pse[i];
        int right = nse[i]-i;
        total = (total + 1LL * right * left * arr[i] % mod) % mod;
    }
    return total;
}

//! brute force
int total_subarray_sum(vector<int>&arr,int n){
    int total = 0;
    int mod = (int)1e9+7;
    for(int i=0;i<n;i++){
        int mini = arr[i];
        for(int j=i;j<n;j++){
            mini = min(mini,arr[j]);
            total = (total + mini)%mod;
        }   
    }
    return total;
}

//! sum of subarray ranges it means
//* to find the answer of this problem we need to find nse pse nge pge
//!next smaller element
vector<int> nSe(vector<int>&arr,int n){
    vector<int>nse(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

        nse[i] = (st.empty())?n:st.top();
        st.push(i);
    }
    return nse;
}
//! previous smaller element
vector<int> pSe(vector<int>&arr,int n){
    vector<int>pse(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]) st.pop();

        pse[i] = (st.empty())?-1:st.top();
        st.push(i);
    }
    return pse;
}
//! next greater element;
vector<int> nGe(vector<int>&arr,int n)
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

    // cout<<"\ntotal tapped rain = "<<total_tapped_water(arr,n);

    cout<<"\ntotal sum of subarray minimum = "<<sum_subarray(arr,n);

    cout<<"\ntotal sum of subarray minimum = "<<total_subarray_sum(arr,n);
}