/*
~~~ 431C - k-Tree ~~~

Key Concepts: DP

Very simple DP

I initially thought it was some yucky math graph theory problem
    but since the bounds of n are so small DP is possible

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e2 + 5;
const ll MOD = 1e9 + 7;

int n, k, d;
ll dp[MAXN][2];

ll numWays(int left, bool hasD) {
    if (left == 0 && hasD) return 1;

    if (dp[left][hasD] != -1) return dp[left][hasD];

    ll ans = 0;

    for (int i=1;i<=k;i++) {
        if (left - i >= 0) 
            ans = (ans + numWays(left - i, hasD || (i >= d))) % MOD;
    }

    return dp[left][hasD] = ans;   

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>d;

    for (int i=0;i<MAXN;i++) for (int j=0;j<2;j++) dp[i][j] = -1;

    ll ans = numWays(n, false);

    cout<<ans<<"\n";
}