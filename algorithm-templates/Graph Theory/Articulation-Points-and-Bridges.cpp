/*
~~~ Finding Articulation Points and Bridges ~~~

Time Complexity: O(V+E)

*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
const int MAX = 1e6+5;

int dfs_low[MAX], dfs_num[MAX], dfs_parent[MAX];
int dfsNumCnt = 0; // used to initialize dfs_num
int rootChildren = 0, dfsRoot; // used special case --> if root is articulation 

bool articulation_points[MAX];
vector<ii> bridges;

vector<int> graph[MAX]; // adjacency list format

int V, E; // #vertices, #edges

void dfs(int u) {
    dfs_num[u] = dfs_low[u] = dfsNumCnt++; // dfs_low[u] = dfs_num at the beginning

    for (auto v : graph[u]) {
        if (dfs_num[v]==-1) { // unvisited vertices
            dfs_parent[v] = u;

            if (u==dfsRoot) rootChildren++; // count #children of root for special case

            dfs(v);

            if (dfs_low[v] >= dfs_num[u]) // check for articulation point
                articulation_points[u] = true;
            
            if (dfs_low[v] > dfs_num[u]) // check for bridge
                bridges.push_back(ii(u, v));
            
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
        } else if (dfs_parent[u]!=v) // update dfs_low[u] only if v is not u's parent
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);      
    }
}

void getInput() {
    cin>>V>>E;

    int u, v;
    for (int i=0;i<E;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    getInput();

    // initialize variables
    dfsNumCnt = 0;
    for (int i=0;i<MAX;i++) dfs_num[i] = -1;

    for (int i=0;i<V;i++) { // do DFS on every vertex to get all connected components
        if (dfs_num[i]==-1) {
            dfsRoot = i; rootChildren = 0;
            dfs(dfsRoot);
            articulation_points[dfsRoot] = rootChildren > 1; // special case
        }
    }
    
    // output Articulation points + Bridges
    printf("\nArticulation Points:\n");
    for (int i=0;i<V;i++) 
        if (articulation_points[i]) printf("Vertex %d\n", i);
    
    printf("\nBridges:\n");
    for (auto b : bridges) 
        printf("Edge (%d, %d)\n", b.first, b.second);
}
