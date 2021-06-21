/*
~~~ Claire Elstein ~~~

Key Concepts: Graph Theory, DP

Find the total length of all paths in a DAG


*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int MAXN = 100001;
const int MOD = 1e9+7;
int n, m;
vector<int> graph[MAXN];
int in[MAXN], out[MAXN], numAcc[MAXN];
long long totTime[MAXN];

long long bfs() {
    queue<int> q;
    
    for (int i=1;i<=n;i++) {
        if (in[i]==0) {
            q.push(i);
            numAcc[i] = 1;
            totTime[i] = 0;
        }
    }
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        // printf("Vertex %d\n", u);

        for (auto v : graph[u]) {
            
            numAcc[v] = (numAcc[v] + numAcc[u])%MOD;
            totTime[v] = (totTime[v] + totTime[u] + numAcc[u])%MOD;
        
            in[v]--;

            if (in[v]==0) q.push(v);
        }
    }

    long long ans = 0;
    for (int i=1;i<=n;i++) 
        if (out[i]==0) ans = (ans + totTime[i])%MOD;
    
    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin>>n>>m;

    int u, v;
    for (int i=0;i<m;i++) {
        cin>>u>>v; graph[u].push_back(v);
        out[u]++;
        in[v]++;
    }

    long long ans = bfs();
    cout<<ans;
}