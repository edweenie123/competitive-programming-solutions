/*
~~~ DMOPC '19 Contest 2 P2 - Squares ~~~

Key Concepts: DP

Very simple DP

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 501;

int n, m;
int grid[MAXN][MAXN];
int dp[MAXN][MAXN];

int minCost(int x, int y) {
    if (dp[x][y]!=-1) return dp[x][y];
    if (x==n&&y==m)
        return grid[x][y];

    if (x==n) 
        return dp[x][y] = minCost(x, y+1) + grid[x][y];
    else if (y==m)
        return dp[x][y] = minCost(x+1, y) + grid[x][y];
    else {
        int down = minCost(x+1, y) + grid[x][y];
        int right = minCost(x, y+1) + grid[x][y];

        return dp[x][y] = min(down, right);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) 
        for (int j=1;j<=m;j++) 
            cin>>grid[i][j];
        
    
    
    memset(dp, -1, sizeof(dp));

    int ans = minCost(1, 1);
    cout<<ans<<"\n";
}