/*
~~~ TSOC '15 Contest 1 #5 - Giant Ants ~~~

Key Concepts: BFS

Fairly Straight-Forward BFS
*/

#include<bits/stdc++.h>
using namespace std;

int n, m, w, antVisited[1010], dist[1010];
vector<int> graph[1010];
vector<int> antQueue;

void antPropagate() {
    // printf("ant propagating\n");
    vector<int> newQueue;

    for (auto u : antQueue) {
        for (auto v : graph[u]) {
            if (antVisited[v]!=0) continue;
            newQueue.push_back(v); 
            antVisited[v] = 1;
            // printf("%d is now anted\n", v);
        }
    }
    antQueue.clear();
    for (auto u : newQueue) antQueue.push_back(u);
}

int bfs() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    int time = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        // printf("looking at %d\n", u);
        if (dist[u]>time) time++;
        // printf("time is now %d\n", time);
        if (time%4==0&&time!=0) antPropagate();
        // if (antVisited[u]) continue;

        if (u==n) return dist[u];
        for (auto v : graph[u]) {
            if (dist[v]!=-1) continue;
            if (antVisited[v]) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return -1;
    
}
int main() {
    cin>>n>>m;

    int x, y;
    for (int i=0;i<m;i++) {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cin>>w;

    int wi;
    for (int i=0;i<w;i++) {
        cin>>wi;
        antQueue.push_back(wi);
        antVisited[wi] = 1;
    }

    for (int i=0;i<101;i++) dist[i] = -1;
    int ans = bfs();

    cout<<(ans!=-1 ? to_string(ans) : "sacrifice bobhob314")<<endl;
}