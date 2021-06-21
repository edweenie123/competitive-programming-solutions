/*
~~~ COCI '14 Contest 4 #4 Mravi ~~~

Key Concepts: Graph Theory + DP

dfs(i) returns the minimun amount of water if the pipe system was rooted at vertex i


*/
#include<bits/stdc++.h>
using namespace std;

struct edge {
    int v, xi, ti;
};
const int MAXN = 1001;
vector<edge> graph[1001]; // (v, xi, ti)
int n, antReq[1001];

float dfs(int u, int par) {
    // printf("looking at %d\n", u);
    if (antReq[u]!=-1) return antReq[u];

    float ans = 0;
    for (auto adj : graph[u]) {
        int v = adj.v, per = adj.xi, super = adj.ti;
        if (v==par) continue;

        float childMin = dfs(v, u);
        if (super==1) childMin = min(childMin, sqrt(childMin));

        ans = max(ans, childMin*100/(float)per);
    }

    return ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    int u, v, xi, ti;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v>>xi>>ti;
        graph[u].push_back((edge){v, xi, ti});
        graph[v].push_back((edge){u, xi, ti});
    }

    for (int i=1;i<=n;i++) cin>>antReq[i];
    cout<<dfs(1, 1)<<endl;
}