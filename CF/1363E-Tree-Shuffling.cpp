/*
~~~ 1363E - Tree Shuffling ~~~

Key Concepts: Graph Theory, Greedy, DP

Let t1 = # of nodes that have a[i] = 0, b[1] = 1
    t2 = # of nodes that have a[i] = 1, b[1] = 0

Notice that we swap nodes of type1 w/ nodes of type2 to resolve them!

Insight 1: 
If t1 != t2 -> it is impossible to resolve every node
            -> output -1

Insight 2:
Consider the following structure
      o    <- root
      |
      o
      |
      o    <- LCA 
     / \
    o  o

Let say, the bottom two nodes are of type 1 and type 2 respective and we want to swap them

In order to do this with the minimal cost, we look at all nodes between the LCA and the root
    and see which one has the lowest cost -> lets call this cost K
    and lets also call the node w/ the lowest cost -> the best ancestor

The minimum cost to resolve both of these nodes is therefore 2 * K

Notice that we can generate bestAncestor of every node using a simple DFS + DP
    -> bestAn[u] is the minimum cost from nodes u to the root

Insight 3:
bestAn[u] gets smaller and smaller as you go deeper down the tree 
    -> this is because as you get deeper, you have more options of nodes you can pick

This insight leads directly to the following greedy approach...

We iterate through the tree bottom up (starting from the leafs and going up)

Every time you can resolve nodes some nodes greedily do it using the Best Ancestor

For example...
    if the subtree rooted at u has x nodes of type 1 and y nodes of type 2
        we resolve min(x, y) * 2 nodes using the best ancestor of u

Notice that after this operation we will be only left with unresolved nodes of ONE type
    -> this information is propagated to the parent of u

After doing this operation of all the children of some node
    -> we sum up all the remaining unresolved nodes of the children
       and perform the operation again on the current node with the new sum

*/



#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 2e5 + 5;

int n;
int cost[MAXN], a[MAXN], b[MAXN];
int bad1 = 0, bad2 = 0;
vector<int> graph[MAXN];

int bestAn[MAXN];
void findBestAncestor(int u, int par) {
    for (auto v : graph[u]) {
        if (v == par) continue;
        bestAn[v] = min(cost[v], bestAn[u]);
        findBestAncestor(v, u);
    }
}

ll totalCost = 0;
// returns {type, cnt} -> the # of nodes that remain unresolved in the subtree u
ii findMinCost(int u, int par) {
    int type1 = 0, type2 = 0;

    for (auto v : graph[u]) {
        if (v == par) continue;

        ii childInfo = findMinCost(v, u);

        if (childInfo.F == 1)
            type1 += childInfo.second;
        else
            type2 += childInfo.second;
    }

    if (a[u] == 0 && b[u] == 1) type1++;
    if (a[u] == 1 && b[u] == 0) type2++;

    ll numSwitch = min(type1, type2) * 2;
    totalCost += numSwitch * bestAn[u];

    if (type1 > type2) 
        return {1, type1 - type2};
    else
        return {2, type2 - type1};

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=1;i<=n;i++) {
        cin>>cost[i]>>a[i]>>b[i];

        if (a[i] == 0 && b[i] == 1) bad1++;
        if (a[i] == 1 && b[i] == 0) bad2++;
    }

    int u, v;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    if (bad1 != bad2) {
        cout<<"-1\n"; return 0;
    } 
    
    bestAn[1] = cost[1];
    findBestAncestor(1, 0);
    findMinCost(1, 0);

    cout<<totalCost<<"\n";
}