/*
~~~ CCC '10 S4 - Animal Farm ~~~

Key Concepts: Kruskal's MST Algorithm

Main insight is to treat the animals as the vertices instead of the corners
There exists a direct path between two animals if their rooms share an edge

The goal is to have it so that any animal can access the rooms of all other animals
Thus, if we turn the graph into a spanning tree, we can achieve this without any useless edges

We can use Kruskal's algorithm to find the minimum spanning tree in the graph to minimize cost

*Note* --- We run Kruskal's algorithm twice:
    1. One time without the outside pen as a vertice
    2. A second time with the outside pen as a vertice

This is because including the outside pen could both lower and increase the cost
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pipii;

int m, par[100000], ranks[100000], numEdges=0;
vector<pipii> edges;
map<pair<int,int>, pair<int,int>> edgeData;

int root(int i) {
    while (i!=par[i]) 
        i = par[i];
    return i;
}

bool merge(int a, int b) { 
    int rootA = root(a), rootB = root(b);

    if (rootA==rootB) 
        return false;
    
    if (ranks[rootA]<ranks[rootB]) {
        par[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    } else {
        par[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    }

    return true;
}

void init() {
    for (int i=0;i<numEdges;i++) {
        par[i] = i;
        ranks[i] = 1;
    }
}

int kruskal() {
    init();

    sort(edges.begin(), edges.end());
    int ans = 0;

    for (int i=0;i<numEdges;i++) {
        pipii e = edges[i];
        int w = e.first, u = e.second.first, v = e.second.second;

        if (merge(u, v)) 
            ans += w;            
    }
    return ans;
}

int main() {
    cin>>m;

    int ep, temp;
    
    for (int i=0;i<m;i++) {
        cin>>ep;
        vector<int> corners, weights;
        for (int j=0;j<ep;j++) {
            cin>>temp;
            corners.push_back(temp);
        }
        for (int j=0;j<ep;j++) {
            cin>>temp;
            weights.push_back(temp);
        }

        int u, v, w;
        pair<int, int> p1, p2;

        for (int j=0;j<ep;j++) {
            if (j==ep-1) u = corners[ep-1], v = corners[0];
            else u = corners[j], v = corners[j+1];
            
            w = weights[j];
            p1 = make_pair(u, v), p2 = make_pair(v, u);
            if (edgeData.find(p1)==edgeData.end()) {
                edgeData[p1] = make_pair(i, w);
                edgeData[p2] = make_pair(i, w);
            } else {
                edges.push_back(make_pair(w, make_pair(edgeData[p1].first, i)));
                edgeData.erase(p1);
                edgeData.erase(p2);
            }
        }
    }

    numEdges = edges.size();
    int inside = kruskal();

    for (auto i : edgeData) 
        edges.push_back(make_pair(i.second.second, make_pair(i.second.first, m)));
    
    numEdges = edges.size();
    int outside = kruskal();

    cout<<min(inside, outside)<<endl;
}