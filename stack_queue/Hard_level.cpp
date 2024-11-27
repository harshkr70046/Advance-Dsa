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
vector<int> nGe(vector<int>&arr,int n){
    vector<int>nge(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        nge[i] = (st.empty())?n:st.top();
        st.push(i);
    }
    return nge;
}
//! previous greater element
vector<int> pGe(vector<int>&arr,int n){
    vector<int>pge(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        pge[i] = (st.empty())?-1:st.top();
        st.push(i);
    }
    return pge;
}
//! main function where it will use
int total_sum_of_range_of_subarray(vector<int>&arr,int n){
    vector<int>pse = pSe(arr,n);
    vector<int>nse = nSe(arr,n);
    vector<int>pge = pGe(arr,n);
    vector<int>nge = nGe(arr,n);
    int total = 0;
    int mod = (int)1e9+7;
    for(int i=0;i<n;i++){
        int left_sm = i - pse[i];
        int right_sm = nse[i] - i;
        int left_lg = i - pge[i];
        int right_lg = nge[i] - i;

        int largest = right_lg*left_lg*1ll*arr[i];
        int smallest = right_sm*left_sm*1ll*arr[i];
        int range = largest-smallest;
        
        total = (total+range)%mod;
    }
    return total;
}
//! Aestroid Collision
vector<int> Aestroid_Collision(vector<int>&arr,int n){
    vector<int>st;
    for(int i=0;i<n;i++){
        if(arr[i]>0) st.push_back(arr[i]);
        else {
            while(!st.empty() && st.back()>0 && st.back()<abs(arr[i])){
                st.pop_back();
            }
            if(!st.empty() && st.back()==abs(arr[i])) st.pop_back();
            else if(st.empty() || st.back()<0) st.push_back(arr[i]);
        }
    }
    return st;
}
//! largest rectange in the histogram
//* to find thid problem we need to find the pse and nse.
vector<int> PsmallElement(vector<int>&arr,int n){
    stack<int>st;
    vector<int>v(n);

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]) {
            st.pop();
        }
        v[i] = (st.empty())?-1:st.top();
        st.push(i);
    }
    return v;
}

vector<int> NsmallElement(vector<int>&arr,int n){
    stack<int>st;
    vector<int>v(n);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) {
            st.pop();
        }
        v[i] = (st.empty())?n:st.top();
        st.push(i);
    }
    return v;
}
int area_of_largest_rectange(vector<int>&arr,int n){
    int max_area = INT_MIN;
    vector<int>nse = NsmallElement(arr,n);
    vector<int>pse = PsmallElement(arr,n);
    for(int i=0;i<n;i++){
        int leftMax = pse[i];
        int rightMax = nse[i];
        int area = arr[i]*(rightMax-leftMax-1);
        max_area = max(max_area,area);
    }
    return max_area;
}
//! optimal code for largest area of rectange in histogram
int LAORIH(vector<int>&arr,int n){
    int maxArea = 0;
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int ele = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty()?-1:st.top();
            maxArea = max(arr[ele]*(nse-pse-1),maxArea);
        }
        st.push(i);
    }
    while(!st.empty()){
        int ele = st.top();
        st.pop();
        int nse = n;
        int pse = st.empty()?-1:st.top();
        maxArea = max(arr[ele]*(nse-pse-1),maxArea);
    }
    return maxArea;
}
//! maximum rectange in 2d array.
void input_2d_arrray(vector<vector<int>>&arr,int n,int m){
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<m;j++){
            int num;
            cout<<"\nenter the element of the array = ";
            cin>>num;
            temp.push_back(num);
        }
        arr.push_back(temp);
    }
}
void print_2d_array(vector<vector<int>>&arr,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<"      ";
        }
        cout<<endl;
    }
}
//! prefix sum in 2d array
// Function to calculate prefix sum of the 2D array column-wise
vector<vector<int>> prefix_sum(vector<vector<int>>& arr, int n, int m) {
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[j][i];
            v[j][i] = sum;
        }
    }
    return v;
}

// Function to calculate the largest rectangle in a histogram
int LAORIH_(vector<int>& arr, int n) {
    int maxArea = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            int ele = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(arr[ele] * (nse - pse - 1), maxArea);
        }
        st.push(i);
    }
    while (!st.empty()) {
        int ele = st.top();
        st.pop();
        int nse = n;
        int pse = st.empty() ? -1 : st.top();
        maxArea = max(arr[ele] * (nse - pse - 1), maxArea);
    }
    return maxArea;
}

// Function to find the maximum rectangle sum in a 2D array
int max_rectangle_in_2d_array(vector<vector<int>>& arr, int n, int m) {
    vector<vector<int>> Psum = prefix_sum(arr, n, m);
    int maxRect = 0;
    for (int i = 0; i < n; i++) {
        maxRect = max(LAORIH_(Psum[i], m), maxRect);
    }
    return maxRect;
}

int main(){
    // int n;
    // cout<<"\nenter the size of the array = ";
    // cin>>n;
    // vector<int>arr;

    // input_array(arr,n);
    // print_array(arr,n);

    // vector<int> pmax = prefix_max(arr,n);
    // vector<int> smax = suffix_max(arr,n);

    // print_array(pmax,n);
    // print_array(smax,n);

    // cout<<"\ntotal tapped rain = "<<tapping_total_water(arr,n);

    // cout<<"\ntotal tapped rain = "<<tappingTotalWater(arr,n);

    // cout<<"\ntotal tapped rain = "<<total_tapped_water(arr,n);

    // cout<<"\ntotal sum of subarray minimum = "<<sum_subarray(arr,n);

    // cout<<"\ntotal sum of subarray minimum = "<<total_subarray_sum(arr,n);

    // cout<<"\nrange sum of all subarray = "<<total_sum_of_range_of_subarray(arr,n);
    // vector<int>astroid = Aestroid_Collision(arr,n);
    // print_array(astroid,astroid.size());

    // cout<<"\nlargest area rectange = "<<area_of_largest_rectange(arr,n);

    // cout<<"\nlargest area rectange = "<<LAORIH(arr,n);

     vector<vector<int>> arr = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };
    int n = arr.size();
    int m = arr[0].size();
    cout << "Maximum Rectangle Sum: " << max_rectangle_in_2d_array(arr, n, m) << endl;
}