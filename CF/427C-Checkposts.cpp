/*
~~~ 427C - Checkposts ~~~

Key Concepts: Tarjan's algorithm

Basically a template SCC problem

Insight 1:
Consider all the nodes that you would cover if you put a police boi on node u
    -> if you think about it, all of these nodes make up a SCC

Therefore at minimum, we need to up a police boi in each SCC

This problem then reduces to finding the min cost police boi in each SCC


*/



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

int n, cost[MAXN];
int m;
vector<int> graph[MAXN];
vector<vector<int>> sccCosts;

int ids[MAXN], low[MAXN], onStack[MAXN], id = 0;
stack<int> s;

void dfs(int u) {
    ids[u] = low[u] = id++;
    s.push(u);
    onStack[u] = 1;

    for (auto v : graph[u]) {
        if (ids[v] == -1)
            dfs(v);

        if (onStack[v])
            low[u] = min(low[u], low[v]);
    }

    if (ids[u] == low[u]) {
        vector<int> costs;
        while (true) {
            int v = s.top(); s.pop();
            onStack[v] = 0;

            costs.push_back(cost[v]);
            if (v==u) break;
        }
        sccCosts.push_back(costs);
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=1;i<=n;i++) cin>>cost[i];

    cin>>m;
    int u, v;
    for (int i=0;i<m;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
    }

    for (int i=0;i<MAXN;i++) ids[i] = -1;

    for (int i=1;i<=n;i++) 
        if (ids[i] == -1)
            dfs(i);
    
    ll minCost=0, ways=1;

    for (auto scc : sccCosts) {
        sort(scc.begin(), scc.end());

        ll minVal = scc.front();
        ll cnt = 0;

        for (auto c : scc)
            if (c == minVal)
                cnt++;
            
        minCost += minVal;
        ways = (ways * cnt) % MOD;
    }

    cout<<minCost<<" "<<ways<<"\n";
}