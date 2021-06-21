// Key Concepts: BFS, Precomputation

#include <bits/stdc++.h>
using namespace std;

int b, q;
vector<array<int, 3>> beacons; 
map<int, vector<int>> graph;

int visited[501];
bool BFS (int start, int end) {
    memset(visited, 0, sizeof(visited));
    visited[start]=1;

    if (!graph.count(start)) return false;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node==end) return true;
        for (auto adj : graph[node]) {
            if (!visited[adj]) {
                q.push(adj);
                visited[adj]=1;
            }
        }
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin>>b>>q;
    int x, y, r;
    for (int i=0;i<b;i++) {
        cin>>x>>y>>r;
        beacons.push_back({x, y, r});
    }

    for (int i=0;i<beacons.size();i++) {
        int x1=beacons[i][0], y1=beacons[i][1], r=beacons[i][2];
        for (int j=0;j<beacons.size();j++) {
            if (j==i) continue;
            int x2=beacons[j][0], y2=beacons[j][1];
            float dist = sqrt(pow(x1-x2, 2)+ pow(y1-y2, 2));
            if (dist<=r) {
                graph[i+1].push_back(j+1);
            }
        }
    }
    int a, b;
    while (q--) {
        cin>>a>>b;
        BFS(a, b) ? cout<<"YES" : cout<<"NO";
        cout<<endl;
    }
}