/*
~~~ CCC '15 S4 - Convex Hull ~~~

Key Concepts: Djikstra

The same thing as classic Djikstra with the added constraint that you have to keep you hull intact!

There are some tricky cases where normal Djikstra will say there is no solution when there really is:

For example:
6 4 4
1 2 2 2
2 3 1 2
1 3 5 3
3 4 1 2
1 4

This is because the route that minimizes distance may damage the hull too much
    - but there exists a less optimal route (takes more time) that leaves the hull intact

Because of this, we need to give the distance array so that:
    dist[i][j] = dist to get to node i with j hull left

We then iterate through all possible values of j to find the minimum amount of time to get to the destination node

*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int MAXN = 2e3 + 5;
const int MAXK = 200 + 5;
const int INF = 1e9;

int k, n, m, src, dest;

int dist[MAXN][MAXK]; // dist[i][j] = dist to get to node i with j hull left

struct edge {
    int time, hCost, vertex; 
};

struct node {
    int totTime, hLeft, vertex;

    friend bool operator<(const node &a, const node &b) {
        return a.totTime > b.totTime;
    }
};

vector<edge> graph[MAXN];
priority_queue<node> pq;

int dijkstra() {
    for (int i=0;i<MAXN;i++) 
        for (int j=0;j<MAXK;j++)
            dist[i][j] = INF;
    

    dist[src][k] = 0;
    pq.push(node{0, k, src});

    while (!pq.empty()) {
        node front = pq.top(); pq.pop();

        int u = front.vertex, hullLeft = front.hLeft, d = front.totTime;

        if (d > dist[u][hullLeft]) continue;

        for (auto e : graph[u]) {
            int t = e.time;
            int h = e.hCost;
            int v = e.vertex;
            int newHullLeft = hullLeft - h;
            int newTime = dist[u][hullLeft] + t;

            if (newHullLeft > 0 && newTime < dist[v][newHullLeft]) {
                dist[v][newHullLeft] = newTime;
                pq.push(node{newTime, newHullLeft, v});
            }
        } 
    }

    int minTime = INF;

    for (int i=1;i<=k;i++) 
        if (dist[dest][i] < minTime) 
            minTime = dist[dest][i];
        
    return (minTime != INF) ? minTime : -1;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>k>>n>>m;

    int u, v, t, h;
    for (int i=0;i<m;i++) {
        cin>>u>>v>>t>>h;
        graph[u].push_back(edge{t, h, v});
        graph[v].push_back(edge{t, h, u});
    }
    cin>>src>>dest;

    int ans = dijkstra();
    cout<<ans<<"\n";
}