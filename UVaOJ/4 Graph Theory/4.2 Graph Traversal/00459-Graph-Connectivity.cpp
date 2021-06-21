/*
~~~ UVa 00459 - Graph Connectivty ~~~

Key Concepts: BFS

Find the number of connected components in a graph
    - Run BFS from every node

Can also be solved using DSU or DFS
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e7;

vector<int> graph[MAX];
int visited[MAX], numCC;

void BFS(int src) {
    if (visited[src]) return;
    
    numCC++;
    visited[src] = 1;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto v : graph[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = 1;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    int TC, n;
    string line;

    scanf("%d\n\n", &TC);
    
    while (TC--) {

        memset(visited, 0, sizeof(visited));
        for (int i=0;i<MAX;i++) graph[i].clear();
        numCC = 0;

        getline(cin, line);
        n = line[0] - 'A' + 1;
        while (1) {
            getline(cin, line);
            if (line.empty()) break;

            int u = line[0] - 'A';
            int v = line[1] - 'A';

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i=0;i<n;i++) BFS(i);

        cout<<numCC<<"\n";
        if (TC) cout<<"\n";
    }
}