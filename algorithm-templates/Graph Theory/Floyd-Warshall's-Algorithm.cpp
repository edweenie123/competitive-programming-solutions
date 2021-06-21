/*
~~~ Floyd Warshall's APSP Algorithm ~~~

Time Complexity: O(V^3)


*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
const int INF = 1e7;
const int MAX_V = 400;
int V, E;
int dist[MAX_V][MAX_V]; // adjacency matrix format

void fw() {
    for (int k=0;k<V;k++) 
        for (int i=0;i<V;i++)
            for (int j=0;j<V;j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}

void getInput() {
    for (int i=0;i<MAX_V;i++) for (int j=0;j<MAX_V;j++) i==j ? dist[i][j] = 0 : dist[i][j] = INF;

    cin>>V>>E;
    int w, u, v; 
    for (int i=0;i<E;i++) {
        cin>>w>>u>>v;
        dist[u][v] = w;
        dist[v][u] = w;
    }
}

int main() {
    getInput();
    fw();
}