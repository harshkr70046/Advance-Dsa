#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(string &s, int ind, string &r)
{
    if (ind == s.size())
        return;
    solve(s, ind + 1, r);
    r.push_back(s[ind]);
}
string reverse(string &s)
{
    string r = "";
    solve(s, 0, r);
    return r;
}
int feb(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return feb(n - 1) + feb(n - 2);
}

long long toh(int n, int from, int to, int aux) {
    if(n == 1) {
        cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        return 1;
    }
        
	int count = toh(n-1, from, aux, to);
        
    cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
    count++;
        
    count += toh(n-1, aux, to, from);
        
    return count;
}
void merge(vector<int>&arr,int start,int mid,int end){
    int i = start;
    int j = mid+1;
    vector<int>temp;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<temp.size();i++){
        arr[start+i] = temp[i];
    }
}
void mergeSort(vector<int>&arr,int start,int end){
    if(start>=end) return;
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int partition(vector<int>&arr,int low,int high){
    int pivot = arr[high];
    int pi = low;
    for(int i=low;i<high;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[pi]);
            pi++;
        }
    }
    swap(arr[pi],arr[high]);

    
    return pi;
}
void quickSort(vector<int>&arr,int low,int high){
    if(low>=high) return;

    int pi = partition(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
}
int main()
{
    // string s = "Harsh";
    // string ans = reverse(s);
    // cout << "reverses = " << ans;
    // // cout<<"\nfeb = "<<feb(6);

    // cout << endl;
    // cout << feb(6);
    vector<int>arr = {1,4,5,3,7,2,9};
    quickSort(arr,0,6);
    for(int i=0;i<=6;i++){
        cout<<arr[i]<<" ";
    }

}