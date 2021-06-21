#include<bits/stdc++.h>
using namespace std;

#define PB push_back
const int MAXN = 1e5 + 1;

int n, m;
int isPho[MAXN];
vector<int> graph[MAXN];

int vis[MAXN], nSub, isUseless[MAXN];

bool prune(int u) { // returns true if node is needed, otherwise false
    vis[u] = 1;

    int needed = false;
    if (isPho[u]) needed = true;

    for (auto adj : graph[u]) {
        if (vis[adj]==0)
            if (prune(adj)) 
                needed = true;
    }

    if (!needed) {
        nSub--;
        isUseless[u] = true;
    }

    return needed;
}

int dist[MAXN], maxDist, furthestNode;
void DFS(int u) {
    for (auto adj : graph[u]) {
        if (isUseless[adj] || dist[adj]!=-1) continue;
        dist[adj] = dist[u] + 1;
        if (dist[adj] > maxDist) {
            maxDist = dist[adj];
            furthestNode = adj;
        }
        DFS(adj);
    }
}

int findDiameter(int str) {
    memset(dist, -1, sizeof(dist));
    maxDist = 0;
    furthestNode = str;
    dist[str] = 0;
    DFS(str);

    memset(dist, -1, sizeof(dist));
    dist[furthestNode] = 0;
    DFS(furthestNode);

    return maxDist;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    int phoTmp;
    for (int i=0;i<m;i++) {
        cin>>phoTmp;
        isPho[phoTmp] = true;
    }
    
    int u, v;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v;
        graph[u].PB(v);
        graph[v].PB(u);
    }

    nSub = n;
    prune(phoTmp);

    int diameter = findDiameter(phoTmp);
    int ans = (nSub-1) * 2 - diameter;

    cout<<ans<<"\n";
}