#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_arrray(vector<int>&arr,int n){
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
//! write a code for assign cookies
//* in this question we have given two array greedy this is parent and 
//* every parient has its own cookies with a array we have to written the
//* maximum number of student
int assignCookies(vector<int>&greedy,vector<int>&s){
    int n = greedy.size();
    int m = s.size();
    sort(greedy.begin(),greedy.end());
    sort(s.begin(),s.end());
    int i = 0;
    int j = 0;
    while(i<m){
        if(s[i]>=greedy[j]){
            j++;
        }
        i++;
    }
    return j;
}
//! lamination charge
//*we have given a rupees in 5 ,10 and 20 we have 
//* return is this possible or not
bool laminationChargePosssible(vector<int>&arr,int n){
    int five = 0;
    int ten = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==5) five++;
        else if(arr[i]==10){
            if(five){
                five--;
                ten++;
            }
            else return false;
        }
        else{
            if(five && ten){
                five--;
                ten--;
            }
            else if(five>=3){
                five-=3;
            }
            else return false;
        }
    }
    return true;
}
//! shortest job first
int shortestJobFirst(vector<int>&arr,int n){
    int time = 0;
    int waitTime = 0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        waitTime+=time;
        time+=arr[i];
    }
    return waitTime/n;
}
//! jump Game I
//! is it possible to move 0th index element by jumping so it goes to last index
bool is_possible_toreach_last(vector<int>&arr,int n){
    int max_jump = 0;
    for(int i=0;i<n;i++){
        if(i>max_jump) return false;
        max_jump = max(max_jump,arr[i]+i);
         
    }
    return true;
}
//! jump Game II
//! return the minimum number of jump to reach the last
int minimum_jump(vector<int>&arr,int n){
    int jumps = 0;
    int l = 0;
    int r = 0;
    while(r<n-1){
        int farthest = 0;
        for(int ind = l;ind<=r;ind++){
            farthest = max(ind+arr[ind],farthest);
        }
        l = r+1;
        r = farthest;
        jumps = jumps+1;
    }
    return jumps;
}
//! second method 
int minimum_jump_to_reach_last(vector<int>& arr, int n) {
    int jumps = 0;  // Number of jumps
    int farthest = 0; // Farthest position reachable in the current range
    int current_end = 0; // End of the current jump range

    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + arr[i]);

        if (i == current_end) { // When we reach the end of the current range
            jumps++;
            current_end = farthest;

            if (current_end >= n - 1) { // If we can reach or exceed the last index
                break;
            }
        }

        if (farthest <= i) { // If we can't progress further
            return -1;
        }
    }

    return jumps;
}
int main(){
    int n;
    cout<<"\nenter the size of the array  = ";
    cin>>n;
    // int m;
    // cout<<"\nenter the size of the second array = ";
    // cin>>m;
    vector<int>arr;
    // vector<int>arr1;
    input_arrray(arr,n);
    // input_arrray(arr1,m);
    print_array(arr,n);
    // print_array(arr1,m);
    // cout<<"\nmaximum student = "<<assignCookies(arr,arr1);
    // if(is_possible_toreach_last(arr,n)){
    //     cout<<"yes it is possible.";
    // }
    // else cout<<"No it is not possible.";

    cout<<"maxJump number = "<<minimum_jump_to_reach_last(arr,n);
}