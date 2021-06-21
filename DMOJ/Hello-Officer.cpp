/*
~~~ VM7WC '16 #3 Gold - Hello, Officer. ~~~ 

Key Concepts: Dijkstra

Very simple Dijkstra implementation
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int MAXN = 2001;
const int INF = 1e8;
int n, m, b, q, dist[MAXN];
vector<ii> graph[MAXN];

void dijkstra() {
    for (int i=0;i<MAXN;i++) dist[i] = INF;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[b] = 0; 
    pq.push(ii(0, b));

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop(); 
        int d = front.first, u = front.second;
        if (d>dist[u]) continue;

        for (auto adj : graph[u]) {
            int w = adj.first, v = adj.second;
            if (dist[u]+w>dist[v]) continue;
            
            dist[v] = dist[u] + w;
            pq.push(ii(dist[v], v));
        }
    }

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>b>>q;

    int x, y, z;
    for (int i=0;i<m;i++) {
        cin>>x>>y>>z;
        graph[x].push_back(ii(z, y));
        graph[y].push_back(ii(z, x));
    }

    dijkstra();

    int a;
    for (int i=0;i<q;i++) {
        cin>>a;
        cout<<(dist[a]!=INF ? dist[a] : -1)<<"\n";
    }
}