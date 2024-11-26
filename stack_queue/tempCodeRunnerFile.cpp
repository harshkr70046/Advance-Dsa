//! brute force
int total_subarray_sum(vector<int>&arr,int n){
    int total = 0;
    int mod = (int)1e9+7;
    for(int i=0;i<n;i++){
        int mini = arr[i];
        for(int j=i;j<n;j++)
        mini = min(mini,arr[j]);
        total+=mini%mod;
    }
    return total;
}