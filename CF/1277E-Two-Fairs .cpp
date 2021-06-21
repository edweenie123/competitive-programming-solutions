/*
~~~ 1277E - Two Fairs ~~~

Key Concepts: Graph Theory

A lot easier than it seems; its very easy to overcomplicate this

This main insight is to understand what would happen if you deleted either A or B

Lets look at a possible path (x, y)

In order to get from x -> y: x -> a -> b -> y

Step 1
Consider what happens when you delete node B and run a dfs from A
    -> all the nodes that you can't reach are the nodes  (k of these)
        that require node B if you start at node A
        (any path from A to one of these nodes includes B)


Step 2
Conversely delete node A and run a dfs from B
    -> all the nodes that you can can't reach are the nodes (g of these)
        that require A if you start at node B

        (any path from B to one of these nodes includes A)

Lets start at node A and choose a node Y
    -> we can choose any node in step 1 (since it will always include B)

Now lets choose a node X
    -> we can choose any node in step 2 (since the only way to access these nodes is through A)

Those we have k options for node Y
and g options for node X

Therefore the answer is k*g

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;

vector<int> graph[MAXN];
bool vis[MAXN];

int compSize = 0;

void dfs(int u, int exclude) {
    compSize++;

    for (auto v : graph[u]) {
        if (vis[v] || v==exclude) continue;

        vis[v] = true;
        dfs(v, exclude);
    }
}

ll solve() {
    int n, m, a, b;
    cin>>n>>m>>a>>b;

    for (int i=0;i<=n;i++) graph[i].clear();

    int u, v;
    for (int i=0;i<m;i++) {
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);

    }

    for (int i=0;i<=n;i++) vis[i] = 0;

    compSize = 0;
    dfs(a, b);
    ll aComp = compSize;
    
    for (int i=0;i<=n;i++) vis[i] = 0;

    compSize = 0;
    dfs(b, a);
    ll bComp = compSize;

    // cout<<aComp<<" "<<bComp<<" bruh \n";
    ll ans = (n-aComp) * (n-bComp);

    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        ll ans = solve();
        cout<<ans<<"\n";
    }
}
