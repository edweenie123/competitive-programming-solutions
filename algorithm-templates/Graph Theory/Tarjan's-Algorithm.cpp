/*
~~~ Tarjan's SCC Algorithm ~~~

Strongly Connected Component: 
    A connect component in a graph such that any two in the component are connected

Tarjan's alg finds all the strongly connected components in a graph
    -> a very similar algorithm can be used to find the articulation points and bridges

This video is great at explaining this: 
    https://www.youtube.com/watch?v=wUgWX0nc4NY&


dfs_id[u] stores the order that node u was visited in the dfs traversal
dfs_low[u] stores the low link value of node u
    -> the smallest id reachable from node u in the dfs traversal

All nodes with the same low link value are part of the same connected component



Time Complexity: O(V+E)
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+5;

int dfs_id[MAX], dfs_low[MAX], onStack[MAX], dfsNumCnt=0;
stack<int> S;

int V, E;
vector<int> graph[MAX];

void tarjanSCC(int u) {
    // initialize 
    dfs_id[u] = dfs_low[u] = dfsNumCnt++;
    S.push(u); // add u to stack
    onStack[u] = 1;

    for (auto v : graph[u]) {
        if (dfs_id[v]==-1)
            tarjanSCC(v);
        if (onStack[v]) // only update dfs_low[u] if v is in the stack
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u]==dfs_id[u]) { // check if we're a the root of SCC
        printf("SCC: ");
        // remove all the nodes in the stack that are part of the SCC
        while (1) {
            int v = S.top(); S.pop();
            onStack[v] = 0; // set vertex to not in the stack
            printf("%d ", v);
            if (u==v) break; // break when it reaches the root
        } printf("\n");
    }
}


void getInput() {
    cin>>V>>E;
    int u, v;
    for (int i=0;i<E;i++) {
        cin>>u>>v;
        graph[u].push_back(v); // no need to add to graph[v] because its an undirected graph
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    getInput();

    for (int i=0;i<MAX;i++) dfs_id[i] = -1;

    for (int i=0;i<V;i++) // run tarjan on every node to get all connected components
        if (dfs_id[i]==-1)
            tarjanSCC(i);
}
