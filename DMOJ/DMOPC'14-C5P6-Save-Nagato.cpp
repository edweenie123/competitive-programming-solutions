/*
~~~ DMOPC '14 Contest 5 P6 - Save Nagato! ~~~

Key Concept: Dynamic Programming / Graph Theory

Find the longest path from every node in a tree (use DP see editorial)
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int n, down[MAXN], up[MAXN], par[MAXN];
vector<int> tree[MAXN];

void dfs_down(int u) {
    for (auto v : tree[u]) {
        if (v==par[u]) continue;
        par[v] = u;
        dfs_down(v);
        down[u] = max(down[u], down[v]+1);
        
    }
}

void dfs_up(int u) {
    // printf("at vertex %d\n", u);
    
    // relax the up path; the parent's up path will always be correct (maximized)
    if (u!=1) up[u] = max(up[u], up[par[u]]+1);

    // determine the child with the best and 2nd best down pathes
    int bestD=up[u], bestS=-1, bestD2=up[u];
    for (auto v : tree[u]) {
        if (v==par[u]) continue;
        if (down[v]+2>bestD) {
            bestD2 = bestD;
            bestD = down[v]+2;
            bestS = v;
        } else if (down[v]+2>bestD2) bestD2 = down[v]+2;
        
    }
   
    // determine the course of action of each child
    for (auto v : tree[u]) {
        if (v==par[u]) continue;

        if (bestS==-1) 
            up[v] = up[u] + 1; // go up the parent
        else {
            if (v==bestS) 
                up[v] = bestD2; // either go up parent or go down 2nd sibling (depending on which one is higher)
            else 
                up[v] = bestD; // go down the best sibling
        }

        dfs_up(v);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin>>n;
    int u, v;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v; 
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs_down(1);
    dfs_up(1);

    for (int i=1;i<=n;i++) {
        int ans = max(down[i]+1, up[i]+1);
        // printf("vertex: %d -> d: %d, u: %d\n", i, down[i], up[i]);
        cout<<ans<<"\n";
    }
}