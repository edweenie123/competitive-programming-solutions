/*
~~~ 225C - Barcode ~~~

Key Concepts: DP

Pretty simple dp

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int n, m, x, y;

int black[MAXN];

int dp[MAXN][MAXN][2];

int minChange(int idx, int wid, int isBlack) {
    if (idx > m) {
        if (wid >= x) return 0;
        else return 1e9;
    }

    if (dp[idx][wid][isBlack] != -1) return dp[idx][wid][isBlack];
    
    int sameCol = 1e9;
    int difCol = 1e9;

    if (wid < y) {

        sameCol = minChange(idx + 1, wid+1, isBlack);
        if (isBlack) sameCol += n - black[idx];
        else sameCol += black[idx];

    } 

    if (wid >= x) {
        difCol = minChange(idx + 1, 1, !isBlack);
        if (isBlack) difCol += black[idx];
        else difCol += n - black[idx];
    }

    
    return dp[idx][wid][isBlack] = min(sameCol, difCol);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>x>>y;

    char c;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>c;
            if (c=='#') black[j]++;
        }
    }

    memset(dp, -1, sizeof(dp));

    int ans1 = minChange(2, 1, true) + n - black[1];
    int ans2 = minChange(2, 1, false) + black[1];

    int ans = min(ans1, ans2);

    cout<<ans<<"\n";
}