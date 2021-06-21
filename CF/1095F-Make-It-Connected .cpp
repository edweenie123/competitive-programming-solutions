/*
~~~ 1095F - Make It Connected ~~~

Key Concepts: Kruskal's

The problem with the BF approach (add all edges to krukals)
    is that it will TLE and MLE since we have n^2 edges

A problem where you have to simplify the problem first to solve it


Insight 1:
Imagine what the optimal arrangement would be if you didn't have the m special deals
    -> through some observation you realize that this arrangement is just
        node A directly connected with every other node where node A has the cheapest cost
    
        If you arrange the node any other way its either the same total cost or more cost

Insight 2:
With the inclusion of the special deals, how does this change...
    each node can either connect to node A or you can use a special deal 

If we include the n edges from insight 1, and the m edges from insight 2
    and run a kruskal's -> wouldn't that give the optimal answer???

    Intuitively yes and it turns out it works!

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5+5;

struct edge {
    int u, v;
    ll w;
};

bool cmp(edge a, edge b) {
    return a.w<b.w;
}

int n, m;
ll cost[MAXN];
vector<edge> edges;
int par[MAXN], ranks[MAXN];

int root(int k) {
    while (k != par[k]) {
        k = par[k];
    }
    return k;
}

bool merge(int a, int b) {
    int rootA = root(a), rootB = root(b);

    if (rootA==rootB) return false;

    if (ranks[rootA] > ranks[rootB]) {
        par[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    } else {
        par[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    }

    return true;
}

ll kruskals() {
    for (int i=1;i<=n;i++) {
        par[i] = i;
        ranks[i] = 1;
    }

    sort(edges.begin(), edges.end(), cmp);

    ll totCost = 0;

    for (auto e : edges) {
        if (merge(e.u, e.v)) {
            totCost += e.w;
        }
    }

    return totCost;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    ll minNode=-1, minCost=1e15;

    for (int i=1;i<=n;i++) {
        cin>>cost[i];
        if (cost[i]<minCost) {
            minCost=cost[i];
            minNode=i;
        }
    }

    for (int i=1;i<=n;i++) {
        if (i==minNode) continue;
        edges.push_back({i, minNode, cost[i]+minCost});
    }

    ll x, y, w;
    for (int i=0;i<m;i++) {
        cin>>x>>y>>w;
        edges.push_back({x, y, w});
    }

    ll ans = kruskals();
    cout<<ans<<"\n";
}