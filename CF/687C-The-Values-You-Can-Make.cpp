/*
~~~ 687C - The Values You Can Make ~~~

Key Concepts: DP

Classic dp subset sum problem with a twist

I couldn't initally solve this cause im dumb, but once i realized the state -> it was obvious

DP(idx, k, x) returns true if you can 
    -> create a subset with sum k using coins idx -> n
        and within that subset you can create a sum of x

Pretty simple transition..
    You can choose 3 options:
        ignore current element
        take current element and contribute to x
        take current element and not contribute to x

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 5;

int n, k;
short coins[MAXN];
short dp[MAXN][MAXN][MAXN];

vector<int> ans;

bool isPos(int idx, int k, int x) {
    if (k<0||x<0||x>k) return false;

    if (idx==n) {
        if ((k!=0) || (x!=0)) return false;
        return true;
    }

    if (dp[idx][k][x] != -1) return dp[idx][k][x];

    bool ret = false;

    // don't take idx
    if (isPos(idx+1, k, x))
        ret = true;

    // take idx, contribute to x
    else if (isPos(idx+1, k-coins[idx], x-coins[idx]))
        ret = true;
    // take idx, don't contribute to x
    else if (isPos(idx+1, k-coins[idx], x))
        ret = true;


    return dp[idx][k][x] = ret;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;

    for (int i=0;i<n;i++) 
        cin>>coins[i];
    
    for (int i=0;i<MAXN;i++)
        for (int j=0;j<MAXN;j++)
            for (int k=0;k<MAXN;k++)
                dp[i][j][k] = -1;

    for (int x=0;x<MAXN;x++) 
        if (isPos(0, k, x)) 
            ans.push_back(x);

    cout<<ans.size()<<"\n";
    
    for (auto a : ans) 
        cout<<a<<" ";

    cout<<"\n";
}