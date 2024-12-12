#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int num;
        cout<<"\n element = ";
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
int minPlatformReq(vector<int>&arr,vector<int>&arr2){
    int n = arr.size();
    int i = 0;
    int j = 0;
    int cnt = 0;
    int maxCnt = 0;
    while(i<n){
        if(arr[i]<=arr2[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        maxCnt = max(maxCnt,cnt);
    }
    return maxCnt;
}
bool is_vaild(int ind,string &s,int cnt){
    if(ind==s.size()){
        return cnt==0;
    }
    if (cnt < 0) {
        return false;
    }
    if(s[ind]=='('){
        return is_vaild(ind+1,s,cnt+1);
    }
    if(s[ind]==')'){
        return is_vaild(ind+1,s,cnt-1);
    }
    
    return is_vaild(ind+1,s,cnt+1)||is_vaild(ind+1,s,cnt-1)||is_vaild(ind+1,s,cnt);
}
bool valid_paranthis(string &s){
    return is_vaild(0,s,0);
}
//* optimal approch
bool is_valid_or_not(string &s){
    int mini = 0;
    int maxi = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            mini+=1;
            maxi+=1;
        }
        else if(s[i]==')'){
            mini = mini-1;
            maxi = maxi+1;
        }
        else{
            mini = mini-1;
            maxi = maxi+1;
        }
        if(mini<0) mini = 0;
        if(maxi<0) return false;
    }
    return mini==0;
}
//! candy Distribution
int totalcandyDistibution(vector<int>&arr,int n){
    vector<int>lrr(n);
    vector<int>rrr(n);
    lrr[0] = 1;
    for(int i=1;i<n;i++){
        if(arr[i]<=arr[i-1]){
            lrr[i] = 1;
        }
        else {
            lrr[i] = lrr[i-1]+1;
        }
    }
    rrr[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<=arr[i+1]){
            rrr[i] = 1;
        }
        else {
            rrr[i] = rrr[i+1]+1;
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=max(lrr[i],rrr[i]);
    }
    return sum;
}
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    vector<int>arr;
    // vector<int>arr1;
    input_array(arr,n);
    // input_array(arr1,n);
    print_array(arr,n);
    // print_array(arr1,n);
    // cout<<"minimum platform = "<<minPlatformReq(arr,arr1);
    // string s = "(*()";
    // if(is_valid_or_not(s)){
    //     cout<<"\n yes it is valid";
    // }
    // else cout<<"\n no it is not valid.";
    cout<<"\n total candy = "<<totalcandyDistibution(arr,n);
}