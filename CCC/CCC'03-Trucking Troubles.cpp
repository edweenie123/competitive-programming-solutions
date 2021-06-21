/*
~~~ CCC '03 - Trucking Troubles ~~~

Key Concepts: Kruskal/Prim, BFS, Maximin

The main idea is to find the maximum spanning tree of the road system to only include the best roads

We can then use BFS to traverse the MST to find the destination city with the lowest possible maximum weight
    - The city which bottlenecks the most weight our truck can carry
    - This miminal weight is the answer

*/

#include<bits/stdc++.h>
using namespace std;

int c, r, d;

typedef pair<int, pair<int, int>> pipii;

set<int> dest; // destination cities
int ranks[10001], parents[10001];
vector<pipii> edges; // stores all roads

map<int, vector<pair<int, int>>> mst; // maximum spanning tree of road system
int distances[10001];

void init() {
    for (int i=1;i<=c;i++) {
        parents[i] = i;
        ranks[i] = 1;
    }
}

int root(int i) {
    while(i!=parents[i]) {
        i = parents[i];
    }
    return i;
}

bool union_rank(int a, int b) { // return false if cycle is made
    int rootA = root(a), rootB = root(b);

    if (rootA==rootB) 
        return false;
    
    if (ranks[rootA]>ranks[rootB]) {
        parents[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    } else {
        parents[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    }

    return true;
}

void kruskal() {
    init();
    
    sort(edges.begin(), edges.end(), greater<pipii>());

    for (auto e : edges) {
        int u = e.second.first, v = e.second.second, w = e.first;

        if (union_rank(u, v)) { // add this edge to MST if it does not create a cycle
            mst[u].push_back(make_pair(v, w));
            mst[v].push_back(make_pair(u, w));
        }
    }
}

int BFS() { // traverses through maximum spanning tree
    memset(distances, -1, sizeof(distances));
    queue<int> q; // {node, maximum_weight}
    q.push(1);
    distances[1] = 100000;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto i : mst[node]) {
            int adj = i.first, weight = i.second;

            if (distances[adj]==-1) {
                distances[adj] = min(weight, distances[node]);
                q.push(adj);
            }
        }
    }

    int ans = 100000;

    for (int i=1;i<=c;i++) {
        if (dest.find(i)!=dest.end()) {
            if (distances[i]<ans) ans = distances[i];
        }
    }

    return ans;
}

void get_input() {
    cin>>c>>r>>d;

    int x, y, w;
    for (int i=0;i<r;i++) {
        cin>>x>>y>>w;
        edges.push_back(make_pair(w, make_pair(x, y)));
    }

    int temp;
    for (int i=0;i<d;i++) {
        cin>>temp;
        dest.insert(temp);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    get_input();
    kruskal();
    
    cout<<BFS()<<endl;
}