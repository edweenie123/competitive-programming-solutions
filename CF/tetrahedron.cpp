// #pragma comment(linker, "/STACK: 2000000000")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e7 + 5;
const ll MOD = 1e9 + 7;

char dp[MAXN][2];

char numPaths(int moves, bool isD) {
    if (moves<0) return 0;
    if (moves==0) return isD;
    // cout<<moves<<" "<<isD<<"\n";
    if (dp[moves][isD] != -1) return dp[moves][isD];

    char paths;
    if (isD) paths = (numPaths(moves-1, false) * 3) % MOD;
    else paths = (numPaths(moves-1, false) * 2 + numPaths(moves-1, true)) % MOD;

    return dp[moves][isD] = paths;
}

int n;
int main() {
    cin>>n;

    for (int i=0;i<MAXN;i++) for (int j=0;j<2;j++) dp[i][j] = -1;
    ll ans = numPaths(n, 1);
    cout<<ans<<"\n";
}