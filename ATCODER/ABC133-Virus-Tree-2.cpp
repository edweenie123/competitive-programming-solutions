/*
~~~ AtCoder Beginner Contest 133 - Virus Tree 2 ~~~

Key Concepts: Tree (sorta), AdHoc

# of ways of coloring all children a node with x children = product(k-2-i) for all i = (0..x-1)
*/

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n, k, visited[100005];
vector<int> graph[100005];

long long dfs(int u) {
    visited[u] = 1;

    long long product = 1;
    int childCnt = 0;

    for (auto v : graph[u]) {
        if (!visited[v]) {
            if (u==1) product = (product * (k - 1 - childCnt))%MOD;
            else product = (product * (k - 2 - childCnt))%MOD;
            childCnt++;
            product = (product * dfs(v))%MOD;
        }
    }

    return product%MOD;
}

int main() {
    cin>>n>>k;
    int u, v;

    for (int i=0;i<n-1;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=0;i<100005;i++) visited[i] = 0;
    cout<<(dfs(1)*k)%MOD;
}