// Idea is to run BFS two times
// 1st time is to find one of the end nodes that is part of the longest path
// 2nd time we run BFS again starting from that end node to find the longest path


#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[10001];
int distances[10001];
int maxDist;

int BFS(int start) {
    memset(distances,-1,sizeof(distances));
    distances[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto adj : graph[v]) {
            if (distances[adj]==-1) {
                distances[adj] = distances[v] + 1;
                q.push(adj);
            } 
        }
    }
    maxDist = -1;
    int maxNode;
    for (int i=1;i<=n;i++) {
        if (distances[i]>maxDist){
            maxDist = distances[i];
            maxNode = i;
        }
    }
    return maxNode;
}
int main() {
    cin>>n;
    int u;
    for(int i=0;i<n-1;i++) {
        int v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int endNode = BFS(u);
    BFS(endNode);
    cout<<maxDist<<endl;
}