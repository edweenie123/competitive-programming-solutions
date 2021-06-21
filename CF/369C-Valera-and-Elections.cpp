/*
~~~ 369C - Valera and Elections ~~~

Key Concepts: DFS

Insight 1: 
It is always better to put the bois deeper down the tree
    -> this is because the path from deeper nodes to 1 contains more nodes

Insight 2:
Thus, we can do a DFS on the tree since this visits nodes that are deeper first
    -> whenever we reach a child v that is connected by a broken road
        we consider whether or not we should place a boi
    
    if there is already a boi in the subtree rooted at v:
        we do nothing -> there is no need to put another boi since it is already covered
    else:
        we must place a boi somewhere in the subtree rooted at v to resolve the broken road
            we can select node v to put the boi in since nothing beneath is broken

*/



#include<bits/stdc++.h>
using namespace std;

typedef pair<int, bool> ib;
const int MAXN = 2e5 + 5;

int n;
vector<ib> graph[MAXN]; // {neighbor, isBroken}
vector<int> bois;

// returns true if the subtree rooted at u contains a boi
bool dfs(int u, int par) {

    bool containsBoi = false;

    for (auto adj : graph[u]) {
        
        int v = adj.first; bool isBroken = adj.second;

        if (v == par) continue;

        bool childHasBoi = dfs(v, u);
        if (childHasBoi) containsBoi = true;

        if (isBroken) {
            if (!childHasBoi) { // you must put a boi here
                bois.push_back(v);
                containsBoi = true;
            }
        }
    }

    return containsBoi;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    int u, v, t;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v>>t;

        graph[u].push_back({v, t==2});
        graph[v].push_back({u, t==2});
    }

    dfs(1, 0);

    cout<<bois.size()<<"\n";
    for (auto b : bois) cout<<b<<" ";
    cout<<"\n";
}