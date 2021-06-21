// Key Concepts: Graph Theory

#include <bits/stdc++.h>
using namespace std;

int n, m;

int components = 0;
vector<int> graph[200001];
bool visited[200001];

void BFS(int start) {
    if (!visited[start]) {
        components += 1;
    } else return;

    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto adj : graph[v]) {
            if (!visited[adj]) {
                q.push(adj);
                visited[adj] = true;
            }
        }
    }

}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
    for (int i=1;i<=n;i++) {
        BFS(i);
    }
    (m+components==n||m+components-1==n) ? cout<<"YES":cout<<"NO";
}