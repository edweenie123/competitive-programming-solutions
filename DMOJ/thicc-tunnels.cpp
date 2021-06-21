/*
~~~ THICC '17 P6 - Tunnels ~~~

Key Concepts: Dynamic Programming, Graph Theory

Combine Save Nagato! and Phonomenal Reviews together

Realize that the shortest dist to visit all the nodes in the tree from node i is:
    
    (2 * sum of all edge weights) - longest path starting from node i

We can calculate the longest path from each node using the same technique as in Save Nagato

*/


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int MAXN = 2e5 + 5;

int n, t, down[MAXN], up[MAXN];
vector<ii> graph[MAXN];
ii par[MAXN];

void dfs_down(int u) {
    for (auto e : graph[u]) {
        int v = e.first, w = e.second;

        if (par[u].first == v) continue;
        
        par[v].first = u;
        par[v].second = w;

        dfs_down(v);
        down[u] = max(down[u], down[v] + w);
    }
}

void dfs_up(int u) {
    // relax the current node's up path (try going up the parent)
    if (u != 1) 
        up[u] = max(up[u], up[par[u].first] + par[u].second);

    // find the child with longest and 2nd longest path down
    int bestD = 0, bestD2 = 0, bestC = -1;
    for (auto e : graph[u]) {
        int v = e.first, w = e.second;

        if (par[u].first == v) continue;
        
        int distSib = down[v] + par[v].second;
        if (distSib > bestD) {
            bestD2 = bestD;
            bestD = distSib;
            bestC = v;
        } else if (distSib > bestD2) {
            bestD2 = distSib;
        }
    }
    

    for (auto e : graph[u]) {
        int v = e.first, w = e.second;
        if (par[u].first == v) continue;

        if (bestC == -1) {
            up[v] = up[u] + w;
        } else if (v != bestC) {
            up[v] = bestD + w;
        } else {
            up[v] = bestD2 + w;
        }

        dfs_up(v);
    }
    

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>t;

    int u, v, w;

    int totWeight = 0;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v>>w;
        // w = 1;
        totWeight += w;
        graph[u].push_back(ii(v ,w));
        graph[v].push_back(ii(u, w));
    }

    dfs_down(1);
    dfs_up(1);

    int maxDist, ans;
    for (int i=1;i<=n;i++) {
        if (graph[i].size()==t) {
            maxDist = max(up[i], down[i]);
            ans = totWeight*2 - maxDist;
            cout<<i<<" "<<ans<<"\n";
        }
    }
}