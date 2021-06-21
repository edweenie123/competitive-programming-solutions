/*
~~~ 1081D - Maximum Distance ~~~

Key Concepts: DSU, DFS

Insight 1: 
If we find the MST of the graph 
    -> it will ensure that the cost between every node is minimized!
        -> this means that path between any nodes in the MST corresponds to the distance!
    
This is just a property of MST (i don't want to think to prove this)

Insight 2:
Since we only care about special vertices, we can find the 
    vertex induced subgraph of the MST using a simple dfs
        (we basically get rid of all the irrelavent vertices in the MST)

Through observation, you can realize that the maximum distance to another special node
    is always equal to the maximum edge weight in the vertex induced subgraph

Therefore, we just print this maximum edge weight k times as the answer!




*/



#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int MAXN = 1e5 + 5;

struct edge {
    int u, v, w;
};

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

bool isSpecial[MAXN];
vector<edge> edges;

int par[MAXN];
int ranks[MAXN];

int root(int k) {
    while (k != par[k])
        k = par[k];
    return k;
}

bool merge(int a, int b) {
    int rootA = root(a), rootB = root(b);
    if (rootA==rootB) return false;

    if (ranks[rootA] < ranks[rootB]) {
        par[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    } else {
        par[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    }

    return true;
}

vector<ii> MST[MAXN];
void kruskal() {
    for (int i=0;i<MAXN;i++) {
        par[i] = i;
        ranks[i] = 1;
    }

    sort(edges.begin(), edges.end(), cmp);

    for (auto e : edges) {
        if (merge(e.u, e.v)) {
            MST[e.u].push_back({e.v, e.w});
            MST[e.v].push_back({e.u, e.w});
        }
    }
}

int maxEdge = 0;

bool dfs(int u, int par) {
    int isGood = false;

    if (isSpecial[u]) isGood = true;
    for (auto adj : MST[u]) {
        int v = adj.first, w = adj.second;
        if (v == par) continue;

        if (dfs(v, u)) {
            maxEdge = max(maxEdge, w);
            isGood = true;
        }
    }

    return isGood;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m, k;

    cin>>n>>m>>k;

    int x;
    for (int i=0;i<k;i++) {
        cin>>x; isSpecial[x] = true;
    }

    int u, v, w;
    for (int i=0;i<m;i++) {
        cin>>u>>v>>w;
        edges.push_back(edge{u, v, w});
    }

    kruskal();
    dfs(x, -1);

    for (int i=0;i<k;i++) {
        cout<<maxEdge<<" ";
    } cout<<"\n";
    
}