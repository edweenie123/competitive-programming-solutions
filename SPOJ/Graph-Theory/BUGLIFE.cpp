// Use BFS to determine whether or not graph is a bipartite graph
// We have to run BFS starting with every insect (1..n) because not all nodes are connected 

#include <bits/stdc++.h>
using namespace std;

bool bipartite(vector<int> graph[], int bugs) {
    int colors[bugs+1];
    memset(colors, -1, sizeof(colors));
    for (int start=1;start<=bugs;start++){
        if (colors[start] == -1){
            colors[start] = 0;
            queue<int> q;
            q.push(start);
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                int nodeColor = colors[node];

                for(auto adj: graph[node]) {
                    if (colors[adj] == -1) {
                        colors[adj] = !nodeColor;
                        q.push(adj);
                    } else if (colors[adj]==nodeColor) return false;
                }
            }
        }
    }
    return true;
}

int main () {
    int t;
    cin>>t;
    int counter = 1;

    while (t--) {
        int bugs, inters;
        cin>>bugs>>inters;
        vector<int> graph[bugs+1];
        for (int i=0;i<inters;i++) {
            int b1, b2;
            cin>>b1>>b2;
            graph[b1].push_back(b2);
            graph[b2].push_back(b1);
        }
        cout<<"Scenario #"<<counter<<":"<<endl;
        bipartite(graph,bugs)?cout<<"No suspicious bugs found!":cout<<"Suspicious bugs found!";
        cout<<endl;
        counter++;
    }
}