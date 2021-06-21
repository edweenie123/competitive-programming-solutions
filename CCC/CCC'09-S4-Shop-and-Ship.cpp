/*
~~~ CCC '09 S4 - Shop and Ship ~~~

Key Concepts: Dijkstra's Algorithm

The key insight is the run dijkstra (once) from the destination city instead of k times from each store

After the distance to each store is found, find min(dist[store] + cost of pencil) for all stores
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int MAX_N = 5001;
const int INF = 1e8;
int n, t, src, dist[MAX_N];
vector<ii> stores;
vector<ii> graph[MAX_N];

int dijkstra(int s) {
    for (int i=0;i<MAX_N;i++) dist[i] = INF;
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    pq.push(ii(0, s));
    dist[s] = 0;

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int u = front.second, d = front.first;
        if (d>dist[u]) continue;

        for (auto adj : graph[u]) {
            int v = adj.second, w = adj.first;
            if (dist[u]+w<dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(ii(dist[v], v));
            }
        }
    }

    int minCost = INF;

    for (auto st : stores) {
        int c = st.first, u = st.second;
        minCost = min(minCost, dist[u] + c);
    }
    return minCost;
}   

int main() {
    // freopen("input.txt", "r", stdin);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>t;
    int u, v, w;
    for (int i=0;i<t;i++) {
        cin>>u>>v>>w;
        graph[u].push_back(ii(w, v));
        graph[v].push_back(ii(w, u));
    }
    int k, z, pz;
    cin>>k;
    for (int i=0;i<k;i++) {
        cin>>z>>pz;
        stores.push_back(ii(pz, z));
    }
    
    cin>>src;

    cout<<dijkstra(src)<<endl;
}