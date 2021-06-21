/*
~~~ Bellman Ford's Algorithm ~~~

Solves the SSSP problem - works on weighted graphs with negative weight cycles 

Time Complexity: O(VE) - very slow 


*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
const int MAX_V = 1e4;
const int INF = 1e9;
int V, E;
vector<ii> graph[MAX_V]; // adjacency list format
int dist[MAX_V];

void bellman() {
    memset(dist, INF, sizeof(dist));
    
    for (int i=0;i<V-1;i++) { // do this V-1 times
        for (int u=0;u<V;u++) { // relax all edges
            for (auto j : graph[i]) {
                int v = j.second, w = j.first;
                dist[v] = min(dist[v], dist[u] + w); // relax the distance to v
            }
        }
    }
}

void negativeCycle() {
    // run this after running the normal BF algorithm
    for (int i=0;i<V-1;i++) {
        for (int u=0;u<V;u++) {
            for (auto j : graph[i]) {
                int v = j.second, w = j.first;
                if (dist[u]+w<dist[v])
                    dist[v] = -INF; // set to -INF as it is part of a negative weight cycle
            }
        }
    }
}

void getInput() {
    cin>>V>>E;

    int u, v, w;
    for (int i=0;i<E;i++) {
        cin>>u>>v>>w; // edge u to v with weight w
        graph[u].push_back(ii(v, w));
        graph[v].push_back(ii(u, w));
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    getInput();
    bellman();
    negativeCycle();
}