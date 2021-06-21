/*
~~~ UVa 11367 - Full Tank ~~~

Key Conepts: Dijkstra, Space-State graph

EXPLANATION REQUIRED
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;

const int MAX = 1e7;

vii graph[1001];
int n, m, prices[1001];
int dist[1001][101];

int dijkstra(int s, int e, int c) {
    for (int i=0;i<1001;i++) for (int j=0;j<101;j++)
        dist[i][j]=MAX;
    
    dist[s][0] = 0;

    priority_queue<iii, vector<iii>, greater<iii>> pq;

    pq.push(iii(0, ii(s, 0)));

    while (!pq.empty()) {
        iii front = pq.top(); pq.pop();

        int d = front.first, u = front.second.first, f = front.second.second;

        // printf("popped <%d,%d,%d>\n", d, u, f);

        if (u == e) return d;

        if (d > dist[u][f]) continue;

        if (f < c) 
            pq.push(iii(d+prices[u], ii(u, f+1))); // buy fuel
        
        for (auto adj : graph[u]) {
            int v = adj.first, w = adj.second;

            if (f >= w && d < dist[v][f-w]) {
                dist[v][f-w] = d;
                pq.push(iii(d,ii(v,f-w)));
            } 
        }
    }

    int ans = MAX;
    for (int i=0;i<=c;i++) 
        ans = min(ans, dist[e][i]);
    
    return ans;
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin>>n>>m;

    for (int i=0;i<n;i++) cin>>prices[i];

    int u, v, d;
    for (int i=0;i<m;i++) {
        cin>>u>>v>>d;
        graph[u].push_back(ii(v,d));
        graph[v].push_back(ii(u,d));
    }

    int q, c, s, e;
    cin>>q;

    while (q--) {
        cin>>c>>s>>e;
        int a = dijkstra(s, e, c);
        cout<<(a==MAX ? "impossible" : to_string(a))<<endl;;
    }
}