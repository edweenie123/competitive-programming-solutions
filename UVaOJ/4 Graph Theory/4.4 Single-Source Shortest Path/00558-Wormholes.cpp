/*
~~~ UVa 558 - Wormholes ~~~

Key Concepts: Bellman Ford's Algorithm

Simply check if negative weight cycle exists using BF's algorithm
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
const int INF = 1e7;
int n, m, dist[1001];
vector<ii> graph[1001];

bool bf() { // returns true if negative cycle exists
    for (int i=0;i<1001;i++) dist[1001] = INF;
    dist[0] = 0;
    for (int i=0;i<n-1;i++) {
        for (int u=0;u<n;u++) {
            for (auto adj : graph[u]) {
                int w = adj.first, v = adj.second;
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    for (int u=0;u<n;u++) { // check if negative cycle exists
        for (auto adj : graph[u]) {
            int w = adj.first, v = adj.second;
            if (dist[u]+w<dist[v]) return true;
        }
    }
    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int TC;
    cin>>TC;
    
    while (TC--) {
        for (int i=0;i<1001;i++) graph[i].clear();

        cin>>n>>m;
        int u, v, t;
        for (int i=0;i<m;i++) {
            cin>>u>>v>>t;
            graph[u].push_back(ii(t, v));
        }
        cout<<(bf() ? "possible" : "not possible")<<endl;
    }
}