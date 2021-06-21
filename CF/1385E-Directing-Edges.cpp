/*
~~~ 1385E - Directing Edges ~~~

Key Concepts: Toposort, DFS

Pretty good problem i should have been able to solve...

Insight 1:
If the directed edges form a cicle -> there is no answer obviously
    we can use a simple dfs to determine if there is a cycle

Insight 2:
Lets look at what happens when we perform a toposort of the nodes (only with directed edges):
    Since there are no cycles -> there exists a toposort of the edges
    If there remains any nodes that are not in the toposort
        we can just add them to the end of the toposort list (it doesn't matter where they are)

    For each undirected edge, we have two choices:
        1. have the edge point from left to right in the toposort 
        2. have the edge ponit from right to left in the toposort
    
    For opt 1: there is no way it will create a cycle
        since a cycle will consists of a node going backwards
    
    For opt 2: it *might* create a cycle
        it is possible, but not certain

    Naturually we should always choose opt 1 to avoid the risk of creating a cycle

    Thus we can just do a simple dfs and find the index of each node
        within the toposort to make sure all edges go from left to right

Time Complexity: O(n+m)

*/


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

int n, m;

vector<ii> graph[MAXN];
int vis[MAXN];
bool isCycle = false;
int order[MAXN]; // order in reverse toposort
int id = 0;
vector<ii> edges;

void dfs(int u) { // find if there is a cycle and toposort
    if (isCycle) return;
    vis[u] = 1;
    for (auto v : graph[u]) {
        if (v.s==1) {
            if (vis[v.f]==0) dfs(v.f);
            if (vis[v.f]==1) isCycle = true;
        }
    }
    vis[u] = 2;
    order[u] = ++id;
}

void solve() {
    cin>>n>>m;

    isCycle = false;
    id = 0;
    fill(vis, vis+n+1, 0);
    fill(graph, graph+n+1, vector<ii>(0));
    fill(order, order+n+1, 0);
    edges.clear();

    int t, u, v;
    for (int i=0;i<m;i++) {
        cin>>t>>u>>v;
        graph[u].push_back({v, t});
        edges.push_back({u, v});        
    }

    for (int i=1;i<=n;i++)
        if (!vis[i]) dfs(i);


    if (isCycle) { // cycle detected
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";
    for (int i=0;i<edges.size();i++) {
        int u = edges[i].f, v = edges[i].s;
        if (order[u] < order[v]) cout<<v<<" "<<u<<endl;
        else cout<<u<<" "<<v<<endl;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        solve();
    }
}