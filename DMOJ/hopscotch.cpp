#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int MAXN = 2e5+1;

int n, q, dist[MAXN];
vi graph[MAXN];

void BFS() {
    for (int i=0;i<MAXN;i++) dist[i] = -1;
    dist[n-1] = 0;
    queue<int> q; q.push(n-1);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto v : graph[u]) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

int main() {
    cin>>n;

    int p;
    for (int i=0;i<n;i++) {
        cin>>p;
        if (i+p>n-1) graph[n-1].push_back(i);
        else graph[i+p].push_back(i);
    }

    cin>>q; 

    int t, x, v;
    for (int i=0;i<q;i++) {
        cin>>t;
        if (t==1) {
            cin>>x;
            cout<<dist[x];
        }
        else {
            cin>>x>>v;
        }
    }


}