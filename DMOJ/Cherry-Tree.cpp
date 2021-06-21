/*
~~~ Back to School '16: Cherry Tree ~~~

Key Concepts: DFS, DP

DP[u] stores (#cherries, weight) of the branch if you were to cut the tree at one of u's children
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int MAXN = 1e5 + 1;
int n, c, k, cherries[MAXN], ans = 0;
vector<ii> graph[MAXN];
vector<ii> dp[MAXN]; // (total cherries, totalWeight)

void dfs(int u, int par) {
    for (auto adj : graph[u]) {
        int w = adj.first, v = adj.second;
        if (v==par) continue;
        dfs(v, u);

        int totCherries = cherries[v];
        int totWeight = w;
        for (auto data : dp[v]) {
            totCherries += data.first;
            totWeight += data.second;
        }
        if (totCherries>=c&&totWeight<=k) ans++;
        dp[u].push_back(ii(totCherries, totWeight));
    }
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>c>>k;
    for (int i=1;i<=n;i++) cin>>cherries[i];
    
    int a, b, w;
    for (int i=0;i<n-1;i++) {
        cin>>a>>b>>w;

        graph[a].push_back(ii(w, b));
        graph[b].push_back(ii(w, a));
    }
    dfs(1, 1);
    cout<<ans<<"\n";
}