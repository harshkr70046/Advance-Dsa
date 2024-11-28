#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<char>&arr,int n){
    for(int i=0;i<n;i++){
        char c;
        cout<<"\nenter the array element = ";
        cin>>c;
        arr.push_back(c);
    }
}
void print_array(vector<char>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
}
//! find the smallest number after removing k element.
vector<char> smallest_number(vector<char>&arr,int n,int k){
    stack<char>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && st.top()-'0'>arr[i]-'0'){
            st.pop();
            k=k-1;
        }
        st.push(arr[i]);
    }
    while(k>0){
        st.pop();
        k--;
    }
    if(st.empty()) return {'0'};
    vector<char>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    for(int i=ans.size()-1;i>=0;i--){
        if(ans[i]=='0') ans.pop_back();
        else break;
    }
    reverse(ans.begin(),ans.end());
    if(ans.empty()) return {'0'};
    return ans;
}
//! online stock span 
//! first of fall we have to take the number of days.
void input_days(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int days;
        cout<<"\nenter the number of days = ";
        cin>>days;
        arr.push_back(days);
    }
}
void print_days(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
}
int maximum_days(vector<int>&days,int n){
    stack<pair<int,int>>st;
    int max_days = 1;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().first<=days[i]){
            st.pop();
        }
        int pgei = (st.empty())?-1:st.top().second;
        max_days = max((i-pgei),max_days);
        st.push({days[i],i});
    }
    return max_days;
}
//! sliding window maximum
vector<int> maximum_in_kLength_window(vector<int>&arr,int n,int k){
    vector<int> v; // Store the results
    deque<int> dq; // Store indices of elements in decreasing order

    for (int i = 0; i < n; i++) {
        // Remove indices of elements not in the current window
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove indices of smaller elements as they will never be the maximum
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Add the current element's index
        dq.push_back(i);

        // Add the maximum of the current window to the result
        if (i >= k - 1) {
            v.push_back(arr[dq.front()]);
        }
    }

    return v;
}
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    // vector<char>v;
    // input_array(v,n);
    // cout<<endl;
    // print_array(v,n);
    // vector<char>ans = smallest_number(v,n,3);
    // cout<<endl;
    // print_array(ans,ans.size());
    vector<int>arr;
    input_days(arr,n);
    print_days(arr,n);
    // cout<<"\n Maximum consiqutive days = "<<maximum_days(arr,n);
    vector<int>ans = maximum_in_kLength_window(arr,n,3);
    cout<<endl;
    print_days(ans,ans.size());
    
}