/*
~~~ 609E - Minimum Spanning Tree for Each Edge ~~~

Key Concepts: Kruskals, Binary Lifting

Very thicc problem

Insight 1:
Lets find the MST of the graph using Kruskals -> weight sum = x
    -> any edge within this MST should output x

Insight 2:
Let us consider any other edge not in the MST now (u, v)
    -> if we add this edge to the MST, it will create a cycle

        Therefore, if we want to include this edge
            we must delete an edge in the MST such that the cycle goes away
    
    Through some insights, you realize that the edge we can delete
        is any edge on the path from u to v (on the MST)
    
    Since we want the MST, we want to find the heavest edge on the path from u to v
        and replace it with the new edge (u, v)

Insight 3:
We can find the heaviest edge between two nodes in tree using binary lifting!!
    -> we store two binary lifting arrays
        1. up[i][j] = 2**j'th parent of i
        2. me[i][j] = maxEdge on path from i to 2**j'th parent

Let lca = lca(u, v) -> find this using the up array

The max edge from to u to v is tho
    the max(maxEdge from u to lca, maxEdge from v to lca)
        which we can find using the me array
*/



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 2e5 + 5;
const int MAXL = 20;
const ll MOD = 1e9 + 7;

struct edge {
    int u, v, w, id;

    friend bool operator<(const edge &a, const edge &b) {
        return a.w < b.w;
    }
};

int n, m;
vector<ii> mst[MAXN];
vector<edge> edges;
bool usedInMST[MAXN];
ll ans[MAXN];

// ------------ Kruskals Stuff ------------
int sz[MAXN], par[MAXN];
int root(int k) {
    while (k!=par[k]) 
        k = par[k];
    return k;
}

bool merge(int a, int b) {
    int rootA = root(a), rootB = root(b);

    if (rootA == rootB) return false;

    if (sz[rootA] > sz[rootB]) {
        par[rootB] = rootA;
        sz[rootA] += sz[rootB];
    } else {
        par[rootA] = rootB;
        sz[rootB] += sz[rootA];
    }

    return true;
}

ll mstSum = 0;
void kruskal() {
    for (int i=0;i<MAXN;i++) {
        sz[i] = 1;
        par[i] = i;
    }

    sort(edges.begin(), edges.end());

    for (auto e : edges) {
        if (merge(e.u, e.v)) {
            mstSum += e.w;

            // flag this edge as being used in the MST
            usedInMST[e.id] = true;

            // add edge to mst
            mst[e.u].push_back({e.v, e.w});
            mst[e.v].push_back({e.u, e.w});
        }
    }
}
// ------------ Kruskals Stuff ------------

// ------------ Binary Lifting Stuff ------------
int up[MAXN][MAXL]; // up[i][j] = 2**j'th parent of i
int maxEdge[MAXN][MAXL]; // me[i][j] = maxEdge on path from i to 2**j'th parent

int tin[MAXN], tout[MAXN];
int dfsTimer = 0;

void dfs(int u, int par, int w) {
    tin[u] = dfsTimer++;

    up[u][0] = par;
    maxEdge[u][0] = w;

    for (int i=1;i<MAXL;i++) {
        int halfUp = up[u][i-1];
        int halfMaxUp = maxEdge[u][i-1];

        up[u][i] = up[halfUp][i-1];
        maxEdge[u][i] = max(halfMaxUp, maxEdge[halfUp][i-1]);
    }

    for (auto adj : mst[u]) 
        if (adj.fi!=par) dfs(adj.fi, u, adj.se);
    
    tout[u] = dfsTimer++;
}

bool isAncestor(int a, int c) {
    return tin[a] <= tin[c] && tout[a] >= tout[c];
}

bool isAbove(int a, int c) {
    return tin[a] < tin[c] && tout[a] > tout[c];
}

int findLCA(int x, int y) {

    if (isAncestor(x, y)) return x;
    if (isAncestor(y, x)) return y;

    for (int i=MAXL-1;i>=0;i--) {

        int goUp = up[x][i];

        if (!isAncestor(goUp, y) && goUp != 0)
            x = goUp;
    }

    return up[x][0];
}

// y is ancestor x
int findMaxEdge(int x, int y) {

    int maxSoFar = 0;

    for (int i=MAXL-1;i>=0;i--) {

        int goUp = up[x][i];

        if (goUp == 0 || isAbove(goUp, y)) continue;

        maxSoFar = max(maxSoFar, maxEdge[x][i]);
        x = goUp;
    }

    return maxSoFar;
}
// ------------ Binary Lifting Stuff ------------

void solve() {
    cin>>n>>m;

    int u, v, w;

    int id = 1;
    for (int i=0;i<m;i++) {
        cin>>u>>v>>w;
        edges.push_back(edge{u, v, w, id++});
    }

    kruskal();
    dfs(1, 0, 0);

    // iterate through all edges
    for (auto e : edges) {
        if (usedInMST[e.id]) ans[e.id] = mstSum;
        else {


            int lca = findLCA(e.u, e.v);

            int side1Max = findMaxEdge(e.u, lca);
            int side2Max = findMaxEdge(e.v, lca);
            int heaviest = max(side1Max, side2Max);

            ll bestMST = mstSum - heaviest + e.w;

            ans[e.id] = bestMST;
        }
    }

    for (int i=1;i<=m;i++) cout<<ans[i]<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); 
    solve();
}