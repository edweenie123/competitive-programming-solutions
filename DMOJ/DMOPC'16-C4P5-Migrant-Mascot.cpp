/*
~~~ DMOPC '16 Contest 4 P5 - Migrant Mascot ~~~

Key Concepts: Minimax problem

Fairly simple minimax problem
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
const int INF = 1e9;
const int MAXN = 2e5 + 5;

int n, m, par[MAXN], ranks[MAXN], dist[MAXN];
vector<iii> edges;
vector<ii> MST[MAXN];

int root(int i) {
    while (i!=par[i]) {
        i = par[i];
    }
    return i;
}

void merge(int a, int b, int p) {
    int rootA = root(a), rootB = root(b);

    if (rootA==rootB) return;

    MST[a].push_back(ii(p, b));
    MST[b].push_back(ii(p, a));

    if (ranks[rootA]<ranks[rootB]) {
        par[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    } else {
        par[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
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
    sort(edges.begin(), edges.end(), greater<>());

    for (auto e : edges) {
        merge(e.second.first, e.second.second, e.first);
    }
}

void dfs(int u, int p, int minP) {
    for (auto adj : MST[u]) {
        int pVal = adj.first, v = adj.second;
        if (v==p) continue;
        dist[v] = min(minP, pVal);
        dfs(v, u, dist[v]);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    int a, b, p;
    for (int i=0;i<m;i++) {
        cin>>a>>b>>p;
        edges.push_back(iii(p, ii(a, b)));
    }

    kruskal();

    dist[1] = 0;
    dfs(1, 1, INF);

    for (int i=1;i<=n;i++) cout<<dist[i]<<"\n";
}