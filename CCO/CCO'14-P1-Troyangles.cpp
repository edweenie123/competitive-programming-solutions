/*
~~~ CCO '14 P1 - Troyangles ~~~

Key Concepts: Dynamic Programming

dp[i][j] stores # of triangles you can root at (i, j)

dp[i][j] = min(a, b, c) + 1 where a = left bottom, b = bottom, c = right bottom

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2001;
int n, dp[MAXN][MAXN]; // dp[i][j] = # of triangles you can root at (i, j)

int min3(int a, int b, int c) { return min(min(a, b), c); }

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    char tmp;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>tmp;
            if (tmp=='#') dp[i][j] = 1;
        }
    }

    int ans = 0;
    for (int i=n-1;i>=0;i--) { // process in reverse row order
        for (int j=0;j<n;j++) {
            if (dp[i][j]>0) {
                dp[i][j] += min3(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]);
                ans += dp[i][j];
            }
        }
    }

    cout<<ans<<"\n";
}