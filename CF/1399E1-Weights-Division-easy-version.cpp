/*
~~~ 1399E1 - Weights Division (easy version) ~~~

Key Concepts: DP, DFS, Greedy, Multiset 

The idea is pretty simple, but implementation is kinda difficult

Let sumCost = the sum of the paths from the root to all leaves

The most obvious thing to do is to understand how an operation of edge e affects sumCost
    -> an operation on edge e does this:
        sumCost := sumCost - (l * w - w/2)

    Where l is the number of leaves that use edge e and w is the weight of the edge

    This is pretty ez to figure out

You can compute the l values for every edge using a pretty simple dp + dfs
    
Once you know all of this, the greedy idea should come pretty intuitively
    -> we just continously perform the operation on the best edge
        (the edge with the largest (l * w - w/2) value)

    We can do this quickly using a multiset

*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> ii;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

vector<ii> graph[MAXN];
ll leaves[MAXN];
ll weight[MAXN];

struct edge {
    ll l; // leaves that use this
    ll w; // weight of edge
};

ll saveAmt(edge a) {
    return a.l * (a.w - a.w/2);;
}

struct cmp {
    bool operator() (edge const &a, edge const & b) {
        ll valA = saveAmt(a);
        ll valB = saveAmt(b);

        return valA > valB;
    }
};

multiset<edge, cmp> allEdges;

ll sumCost = 0;

void dfs(int u, int par, ll dist) {
    if (graph[u].size()==1 && u!=1) {
        leaves[u] = 1;
        weight[u] = graph[u][0].se;
        sumCost += dist;
        return;
    }

    ll sumChild = 0;

    for (auto [v, w] : graph[u]) {
        if (v == par) continue;

        dfs(v, u, dist+w);

        weight[v] = w;
        sumChild += leaves[v];
    }

    leaves[u] = sumChild;
}


void solve() {
    ll n, s;
    cin>>n>>s;

    // reset all the bois
    for (int i=0;i<=n+5;i++) {
        graph[i].clear();
        leaves[i] = 0;
        weight[i] = 0;
    }

    sumCost = 0;
    allEdges.clear();

    int x, y, w;
    for (int i=0;i<n-1;i++) {
        cin>>x>>y>>w;

        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    dfs(1, 0, 0);

    for (int i=1;i<=n;i++) {
        allEdges.insert(edge{leaves[i], weight[i]});
    }

    ll ans = 0;

    while (true) {
        if (sumCost <= s) break;

        auto bestEdge = allEdges.begin();
        ll save = saveAmt(*bestEdge);

        sumCost -= save;
        ++ans;

        edge newEdge = edge{(*bestEdge).l, (*bestEdge).w / 2};
        allEdges.erase(bestEdge);
        allEdges.insert(newEdge);
    }

    cout<<ans<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) 
        solve();
}
