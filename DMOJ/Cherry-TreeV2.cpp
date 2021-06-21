#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define F first
#define S second
#define PB push_back

const int MAXN = 1e4+1; 

int n, c, k;
int cherries[MAXN];
vector<ii> graph[MAXN];
ii dp[MAXN]; // (cherry, weight)

int ans = 0;
void dfs(int u, int par) {
    for (auto adj : graph[u]) {
        int v = adj.F, w = adj.S;
        if (v==par) continue;
        dfs(v, u);

        if (dp[v].F>=c && dp[v].S + w <= k) 
            ans++;
        
        dp[u].F += dp[v].F;
        dp[u].S += dp[v].S + w;
    }
    dp[u].F += cherries[u];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>n>>c>>k;

    for (int i=1;i<=n;i++) {
        cin>>cherries[i];
    }

    int a, b, w;    
    for (int i=0;i<n-1;i++) {
        cin>>a>>b>>w;
        graph[a].PB(ii{b, w});
        graph[b].PB(ii{a, w});
    }

    dfs(1, 1);
    cout<<ans<<"\n";
}