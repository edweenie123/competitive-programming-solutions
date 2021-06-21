/*
~~~ Pursuit of Knowledge ~~~

Key Concepts: BFS

Simply doing BFS for each query is too slow as Q is very large

Q is much larger than the number of nodes:
    therefore precomputing the distances for all possible start and end nodes is faster
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, t, q;
int answer[1001][1001], dist[1001];
map<int, vector<int>> graph;

void precompute() {
    for (int i=1;i<=n;i++) {
        memset(dist, -1, sizeof(dist));
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto v : graph[node]) {
                if (dist[v]==-1) {
                    dist[v] = dist[node] + t;
                    q.push(v);
                } else {
                    dist[v] = min(dist[v], dist[node]+t);
                }
            }
        }

        for (int j=1;j<=n;j++) {
            answer[i][j] = dist[j];
        }
    }
}
int main() {
    cin>>n>>m>>t;
    int u, v;
    for (int i=0;i<m;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
    }
    precompute();
    cin>>q;
    int a, b;
    while (q--) {
        cin>>a>>b;
        if (answer[a][b]!=-1) cout<<answer[a][b]<<endl;
        else cout<<"Not enough hallways!"<<endl;
    }
}