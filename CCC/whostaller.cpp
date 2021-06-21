#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;;
int n, m;
vector<int> graph[MAXN];

int bfs(int u, int tar) {
    bool vis[MAXN];

    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto v : graph[u]) {
            if (!vis[v]) {
                if (v==tar) return true;
                q.push(v);
                vis[v] = true;
            }
        }
    }

    return false;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    int x, y;
    for (int i=0;i<m;i++) {
        cin>>x>>y;
        graph[x].push_back(y);
    }

    int p, q;
    cin>>p>>q;

    if (bfs(p, q)) 
        cout<<"yes"<<"\n";
    else if (bfs(q, p))
        cout<<"no"<<"\n";
    else 
        cout<<"unknown"<<"\n";

    
}