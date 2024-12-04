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
void print_array(vector<int>&arr,int n)
{
    for(int j=0;j<n;j++){
        cout<<arr[j]<<"     ";
    }
    cout<<endl;
}
//! we have two basket each backet conatin unique frute return the maximum length of the sub-arrray
//! brute
int max_len_of_subarry_with_2type_fruite(vector<int>&arr,int n,int k){
    int maxi = 0;
    
    for(int i=0;i<n;i++){
        unordered_set<int>st;
        for(int j=i;j<n;j++){
            st.insert(arr[j]);
            if(st.size()<=2){
                maxi = max(maxi,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxi;
}
//!Optimal
int maximumFruteInTwoBasket(vector<int>&arr,int n,int k){
    int j = 0,i=0,maxi = 0;
    unordered_map<int, int> fruitCount;

    while (j < n) {
        // Add the current fruit to the map
        fruitCount[arr[j]]++;

        // If we have more than 2 types of fruits, shrink the window
        while (fruitCount.size() > 2) {
            fruitCount[arr[i]]--;
            if (fruitCount[arr[i]] == 0) {
                fruitCount.erase(arr[i]); // Remove the fruit type from the map
            }
            i++; // Move the left pointer
        }

        // Update the maximum length of the window
        maxi = max(maxi, j - i + 1);
        j++; // Move the right pointer
    }

    return maxi;
}
//! more optimal
int max_len_of_fruite(vector<int>&arr,int n,int k){
    int i = 0;
    int j = 0;
    int maxi = 0;
    unordered_map<int,int>mp;
    while(j<n){
        mp[arr[j]]++;
        if(mp.size()>2){
            mp[arr[i]]--;
            if(mp[arr[i]]==0){
                mp.erase(arr[i]);
            }
            i++;
        }
        if(mp.size()<=2){
            maxi = max(maxi,j-i+1);
        }
        j++;
    }
    return maxi;
}
//! we have a string find out the longest subarray with k distint character
//! brute
int maxi_len_of_k_distinct_char(string s,int k){
    int maxi = 0;
    for(int i=0;i<s.size();i++){
        unordered_set<int>st;
        for(int j=i;j<s.size();j++){
            st.insert(s[j]);
            if(st.size()<=2){
                maxi = max(maxi,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxi;
}
//! better approch
int maxLenofKdistinctCHar(string s,int k){
    int i=0;
    int j = 0;
    int maxi = 0;
    unordered_map<int,int>mp;
    while(j<s.size()){
        mp[s[j]]++;
        while(mp.size()>2){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }
        if(mp.size()<=2){
            maxi = max(maxi,j-i+1);
        }
        j++;
    }
    return maxi;
}
//! opimal code
int max_Len_ofKdistinctChar(string s,int k){
    int i=0;
    int j = 0;
    int maxi = 0;
    unordered_map<int,int>mp;
    while(j<s.size()){
        mp[s[j]]++;
        if(mp.size()>2){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }
        if(mp.size()<=2){
            maxi = max(maxi,j-i+1);
        }
        j++;
    }
    return maxi;
}

//! Number of substring containing all three characters
int Number_of_subtring(string s,int k){
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        int arr[3] = {0};
        for(int j=i;j<s.size();j++){
            arr[s[j]-'a']=1;
            if(arr[0]+arr[1]+arr[2]==3){
                cnt=cnt+(s.size()-j);
                break;
            }
        }
    }
    return cnt;
}
//! optimal code
int totalSubarrayWithKChar(string s,int k){
    int lastSeen[3] = {-1,-1,-1};
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        lastSeen[s[i]-'a'] = i;
        if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
            cnt+=(1+min(min(lastSeen[0],lastSeen[1]),lastSeen[2]));
        }
    }
    return cnt;
}
//! find the longest substring after changing k char 
int longest_substring(string s,int k){
    int maxLen = 0;
    for(int i=0;i<s.size();i++){
        int arr[26] = {0};
        int maxFreq = 0;
        for(int j=i;j<s.size();j++){
            arr[s[j]]++;
            maxFreq = max(maxFreq,arr[s[i]]);
            int changes = (j-i+1) - maxFreq;
            if(changes<=k){
                maxLen = max(maxLen,j-i+1);
            } 
            else{
                break;
            }
        }
    }
    return maxLen;
}
//! optimal code
int longestSubtr(string s,int T){
    int l = 0,r = 0,maxlen = 0, maxFreq = 0;
    int arr[26] = {0};
    while(r<s.size()){
        arr[s[r]-'A']++;
        maxFreq = max(maxFreq,arr[s[r]-'A']);
        while(r-l+1 - maxFreq > T){
            arr[s[l]-'A']--;
            maxFreq = 0;
            for(int k=0;k<26;k++){
                if(maxFreq<arr[k]) maxFreq = arr[k];
            }
            l = l+1;
        }
        if((r-l+1)-maxFreq <= T){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}
//! more optimize
int longestSubtrKChange(string s,int T){
    int l = 0,r = 0,maxlen = 0, maxFreq = 0;
    int arr[26] = {0};
    while(r<s.size()){
        arr[s[r]-'A']++;
        maxFreq = max(maxFreq,arr[s[r]-'A']);
        if(r-l+1 - maxFreq > T){
            arr[s[l]-'A']--;
            l = l+1;
        }
        if((r-l+1)-maxFreq <= T){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}
int main(){
    // int n;
    // cout<<"\nenter the size of the array = ";
    // cin>>n;
    // vector<int>arr;
    // input_array(arr,n);
    // print_array(arr,n);
    //cout<<"\nMaximum frute of 2 type is = "<<max_len_of_fruite(arr,n,2);
    //string s = "bbacba";
    // cout<<"\n maximum len of k chr = "<<max_Len_ofKdistinctChar(s,2);
    // cout<<"\nTotal number of substring = "<<totalSubarrayWithKChar(s,3);

    string s = "AAABA";
    // cout<<"\nlongest substring after chage k char = "<<longest_substring(s,2);
    cout<<"\n Longest len of substring = "<<longestSubtrKChange(s,2);
}  