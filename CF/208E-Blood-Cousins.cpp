/*
~~~ 208E - Blood Cousins ~~~

Key Concepts: Binary Lifting, Tree flattening (Euler Tour), DFS

Pretty intresting problem which uses a lot of cool tricks

Insight 1:
Query: (v, p)

Let x be the p'th parent of v

For a node u to be blood cousins with v, two conditions must be satisfied

    1) u must have the same depth as v (from the root)
    2) x must be an ancestor of v

Think about this boi and it will make sense

Insight 2:
We can find x quickly using binary lifting

and

We can check the first condition quickly having an array depthNodes
    where depthNodes[i] returns a vector of all nodes with a depth of i
        -> use dfs

The issue now is checking if x is an ancestor of v

    Watch SecondTread's tree video for a better understanding

    We can do this by flattening the tree...

    let tin[i] be the time when you visit node i
        tout[i] be the time when you exit node i

    increment the timer everytime you go DOWN an edge

    We renumber all the node i's id to be tin[i]

    now if node u is id between tin[x] and tout[x]
        we know u is in the subtree of x
            x is ancestor!!!

    We can use a pretty simple binary serach to find the number of nodes

        that have an id that is between the range tin[x] and tout[x]


*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 1e5 + 5;
const int LOG = 20;
const ll MOD = 1e9 + 7;

int n, m;
vector<int> graph[MAXN];
vector<int> depthNodes[MAXN]; // vector of nodes with a certain depth
int depth[MAXN];


int tin[MAXN], tout[MAXN];
int rangeEnd[MAXN];

int up[MAXN][LOG];
int dfsTimer = 1;

void dfsLift(int u, int par) {
    up[tin[u]][0] = tin[par];

    for (int i=1;i<LOG;i++) {
        int halfUp = up[tin[u]][i-1];
        up[tin[u]][i] = up[halfUp][i-1];
    }

    for (auto v : graph[u]) 
        dfsLift(v, u);
}

void dfs(int u, int d=0) {
    tin[u] = dfsTimer;

    depthNodes[d].push_back(tin[u]); // pushback the renumbered value
    depth[tin[u]] = d;

    for (auto v : graph[u]) {
        dfsTimer++; // only increment dfs timer when you go down an edge
        dfs(v, d+1);
    }

    rangeEnd[tin[u]] = dfsTimer;
    tout[u] = dfsTimer;
}

int kthAncestor(int u, int k) {
    for (int i=LOG-1;i>=0;i--) {

        if ((1<<i) & k) 
            u = up[u][i];
    }

    return u;
}

int findNumCousin(int v, int p) {

    int pParent = kthAncestor(tin[v], p);

    if (pParent == 0) return 0;

    int reqDepth = depth[pParent] + p;


    int lo = pParent, hi = rangeEnd[pParent];

    auto lessHigh = prev(upper_bound(all(depthNodes[reqDepth]), hi));
    auto lessLo = lower_bound(all(depthNodes[reqDepth]), lo);

    int ans = lessHigh - lessLo;

    return ans;
}

vector<int> roots;

void solve() {
    cin>>n;

    int par, root=-1;

    for (int i=1;i<=n;i++) {
        cin>>par;
        graph[par].push_back(i);

        if (par==0) roots.push_back(i);
    }

    for (auto r : roots) {
        dfs(r);
        dfsLift(r, 0);

        dfsTimer++;
    }

    for (int i=0;i<MAXN;i++) sort(depthNodes[i].begin(), depthNodes[i].end());

    cin>>m;
    int v, p;
    while (m--) {
        cin>>v>>p;

        int ans = findNumCousin(v, p);
        cout<<ans<<" ";
    } cout<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); 
    solve();
}