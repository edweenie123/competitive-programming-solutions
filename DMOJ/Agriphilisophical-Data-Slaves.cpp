/*
~~~ Agriphilisophical Data Slaves ~~~

Key Concepts: Graph Theory

Update agriculturality starting from the leaves of the tree.

Add a parent to the bfs queue only if agri[parent] is correct (all of its children have relayed their info)
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 5;
int n, parent[MAXN], out[MAXN], work[MAXN], agri[MAXN];

int bfs() {
    queue<int> q;
    
    for (int i=1;i<=n;i++)  
        if (out[i]==0)
            q.push(i);
    
    int optAgri = -1e8;
    while(!q.empty()) {
        int u = q.front(); q.pop();

        optAgri = max(optAgri, agri[u]);

        int v = parent[u];
        agri[v] += agri[u];
        out[v]--;

        if (out[v]==0) q.push(v);
    }

    return optAgri;

}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    int u, v;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v;
        parent[v] = u;
        out[u]++;
    }

    for (int i=1;i<=n;i++) {
        cin>>work[i];
        agri[i] = work[i];
    }

    cout<<bfs();
}