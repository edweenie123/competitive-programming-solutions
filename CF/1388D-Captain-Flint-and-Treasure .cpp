/*
~~~ 1388D - Captain Flint and Treasure ~~~

Key Concepts: DFS, Toposort, Greedy

Good problem; im happy i solved this during the contest

Key idea is to model the problem as a directed tree
    -> there is an edge between i and b[i]

Lets look at the leaves of the graph...
    Notice that if you take leaf, its value gets added to its parent

    This is only desirable if the leaf has a positive value...
        cause we want to maximize our answer
    
    In the case that the value is negative...
        -> we should just take the parent first
            that way the negative value does not get propagated
    
    The same logic applies for every node (not just the leaves)

Thus we can perform a simple dfs from the root to find which nodes should get taken first
    -> take nodes that have a positive value in the order we visited them in dfs

The remaining nodes in the tree all have negative values
    To avoid making the remaining values smaller
        -> we take them in reverse toposort order

*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> ii;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

int n;
ll a[MAXN];
ll b[MAXN];

vector<int> graph[MAXN];

bool vis[MAXN];
ll ans = 0;
vector<int> idxs;

set<int> rem;

ll negBoi[MAXN];

ll dfs(int u) {
    vis[u] = true;

    ll more = 0;
    for (auto v : graph[u]) {
        if (vis[v]) continue;

        more += dfs(v);
    }

    ll total = a[u] + more;

    if (total > 0) {
        idxs.push_back(u);
        ans += total;
        rem.erase(u);
        return total;
    }

    negBoi[u] = total;

    return 0;
}

ll topo(int u) {
    vis[u] = true;

    if (rem.count(u)) {
        ans += negBoi[u];
        idxs.push_back(u);
    }

    for (auto v : graph[u]) {
        if (!vis[v]) topo(v);
    }
}



void solve() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        rem.insert(i);
    }

    for (int i=1;i<=n;i++) {
        cin>>b[i];
        if (b[i]!=-1) {
            graph[i].push_back(b[i]);
            graph[b[i]].push_back(i);
        }
    }

    for (int i=1;i<=n;i++) {
        if (b[i]==-1 && !vis[i]) dfs(i);
    }

    for (int i=1;i<=n;i++) {
        vis[i] = false;
    }

    for (int i=1;i<=n;i++) {
        if (b[i]==-1) topo(i);
    }

    cout<<ans<<endl;

    for (auto i : idxs) {
        cout<<i<<" ";
    } cout<<endl;
    
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    solve();
}