/*
~~~ 1361A - Johnny and Contribution ~~~

Key Concepts: DFS, constructive algorithms

Insight 1:
In order for a network to be valid, 2 conditions must be satisfied:

    1. Two nodes with the same color can't be adjacent
    2. If a node has color X, it needs to be connected to nodes
        with colors 1 -> X-1
        -> this is because Johnny always picks the lowest topic that hasn't been written

These conditions can be checked in O(n + m) using a simple DFS
    -> in hindsight i probably should have used BFS (its simplier)

Insight 2:
If a graph is valid, we can always generate the desired network if we:
    Write the blogs with the smallest colors first

    IE: sort all the nodes by the colors in non-decreaseing order
        -> that is the order we visit the nodes in


*/


#include<bits/stdc++.h>
using namespace std;

#define print(x) cout<<(#x)<<" = "<<x<<"\n";
typedef long long ll;

int n, m;

vector<int> graph[500005];
int topic[500005];
int vis[500005];
vector<int> topicList[500005];
bool isValid = true;

void dfs(int u) {
    vis[u] = 1;
    set<int> lessBois;

    for (auto v : graph[u]) {
        if (topic[v] == topic[u]) {
            isValid = false;
            break;
        }

        if (topic[v] < topic[u]) {
            if (!lessBois.count(topic[v])) {
                lessBois.insert(topic[v]);
            }
        }

        if (!vis[v]) dfs(v);
    }

    if (lessBois.size() != topic[u] - 1) 
        isValid = false;
}


int main() {
    cin>>n>>m;

    int u, v;
    for (int i=0;i<m;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
        cin>>topic[i];
        topicList[topic[i]].push_back(i);
    }

    for (int i=1;i<=n;i++) 
        if (!vis[i]) dfs(i);    

    if (!isValid) {
        cout<<"-1\n";
        return 0;
    }

    for (int i=1;i<=n;i++) 
        for (auto a : topicList[i])
            cout<<a<<" ";
    
    cout<<"\n";


}