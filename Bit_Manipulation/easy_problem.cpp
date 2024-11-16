#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//count the total number of bits so that start become the goal
string convert_decimal_to_binary(int n){
    string s = "";
    while(n){
        int dig = n%2;
        if(dig==1){
            s+='1';
        }
        else s+='0';
        n = n/2;
    }
    reverse(s.begin(),s.end());
    return s;
}
//brute force code
int count_total_bits(int start,int goal){
    string s = convert_decimal_to_binary(start);
    string g = convert_decimal_to_binary(goal);
    while (s.size() < g.size()) s = '0' + s;
    while (g.size() < s.size()) g = '0' + g;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != g[i]) cnt++;
    }
    return cnt;
    
}
// optimal code
int count_set_bit_to_reach_goal(int start,int goal){
    int ans = start^goal;
    int cnt = 0;
    for(int i=0;i<31;i++){
        if(ans&(1<<i)) cnt++;
    }
    return cnt;
}
// more optimal
int count_the_bits(int start,int goal){
    int new_num = start^goal;
    int cnt = 0;
    while(new_num){
        if(new_num&1) cnt++;
        new_num = new_num>>1;
    }
    return cnt;
}
void input_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int num;
        cout<<"\nenter the size of the array = ";
        cin>>num;
        arr.push_back(num);
    }
}
void print_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;
}
// print all the power set or subsequence this is recursive code
void helper(int ind,vector<int>&arr,int n,vector<int>&temp){
    if(ind==n){
        if(temp.size()==0) cout<<"{}";
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<",";
        }
        cout<<endl;
        return;
    }
    
    helper(ind+1,arr,n,temp);
    temp.push_back(arr[ind]);
    helper(ind+1,arr,n,temp);
    temp.pop_back();
    
}
void print_power_set(vector<int>&arr,int n){
    int i = 0;
    vector<int>temp;
    helper(i,arr,n,temp);
}

// using bit manipulation
void helper_of_print_subcequence(vector<int>&arr,int num){
    int size = arr.size();
    if(num==0) cout<<"{},";
    string s =convert_decimal_to_binary(num); 
    while(s.size()<size) s = '0'+s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            cout<<arr[i]<<",";
        }
    }
}
void print_subcequence(vector<int>&arr,int n){
    int total_s = pow(2,n);
    for(int i=0;i<total_s;i++){
        helper_of_print_subcequence(arr,i);
        cout<<endl;
    }
}

//optimal code using bit maniputlaion
void print_power_set___(vector<int>&arr,int n){
    int total_s = pow(2,n);
    for(int i=0;i<total_s;i++){
        if(i==0) cout<<"{},";
        for(int j=0;j<n;j++){
            if(i&(1<<j)) cout<<arr[j]<<",";

        }
        cout<<endl;
    }
}
int main(){

    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    vector<int>arr;
    input_array(arr,n);
    print_array(arr,n);
    print_power_set___(arr,n);

    // int start ,goal;
    // cout<<"\nenter the start = ";
    // cin>>start;
    // cout<<"\nenter the goal = ";
    // cin>>goal;
    // int cnt = count_the_bits(start,goal);
    // cout<<"\ntotal count of different bit = "<<cnt;
    // cout<<endl;
    
}