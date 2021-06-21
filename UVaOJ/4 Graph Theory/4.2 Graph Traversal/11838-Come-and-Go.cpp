/*
~~~ UVa 11838 - Come and Go ~~~

Key Concepts: Tarjan's SCC Algorithm

Run Tarjan's Algorithm to find # of Strongly Connected Components
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2001;

int n, m;
vector<int> graph[MAX];
int dfsNum[MAX], dfsLow[MAX], visited[MAX];
stack<int> s;

int numSCC, dfsIter;

void tarjan(int u) {
    dfsNum[u] = dfsLow[u] = dfsIter++;

    visited[u] = 1;
    s.push(u);

    for (auto v : graph[u]) {
        if (dfsNum[v]==-1)
            tarjan(v);
        if (visited[v])
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
    }

    if (dfsLow[u]==dfsNum[u]) {
        numSCC++;
        while (1) {
            int v = s.top(); s.pop();
            visited[v] = 0;
            if (v==u) break;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    while(cin>>n>>m) {
        if (n==0&&m==0) break;

        for (int i=0;i<MAX;i++) {
            graph[i].clear();
            dfsNum[i] = -1;
        }
        numSCC = 0;
        dfsIter = 0;

        int u, v, p;
        for (int i=0;i<m;i++) {
            cin>>u>>v>>p;
            if (p==2) graph[v].push_back(u);
            graph[u].push_back(v);
        }

        for (int i=1;i<=n;i++) 
            if (dfsNum[i]==-1)
                tarjan(i);

        cout<<(numSCC==1 ? 1 : 0)<<endl;

    }
}