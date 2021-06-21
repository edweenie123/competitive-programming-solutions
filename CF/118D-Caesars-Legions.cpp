/*
~~~ 118D - Caesar's Legions ~~~

Key Concepts: Dynamic Programming

The dp recurrence is pretty simple

Becareful not to MLE tho

dp[i][j][k][l]
    = max # of ways if you have i footment j horsemen
      the length of the last chain of the same element is k
      and that chain is made of elements of type l
*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e8;
int n1, n2, k1, k2;

ll dp[101][101][101][3];

ll numWays(int l1, int l2, int c, int t) {
    if (l1 == 0 && l2 == 1) {
        if (t != 2) return 1;
        if (c < k2) return 1;
    }

    if (l2 == 0 && l1 == 1) {
        if (t != 1) return 1;
        if (c < k1) return 1;
    }

    if (dp[l1][l2][c][t] != -1) return dp[l1][l2][c][t];

    ll ans = 0;

    if (l1 > 0) 
        if (t != 1) 
            ans = (ans + numWays(l1-1, l2, 1, 1)) % MOD;
        else if (c < k1)
            ans = (ans + numWays(l1-1, l2, c+1, 1)) % MOD;
    
    if (l2 > 0) 
        if (t != 2) 
            ans = (ans + numWays(l1, l2-1, 1, 2)) % MOD;
        else if (c < k2)
            ans = (ans + numWays(l1, l2-1, c+1, 2)) % MOD;

    return dp[l1][l2][c][t] = ans;

}

int main() {
    cin>>n1>>n2>>k1>>k2;

    memset(dp, -1, sizeof(dp));
    ll ans = numWays(n1, n2, 0, 0);

    cout<<ans<<"\n";
}