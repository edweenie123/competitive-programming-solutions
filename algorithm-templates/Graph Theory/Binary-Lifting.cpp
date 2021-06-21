/*
~~~ Binary-Lifting ~~~

Cool trick which can be used to... (ONLY works for trees!!)
    Find the k'th ancestor of any node in (log n)
    Find the LCA of 2 nodes in O(log n)

    Find the distance between any two nodes
        dist(x, y) = depth(x) + depth(y) - 2*depth(LCA(x, y))

    Find the max edge / node weight on the path between any two nodes

Note: If the tree isn't already rooted, you can arbitrarily root it at any node

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, q; // number of nodes and queries respectively
vector<int> graph[MAXN];
int tin[MAXN]; // timer when you go into a node
int tout[MAXN]; // time when you get out of a node (done dfs calls)
int up[MAXN][25]; // up[x][i] returns the 2**i'th ancestor of node x

int dfsTimer = 1;

void dfs(int u, int par) {

    tin[u] = dfsTimer++;

    // generate the up array for this node
    // you can do this since all up arrays ancestors have already been generated
    
    up[u][0] = par;

    for (int i=1;i<=20;i++) {
        int halfUp = up[u][i-1];
        up[u][i] = up[up[u][i-1]][i-1];
    }

    for (auto v : graph[u])
        if (v != par) dfs(v, u);

    tout[u] = dfsTimer++;
}

// returns true if a is an ancestor of c
// if a==c -> it still counts as ancestor apparently
// this makes sense if you think about it for a bit
bool isAncestor(int a, int c) {
    return tin[a] <= tin[c] && tout[a] >= tout[c];
}

int findLCA(int x, int y) {

    // case lca is x or y
    if (isAncestor(x, y)) return x;
    if (isAncestor(y, x)) return y;

    // general case
    // find the highest ancestor of x that is also not an ancestor of y -> boi
    // the lca is thus the parent of boi -> up[boi][0]

    for (int i=20;i>=0;i--) {

        int goUp = up[x][i];

        // if goUp == 0 that means we went beyond the root
        if (!isAncestor(goUp, y) && goUp != 0)
            x = goUp;
    }

    return up[x][0];
}

int main() {
    cin>>n;

    // get edges of tree
    int u, v;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // generate the up array
    dfs(1, 0); // root the tree at node 1

    cin>>q;
    int x, y; // find lca of x and y
    while (q--) {
        cin>>x>>y;

        int ans = findLCA(x, y);
        cout<<"The lca is "<<ans<<"\n";
    }
}