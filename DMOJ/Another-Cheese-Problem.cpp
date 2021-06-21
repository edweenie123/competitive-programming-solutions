/*
~~~ Another Contest 5 Problem 5 - Another Cheese Problem ~~~

Key Concepts: Graph Theory, Dynamic Programming

let dp[i] = # of bowls needed to get to operation i

Through oberservation, we notice that:
    if i is a leaf -> dp[i] = k + 1                                     where k = # of children of i
    else           -> dp[i] = max(k+1, dp[dp[xj] + i]) for j = 0 -> k-1 where xj = child j of i (sorted in increasing bowl order)   
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+1;
int n;
vector<int> tree[MAXN];
int dp[MAXN];

void dfs(int u) {
    // printf("looking at %d\n", u);
    int numC = 0;
    vector<int> cBowls;
    for (int c : tree[u]) {
        dfs(c);
        numC++;
        cBowls.push_back(dp[c]);
    }

    sort(cBowls.begin(), cBowls.end(), greater<>());
    dp[u] = numC + 1;

    for (int i=0;i<cBowls.size();i++) {
        dp[u] = max(dp[u], cBowls[i] + i);
    }
    // printf("%d -> bowls needed %d\n", u, dp[u]);   
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    cin>>n;
    int v = 2, u;
    for (int i=0;i<n-1;i++) {
        cin>>u;
        tree[u].push_back(v);
        v++;
    }

    dfs(1);
    cout<<dp[1]<<"\n";
}