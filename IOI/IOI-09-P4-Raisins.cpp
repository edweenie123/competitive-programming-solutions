/*
~~~ IOI '09 P4 - Raisins ~~~

Key Concepts: DP, PSA

Fairly simple DP
You use a 2D PSA to optimize the DP

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 50 + 5;

int raisin[MAXN][MAXN];
int psa[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

int n, m;

int rangeSum(int r1, int c1, int r2, int c2) {
    int tot = psa[r2][c2] - psa[r1-1][c2] - psa[r2][c1-1] + psa[r1-1][c1-1];
    return tot;
}

int minRaisin(int r1, int c1, int r2, int c2) {
    if (dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];

    int h = r2 - r1 + 1;
    int w = c2 - c1 + 1;

    if (h==1 && w==1) return 0;

    int areaSum = rangeSum(r1, c1, r2, c2); // sum of raisins in rectangle
    int best = 1e9;
    int potenRaisin;

    // try vertical cuts
    for (int i=c1;i<c2;i++) {
        potenRaisin = minRaisin(r1, c1, r2, i) + minRaisin(r1, i+1, r2, c2);
        best = min(best, potenRaisin + areaSum);
    }

    // try horizontal cuts
    for (int i=r1;i<r2;i++) {
        potenRaisin = minRaisin(r1, c1, i, c2) + minRaisin(i+1, c1, r2, c2);
        best = min(best, potenRaisin + areaSum); 
    }

    return dp[r1][c1][r2][c2] = best;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>raisin[i][j];
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + raisin[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    int ans = minRaisin(1, 1, n, m);
    cout<<ans<<"\n";
}