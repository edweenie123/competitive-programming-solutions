/*
~~~ UVa 10305 - Ordering Tasks ~~~

Key Concepts: Topological Sort of DAG

Trivial Implementation of toposort
*/
#include<bits/stdc++.h>

using namespace std;

int n, m;

vector<int> graph[101];
vector<int> ts;
bool visited[101];

void dfs(int u) {
    visited[u] = true;

    for (auto v : graph[u]) {
        if (!visited[v]) 
            dfs(v);
    }

    ts.push_back(u);
}

int main() {
    while (scanf("%d %d", &n, &m)) {
        if (n==0&&m==0) break;
        ts.clear();
        for (int i=0;i<101;i++) {
            graph[i].clear();
            visited[i] = false;
        } 

        int u, v;
        for (int i=0;i<m;i++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
        }

        for (int i=1;i<=n;i++) 
            if (!visited[i])
                dfs(i);
        
        for (int i=n-1;i>=0;i--) {
            printf("%d ", ts[i]);
        } printf("\n");
    }
}