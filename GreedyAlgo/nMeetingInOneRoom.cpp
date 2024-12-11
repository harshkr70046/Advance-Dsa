#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<vector<int>>&arr,int n,int m){
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
void print_array(vector<vector<int>>&arr){
    for(auto val:arr){
        for(auto v:val){
            cout<<v<<"->";
        }
        cout<<endl;
    }
}
bool comp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
int totalMeating(vector<vector<int>>&arr){
    int count = 0;
    int lastEnd = -1;
    sort(arr.begin(),arr.end(),comp);
    for(int i=0;i<arr.size();i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(start>=lastEnd){
            count++;
            lastEnd = end;
        }
    }
    return count;
}
int numberOverLaping(vector<vector<int>>&arr){
    
    sort(arr.begin(),arr.end(),comp);
    int count = 1;
    int lastEnd = arr[0][1];
    for(int i=1;i<arr.size();i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(start>=lastEnd){
            count++;
            lastEnd = end;
        }
    }
    return arr.size()-count;
}
//! second method 
int TotalnumberOverlapping(vector<vector<int>>& arr) {
    sort(arr.begin(), arr.end(), comp); // Sort intervals by start time
    int overlapCount = 0;
    int lastEnd = arr[0][1]; // End time of the first interval

    for (int i = 1; i < arr.size(); i++) {
        int start = arr[i][0];
        int end = arr[i][1];

        // If the current interval overlaps with the previous one
        if (start < lastEnd) {
            overlapCount++;
            lastEnd = max(lastEnd, end); // Update lastEnd to cover maximum overlap
        } else {
            lastEnd = end; // Update lastEnd to the current interval's end
        }
    }

    return overlapCount;
}
//! insert interval
vector<pair<int, int>> insertInterval(vector<pair<int, int>>& intervals, pair<int, int> newInterval) {
    vector<pair<int,int>>ans;
    int i = 0;
    int n = intervals.size();
    while(i<n && intervals[i].second<newInterval.first){
        ans.push_back({intervals[i].first,intervals[i].second});
        i++;
    }
    while(i<n && intervals[i].first<newInterval.second){
        newInterval.first = min(newInterval.first,intervals[i].first);
        newInterval.second = max(newInterval.second,intervals[i].second);
        i++;
    }
    ans.push_back(newInterval);
    while(i<n){
        ans.push_back({intervals[i].first,intervals[i].second});
        i++;
    }
    return ans;
}
int main(){
    int n;
    cout<<"\nRow size   = ";
    cin>>n;
    int m;
    cout<<"\nColum size  = ";
    cin>>m;
    // vector<vector<int>>arr;
    // input_array(arr,n,m);
    // print_array(arr);
    // cout<<"Total  Meating = "<<totalMeating(arr);
    //cout<<"\n No overLap = "<<TotalnumberOverlapping(arr);
    vector<pair<int,int>>interval;
    for(int i=0;i<n;i++){
        int num1,num2;
        cout<<"\nenter the first num = ";
        cin>>num1;
        cout<<"\nenter the second num = ";
        cin>>num2;
        interval.push_back({num1,num2});
    }
    pair<int,int>newinteval;
    newinteval = {6,8};
    vector<pair<int,int>>ans = insertInterval(interval,newinteval);
    for(int i=0;i<ans.size();i++){
        cout<<"{"<<ans[i].first<<" "<<ans[i].second<<"}";
    }
}