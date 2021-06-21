/*
~~~ Prim's MST Algorithm ~~~

- Idea -

1. We start at any arbitary node in the graph
2. Add all neighbors of the vertex to a priority queue (sorts in increasing)
3. Visit the vertex which is at the top of the priority queue (include that edge in the MST)
    (the neighbor with the smallest edge weight)
4. Repeat from step 2 until all vertices have been visited   

Time Complexity: O(ElogE)

*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
const int MAX = 1e6+5; 

int V, E;
vector<ii> graph[MAX]; // adjacency list format
bool visited[MAX];

int prim(int src) { // returns weight of MST
    for (int i=0;i<MAX;i++) visited[i] = false;

    priority_queue<ii, vector<ii>, greater<ii>> pq; // stores edges in non-decreasing order

    pq.push(ii(0, src));
    // visited[src] = true;

    int MSTweight = 0;
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();

        int u = front.second, w = front.first;

        if (!visited[u]) {
            MSTweight += w;
            visited[u] = true;

            for (auto adj : graph[u]) {
                int v = adj.second, vw = adj.first;
                if (!visited[v]) 
                    pq.push(ii(vw, v)); 
            }
        }
    }

    return MSTweight;
}

void getInput() {
    cin>>V>>E;

    int u, v, w;
    for (int i=0;i<E;i++) {
        cin>>u>>v>>w;
        graph[u].push_back(ii(w, v));
        graph[v].push_back(ii(w, u));
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    getInput();

    int ans = prim(1); // can start at any arbitary vertex

    cout<<"The weight of the MST is "<<ans<<endl;
}