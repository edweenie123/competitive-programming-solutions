/*
~~~ Kruskal's Minimum Spanning Tree Algorithm ~~~

- Overview -
Time Complexity: O(Elog(E)) - E = # of edges
Finds a MST of a graph using a greedy algorithm

- Idea - 

1. Edges sorted by their weight in increasing order
2. One by one the edges are added to the disjoint set data structure
    a) if no cycle is found, the edges is part of the MST
    b) if a cycle is found (same root), the edge is not part of MST; move on
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pipii;

int N, M; // #vertices, #edges
int par[100000], ranks[100000];
pipii edges[100000]; // (weight, (source, dest))

pair<int, pair<int, int>> edges;


int root(int i) {
    while (i != par[i]) 
        i = par[i];
    return i;
}

bool merge(int a, int b) { // returns true if no cycle is formed
    int rootA = root(a), rootB = root(b);

    if (rootA==rootB) return false; // leads to cycle!

    if (ranks[rootA]<rootB) {
        par[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    } else {
        par[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    }
    return true;
}

void init() {
    for (int i=0;i<N;i++) {
        par[i] = i;
        ranks[i] = 1;
    }
}

int kruskal() {
    init();
    sort(edges, edges+M); // sort edges in non-decreasing order

    int weightSum = 0;

    for (int i=0;i<M;i++) {
        pipii e = edges[i];
        int u=e.second.first, v=e.second.second, w=e.first;
        if (merge(u, v)) 
            weightSum += w;
    }

    return weightSum;
}

int main() {
    cin>>N>>M;
    int u, v, w; // src, dst, weight;
    for (int i=0;i<M;i++) { // parse input
        cin>>u>>v>>w;
        edges[i] = make_pair(w, make_pair(u, v)); 
    }

    cout<<kruskal(); // total weight of MST
}