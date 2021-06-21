/*
~~~ VM7WC '15 #4 Gold - Chain Rule ~~~

Key Concepts: Djikstra

Run dijkstras from your starting node  => d2[] and then run djikstra again from the ending node => d1.

The answer is max(d1[i] + d2[i]) for all i in [0..n-1]



*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int MAXN = 1e6 + 5;
const int INF = 1e9;

int n, m;
vector<ii> graph[MAXN];

int dist1[MAXN], dist2[MAXN];
int vis[MAXN];

priority_queue<ii, vector<ii>, greater<ii>> pq;


void djikstra(int src) {
    for (int i=0;i<MAXN;i++) {
        dist1[i] = INF;
        vis[i] = 0;
    }

    while(!pq.empty()) pq.pop();

    dist1[src] = 0;
    pq.push(ii(0, src));

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();

        int d = front.first, u = front.second;

        if (!vis[u]) {
            // if (d > dist1[u]) continue;

            vis[u] = true;
            for (auto e : graph[u]) {
                int v = e.first;
                int w = e.second;

                
                if (!vis[v] && dist1[u] + w < dist1[v]) {
                    dist1[v] = dist1[u] + w;
                    pq.push(ii(dist1[v], v));
                }
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    int u, v, w;
    for (int i=0;i<m;i++) {
        cin>>u>>v>>w;
        graph[u].push_back(ii(v, w));
        graph[v].push_back(ii(u, w));
    }

    djikstra(0);

    for (int i=0;i<n;i++) {
        dist2[i] = dist1[i];
        // cout<<dist1[i]<<"\n";
    }

    djikstra(n-1);

    int ans = 0;

    for (int i=0;i<n;i++) {
        int d = dist2[i] + dist1[i];
        ans = max(ans, d);
    }

    cout<<ans<<"\n";
}