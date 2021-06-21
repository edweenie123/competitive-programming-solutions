/*
~~~ Disjoint Set Test ~~~

Key Concepts: Kruskal's MST Algorithm

Trivial Implementation of Kruskal's MST algorithm to find the edges of the MST

Note: The MST doesn't exist if the # of edges in the MST != n-1
*/

#include<bits/stdc++.h>

using namespace std;

int n, m, par[100005], ranks[100005];
vector<pair<int, int>> edges;
vector<int> mstEdges;

int root(int i) {
    while (i!=par[i]) {
        par[i] = par[par[i]];
        i = par[i];
    }
    return i;
}

void merge(int a, int b) { 
    if (ranks[a]>ranks[b]) {
        par[a] = b;
        ranks[a] += ranks[b];
    } else {
        par[a] = b;
        ranks[b] += ranks[a];
    }
}

void init() {
    for (int i=1;i<=n;i++) {
        par[i] = i;
        ranks[i] = 1;
    }
}

void kruskal() {
    init();
    for (int i=0;i<edges.size();i++) {
        
        int rootA = root(edges[i].first), rootB = root(edges[i].second);
        if (rootA!=rootB) {
            merge(rootA, rootB);
            mstEdges.push_back(i+1);
        } 
        
    }
}

void output() {    
    if (mstEdges.size()!=n-1) {
        cout<<"Disconnected Graph";
        return;
    }

    for (auto e : mstEdges) 
        cout<<e<<endl;
}

int main() {
    cin>>n>>m;

    int u, v;
    for (int i=0;i<m;i++) {
        cin>>u>>v;
        edges.push_back(make_pair(u, v));
    }

    kruskal();
    output();
}