// Use DFS to determine if there is a cycle present in the graph
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> graph[10010];
bool visited[10010];
bool dfs(int start, int parent) {
    visited[start] = true;
    for (auto adj:graph[start]) {
        if (!visited[adj]) {
            if (!dfs(adj, start)) return false;
            visited[adj] = true;
        } else if (adj!=parent){
            return false;
        }
    } 
    return true;
}

int main() {
    cin>>n>>m;
    int u,v;
    for (int i = 0; i < m; i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(u, u) ? cout<<"YES"<<endl 
            :cout<<"NO"<<endl;
}