/*
~~~ Dijkstra's Algorithm ~~~

Solves the "single-source shortest path" (SSSP)
    - Finds the minimum distance to every vertex in a weighted graph

Time Complexity: O((V+E) * log V)
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
const int MAX = 1e6;

int dist[MAX]; // distance to every vertex
int vis[MAX];
vii graph[MAX]; // adjacency list
priority_queue<ii, vector<ii>, greater<ii>> pq; // priority queue (dist from source, vertex num)

int N, M; // # vertices, # edges

void dijkstra(int src) {
    for (int i=0;i<MAX;i++) dist[i]=MAX;

    dist[src] = 0;

    pq.push(ii(0, src)); // enqueue source vertex

    while (!pq.empty()) {

        ii front = pq.top(); pq.pop();

        int d = front.first, u = front.second;

        // if (d > dist[u]) continue; // ignore u 

        if (!vis[u]) {
            vis[u] = true;
            for (auto e : graph[u]) { // for each neighbor relax it and enqueue it
                int v = e.first;
                int w = e.second;
                if (!vis[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push(ii(dist[v], v));
                }
            }
        }
    }
}

void getInput() {
    cin>>N>>M;

    int u, v, w;
    for (int i=0;i<M;i++) {
        cin>>u>>v>>w; // edge u to v with weight w
        graph[u].push_back(ii(v, w));
        graph[v].push_back(ii(u, w));
    }
}

int main () {
    // freopen("input.txt", "r", stdin);
    
    getInput();
    dijkstra(0);

    for (int i=1;i<=N;i++) // print dist to every vertex
        cout<<(dist[i]==MAX ? -1 : dist[i])<<endl;
    
}