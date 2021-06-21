/*
~~~ 474D - Flowers ~~~

Key Concepts: DP, PSA

Very simple DP problem;

i initially thought it was a math problem tho

Be careful the modding on the psa

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;


ll k;

ll dp[MAXN];
ll dpPSA[MAXN];

ll ways(int fLeft) {

    if (fLeft < 0) return 0;
    if (fLeft == 0) return 1;

    if (dp[fLeft] != -1) return dp[fLeft];

    ll goRed = ways(fLeft-1);
    ll goWhite = ways(fLeft-k);

    return dp[fLeft] = (goRed + goWhite) % MOD;
}


int main() {
    int TC; cin>>TC;
    cin>>k;

    for (int i=0;i<MAXN;i++) dp[i] = -1;
    for (int i=1;i<MAXN;i++) ways(i);
    for (int i=1;i<MAXN;i++) dpPSA[i] = (dpPSA[i-1] + dp[i]) % MOD;

    int a, b;
    while (TC--) {
        cin>>a>>b;
        ll ans = (dpPSA[b] - dpPSA[a - 1] + MOD) % MOD;        
        cout<<ans<<"\n";
    }
}