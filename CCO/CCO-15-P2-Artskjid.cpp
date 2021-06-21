/*
~~~ CCO '15 P2 - Artskjid ~~~

Key Concepts: Graph Theory, TSP

Apply basically the same algorithm as the 2^n n^2 Travelling Salesman DP solution

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 18 + 1;
const int states = 524288;

int n, m;
int dist[MAXN][MAXN];
int dp[states][MAXN];

int longest(int mask, int pos) {
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    if (pos == n-1)
        return 0;


    int maxDist = -1e9;
    for (int b=0;b<n;b++) {
        int cityMask = 1 << b;
        int overlap = mask & cityMask;
        if (overlap == 0) {
            if (dist[pos][b]==-1) continue;

            int newMask = mask | cityMask;
            int newDist = longest(newMask, b) + dist[pos][b];

            maxDist = max(maxDist, newDist);
        }
    }

    return dp[mask][pos] = maxDist;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    for (int i=0;i<MAXN;i++) for (int j=0;j<MAXN;j++) dist[i][j] = -1;

    int u, v, w;
    for (int i=0;i<m;i++) {
        cin>>u>>v>>w;
        dist[u][v] = w;
    }
    
    for (int i=0;i<states;i++) for (int j=0;j<MAXN;j++) dp[i][j] = -1;

    int ans = longest(1, 0);
    cout<<ans<<"\n";
}