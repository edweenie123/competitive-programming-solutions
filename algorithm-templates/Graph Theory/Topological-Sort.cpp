#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+5;

int V, E;
int inDeg[MAX]; // stores the indegree of each vertex
vector<int> graph[MAX];

vector<int> ts;

void kahn () {
    queue<int> q;
    for (int i=0;i<V;i++) // get all vertices with an in-degree of 0
        if (inDeg[i]==0) q.push(i);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        ts.push_back(u);

        for (auto v : graph[u]) {
            inDeg[v]--; // "remove" u from graph, all neighbors of u have 1 less in degree
            if (inDeg[v]==0) q.push(v); // if neighbor has an in-degree of 0, add to queue
        }
    }
    
}

void getInput() {
    scanf("%d %d", V, E);

    int u, v;
    for (int i=0;i<E;i++) {
        scanf("%d %d", u, v);
        graph[u].push_back(v);
        inDeg[v]++;
    }
}

int main() {
    getInput();

    for (int i=0;i<MAX;i++) inDeg[i] = 0;
}