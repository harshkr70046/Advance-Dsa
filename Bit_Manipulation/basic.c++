#include<iostream>
#include<bits/stdc++.h>

using namespace std;
string convert_decimal_to_binary(int n){
    string ans;
    while(n){
        int dig = n%2;
        if(dig==1){
            ans+='1';
        }
        else ans+='0';
        n = n/2;
    }
    reverse(ans.begin(),ans.end());
    return ans;

}
int binary_to_decimal(string n){
    int num = 0;
    int j = 0;
    for(int i=n.size()-1;i>=0;i--){
        
        if(n[i]=='1'){
            num+=pow(2,j);
        }
        j++;

    }
    return num;
}
void swap_using_bits(int &n,int &m){
    n = n^m;
    m = n^m;
    n = n^m;
}
//kth bit is set or not
bool check_set_bits(int n,int m){
    string temp = convert_decimal_to_binary(n);
    for(int i=temp.size()-1;i>=0;i--){
        if(m==0){
            if(temp[i]=='1') return true;
            break;
        }
        m--;
    }
    return false;
}

int count_set_bits(int n){
    int cnt = 0;
    while(n){
        int dig = n%2;
        if(dig==1) cnt++;
        n = n/2;
    }
    return cnt;
}
//optimal code
int count(int n){
    int cnt = 0;
    while(n){
        n = n&n-1;
        cnt++;
    }
    return cnt;
}
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    int m;
    cout<<"\nenter the second number = ";
    cin>>m;

    if(check_set_bits(n,m)){
        cout<<"\nyes...";
    }
    else cout<<"no...";

    //left shift
    if((n&(1<<m))==0) cout<<"\nnot..";
    else cout<<"\nyes...";

    //right shift
    if(((n>>m)&1)==0) cout<<"\nno...";
    else cout<<"\nyes..";


    //chnage the mth bit
    cout<<"\nchnage the mth bits = "<<(n|(1<<m));

    //clear the mth bit
    
    //using and and not
    cout<<"\nclear the mth bits = "<<(n&~(1<<m));

    // toggle the set bit using xor
    cout<<"\n toggle the mth bits = "<<(n^(1<<m));

    //remove the last set bit (right most)
    cout<<"\nremove the last set bit = "<<(n&(n-1));


    //check for power of two
    if((n&(n-1))==0) cout<<"\nyes it is power of two...";
    else cout<<"\n no it is not..";

    cout<<"\nnumber of set bit = "<<count_set_bits(n);
    cout<<"\nnumber of set bit = "<<count(n);

    // swap_using_bits(n,m);
    // cout<<"first_num = "<<n<<" second_num = "<<m;

    // string binary = convert_decimal_to_binary(n);
    // cout<<"\nbinary number = "<<binary;
    // int num = binary_to_decimal(binary);
    // cout<<"\ndecimal number = "<<num;
}