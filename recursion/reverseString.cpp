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

int main()
{
    string s = "Harsh";
    string ans = reverse(s);
    cout << "reverses = " << ans;
    // cout<<"\nfeb = "<<feb(6);

    cout << endl;
    cout << feb(6);
}