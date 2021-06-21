/*
~~~ CCC '16 S3 - Phonomenal Reviews ~~~

Key Concepts: Very high iq, BFS, DFS

This problem requires many insights:

We must first "prune" the tree such that it only contains nodes which are required to visit all the restaurants
    - This is done using a fairly simple DFS alg 

Then we find the diameter of this pruned graph by running BFS twice.

Imagine that we have to return to the starting node:
    In this case, each edge must be visited twice.

Because we don't have to return to the starting node => some edges are traversed twice and some only once

If we maximize the # nodes that are traveled once, we will have the minimum time to visit all restaurants
    * The longest path => diameter of the graph

Thus ans = ( subGraphNodes -1 ) * 2 - diameter

*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int MAX_N = 100001;
int n, m, isPho[MAX_N], badNode[MAX_N], subGraphNodes;
vector<int> graph[MAX_N];

int dist[100001];

bool prune(int u) {
    // cout<<"looking at "<<u<<endl;
    dist[u] = 1;
    bool needed = false;
    for (auto v : graph[u]) {
        if (dist[v]==-1)
            if (prune(v)) needed = true;
    }
    if (isPho[u]) needed = true;
    if (!needed) {badNode[u] = true; subGraphNodes--;}
    return needed;
}

ii BFS(int src) {
    for (int i=0;i<MAX_N;i++) dist[i] = -1;
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    int maxDist = 0, maxDistV;
    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto v : graph[u]) {
            if (!badNode[v]&&dist[v]==-1) {
                dist[v] = dist[u] + 1;
                if (maxDist<dist[v]) {
                    maxDist = dist[v];
                    maxDistV = v;
                }
                q.push(v);
            } 
        }
    }

    return ii(maxDist, maxDistV);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    int p;
    for (int i=0;i<m;i++) {
        cin>>p;
        isPho[p] = true;
    }
    int u, v;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<MAX_N;i++) {dist[i] = -1; badNode[i] = false;}
    subGraphNodes = n;
    prune(p);

    // find the diameter of the graph
    int f = BFS(p).second;
    int diameter = BFS(f).first;
    cout<<2*(subGraphNodes-1) - diameter;
}