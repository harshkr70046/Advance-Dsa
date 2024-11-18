#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int num;
        cout<<"\nenter the elemnet of the array = ";
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
int find_the_unique_in_3_num(vector<int>&arr,int n){
    int ans = 0;
    for(int i=0;i<32;i++){
        int cnt = 0;
        for(int j = 0;j<n;j++){
            if(arr[j]&(1<<i)) cnt++;
        }
        if(cnt%3==1) ans = ans|(1<<i);
    }
    return ans;
}
// better approch
int unique_number(vector<int>&arr,int n){
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i+=3){
        if(arr[i-1]!=arr[i]) return arr[i-1];
    }
    return arr[n-1];
}
//concept of bucket
int unique_number_in_group_3(vector<int>&arr,int n){
    int one = 0;
    int two = 0;
    for(int i=0;i<arr.size();i++){
        one = (one^arr[i])& ~two;
        two = (two^arr[i])& ~one;
    }
    return one;
}

// find the two unique number in the dublicate array
pair<int, int> _2_unique(vector<int>& arr, int n) {
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr ^= arr[i];
    }

    // Isolate the rightmost set bit
    int right_bit = (xorr & -xorr);

    int bucket1 = 0, bucket2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] & right_bit) {
            bucket1 ^= arr[i];
        } else {
            bucket2 ^= arr[i];
        }
    }

    return {bucket1, bucket2};
}
// find the xor upto t to n;
int xor_upto_n(int n){
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else return n;
}

// find the xor in the range
int xor_in_range(int l,int r){
    int xor_before_l = xor_upto_n(l-1);

    int ans = xor_before_l ^ xor_upto_n(r);
    return ans;
}

// we have given the divend and divisor we have to devide it without using / sign
int divide(int dividend,int divisor){
    if(dividend==divisor) return 1;
    bool sign = true;
    if(dividend>=0 && divisor<0) sign = false;
    else if(dividend<0 && divisor>=0) sign = false;
    long n = abs(dividend);
    long d = abs(divisor);
    divisor = abs(divisor);
    long quotient = 0;
    while(n>=d){
        int cnt = 0;
        while(n>=(d<<(cnt+1))){
            cnt++;
        }
        quotient+=1<<cnt;
        n-=(d<<cnt);
    }
    if(quotient==(1<<31) && sign){
        return INT_MAX;
    }
    if(quotient==(1<<3) && !sign){
        return INT_MIN;
    }
    return sign?quotient:-quotient;
}
// this function is not working know the reason connect with harsh.😓
int divide_the_two(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    
    bool sign = true;
    if (dividend >= 0 && divisor < 0) sign = false;
    else if (dividend < 0 && divisor > 0) sign = false;
    
    int n = abs(dividend);
    int d = abs(divisor);
    
    divisor = abs(divisor);
    
    int q = 0;
    while (n >= d) {
        int cnt = 0;
        while (n >= (d * pow(2, cnt))) {
            cnt++;
        }
        q += pow(2, cnt);
        n -= pow(2, cnt) * d;
    }
    
    if (q == pow(2, 31) && sign) return INT_MAX;
    if (q == pow(2, 31) && !sign) return INT_MIN;
    
    return sign ? q : -q;
}
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    int m;
    cout<<"\nenter the second number = ";
    cin>>m;
    cout<<"\nquotient = "<<divide(n,m);
    // vector<int>arr;
    // input_array(arr,n);
    // print_array(arr,n);
    // int unique = unique_number_in_group_3(arr,n);
    // cout<<"\nUnique Number = "<<unique;
    // pair<int,int>p = _2_unique(arr,n);
    // cout<<"\nfirst unique = "<<p.first;
    // cout<<"\nsecond unique = "<<p.second;
    // cout<<"\nxor from one to n = "<<xor_in_range(n,7);

}