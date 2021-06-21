/*
~~~ 1051D - Bicolorings ~~~

Key Concepts: DP

EZ counting dp problem; but my implementation is really ugly

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;
const int MAXN = 1e3 + 5;

int n, k;
ll dp[2][2][MAXN][2*MAXN];

ll numWays(int lastUp, int lastDown, int col, int req) {

    if (col==n) {
        if (req==0) return 1;
        return 0;
    }

    if (dp[lastUp][lastDown][col][req] != -1) return dp[lastUp][lastDown][col][req];

    ll ans = 0;

    // white, white
    int newReq = req;
    if (col==0) newReq--;
    else if (lastUp && lastDown) newReq--;
    ans = (ans + numWays(0, 0, col+1, newReq)) % MOD;

    // black, black
    newReq = req;
    if (col==0) newReq--;
    else if (!lastUp && !lastDown) newReq--;
    ans = (ans + numWays(1, 1, col+1, newReq)) % MOD;

    // white black
    newReq = req;
    if (col==0) newReq-=2;
    else {
        if (lastUp) newReq--;
        if (!lastDown) newReq--;
    }
    ans = (ans + numWays(0, 1, col+1, newReq)) % MOD;

    // black white
    newReq = req;
    if (col==0) newReq-=2;
    else {
        if (!lastUp) newReq--;
        if (lastDown) newReq--;
    }
    ans = (ans + numWays(1, 0, col+1, newReq)) % MOD;

    return dp[lastUp][lastDown][col][req] = ans;
}

int main() {
    cin>>n>>k;

    for (int i=0;i<2;i++) 
        for (int j=0;j<2;j++)
            for (int k=0;k<MAXN;k++)
                for (int l=0;l<2*MAXN;l++)
                    dp[i][j][k][l] = -1;

    ll ans = numWays(0, 0, 0, k);
    cout<<ans<<"\n";
}