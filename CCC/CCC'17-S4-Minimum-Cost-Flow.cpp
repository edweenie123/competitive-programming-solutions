/*
~~~ CCC '17 S4 - Minimum Cost Flow ~~~

Key Concepts: High IQ, MST - Kruskal's 

Let's assumme D = 0, for now.

Clearly, we want to find the MST of the graph
    - However, we want to choose the MST which maximizes the # of original edges (to minimize # of days)
        => therefore, when we sort the edges, we break ties by whether it is an original edge or not
           In this way, we maximize the # of edges in the MST that are original edges
    After this process, the # of days, is simply the # of new edges that are in the generated MST



*/

#include<bits/stdc++.h>
using namespace std;

#define PB push_back
const int MAXN = 1e5 + 1;

int n, m, d;

int ranks[MAXN], par[MAXN];

struct edge {
    int u, v, w, isInactive;
    bool operator<(const edge &e)const {
        if (w==e.w) 
            return isInactive<e.isInactive;
        return w<e.w;
    }
};

vector<edge> edges; 

int root(int i) { // path compression??
    while (i != par[i]) {
        par[i] = par[par[i]];
        i = par[i];
    }
    return i;
}

void merge(int A, int B) { 
    int rootA = root(A), rootB = root(B);

    if (ranks[rootA] > ranks[rootB]) {
        par[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    } else {
        par[rootA] = rootB;
        ranks[rootB] += ranks[rootB];
    }
}

void initDSU() {
    for (int i=0;i<MAXN;i++) {
        ranks[i] = 1;
        par[i] = i;
    }
}

int kruskals() {
    initDSU();

    sort(edges.begin(), edges.end());
    int days = 0;

    int maxWeight = 0;
    for (auto e : edges) {
        int w = e.w, isInactive = e.isInactive, u = e.u, v = e.v;
        
        if (root(u)!=root(v)) {
            merge(u, v);
            if (isInactive) days++;
            maxWeight = max(maxWeight, w);
        }
    }

    initDSU();
    for (auto e : edges) {
        int w = e.w, isInactive = e.isInactive, u = e.u, v = e.v;

        if (root(u) != root(v)) {
            if (w < maxWeight || (w==maxWeight && !isInactive)) { // important line
                merge(u, v);
            } else if (w<=d && !isInactive) {
                days--;
                break;
            }
        }
    }

    return days;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>d;
    
    int a, b, c;
    for (int i=0;i<m;i++) {
        cin>>a>>b>>c;
        
        if (i<n-1) edges.PB(edge{a, b, c , 0}); // original edge
        else       edges.PB(edge{a, b, c, 1}); // inactive edge
    }

    int days = kruskals();
    cout<<days<<"\n";
}