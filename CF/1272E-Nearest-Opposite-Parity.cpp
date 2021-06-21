/*
~~~ 1272E - Nearest Opposite Parity ~~~

Key Concepts: Multi-source BFS, DFS

Very good problem imo

Insight 1:
We can generate a directed graph representing the possible moves at each index
    using a pretty simple DFS

    This works because there are at most n nodes in the graph so it won't MLE

Insight 2: 
Lets only consider the shortest path from an even value to an odd value for now...

Notice that this simplifies into the classic multi source BFS problem
    -> we add all the odd values into a queue and start BFS with these sources
        -> because of how BFS works, the first time we reach an even value that is the shortest dist 
            from even value to the odd value

    *Note, we have to reverse all our edges in the graph for this to work (pretty intuitive why)
        -> so we have to modify the process in insight 1 

*/



#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int MAXN = 2e5 + 5;

int n;
int steps[MAXN];

bool vis[MAXN];
vector<int> graph[MAXN];

void dfs(int u) {
    vis[u] = 1;

    int left = u - steps[u];
    int right = u + steps[u];

    if (left>=1) {
        graph[left].push_back(u); // reverse all edges
        if (!vis[left]) dfs(left);
    } 

    if (right<=n) {
        graph[right].push_back(u); // reverse all edges
        if (!vis[right]) dfs(right);
    } 

}

void genGraph() {
    for (int i=1;i<=n;i++) 
        if (!vis[i]) 
            dfs(i);
}

int dist[MAXN];
int ans[MAXN];

void bfs(int par) {
    memset(dist, -1, sizeof(dist));

    queue<int> q; // {node, origin}

    for (int i=1;i<=n;i++) 
        if (steps[i]%2==par) {
            q.push(i);
            dist[i] = 0;
        }
    
    while (!q.empty()) {

        int u = q.front(); q.pop();

        for (auto v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (steps[v]%2!=par) 
                    ans[v] = dist[v];
            }
        }
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=1;i<=n;i++) 
        cin>>steps[i];
    
    genGraph();

    memset(ans, -1, sizeof(ans));

    bfs(0); // odd to even
    bfs(1); // even to odd

    for (int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}