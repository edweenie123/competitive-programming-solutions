/*
~~~ UVa 10600 - ACM contest and Blackout ~~~

Key Concepts: 2nd Best MST (Kruskals)

Run Kruskal's to find MST

For each edge in the MST:
    exclude it and run Kruskal's again

The best spanning tree founded in this process is the 2nd best MST

*** You must check if every thing is fully connected (excluding an edge might disconnect everything) ***
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int TC, n, m;
iii edges[6000];
vector<iii> MSTEdges;
int par[200], ranks[200], MSTWeight, sMSTWeight;

int root(int i) {
    while (i!=par[i]) {
        i = par[i];
    }
    return i;
}

void merge(int a, int b, int w, bool isMST) {
    int rootA = root(a), rootB = root(b);

    if (isMST) {
        MSTWeight += w;
        MSTEdges.push_back(iii(w, ii(a, b)));
    } else {
        sMSTWeight += w;
    }

    if (ranks[rootA]>ranks[rootB]) {
        par[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    } else {
        par[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    }
}

void initialize() {
    for (int i=0;i<200;i++) {
        par[i] = i;
        ranks[i] = 1;
    }
}

void kruskals(iii exclude) {
    bool excluded = false;

    initialize();
    for (int i=0;i<m;i++) {
        iii e = edges[i];
        if (e==exclude && !excluded) {
            excluded = true;
            continue;
        }

        if (root(e.second.first)!=root(e.second.second)) {
            if (exclude==iii(-1,ii(-1,-1))) {
                merge(e.second.first, e.second.second, e.first, true);
            } else {
                merge(e.second.first, e.second.second, e.first, false);
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>TC;

    while (TC--) {
        cin>>n>>m;
        MSTWeight = 0;
        sMSTWeight = 0;

        MSTEdges.clear();

        int u, v, w;
        for (int i=0;i<m;i++) {
            cin>>u>>v>>w;
            edges[i] = iii(w, ii(u, v));
        }

        sort(edges, edges+m);
        kruskals(iii(-1, ii(-1, -1))); // find MST

        int secondBest = 1e6;
        for (auto e : MSTEdges) {
            kruskals(e);
            
            bool isConnected = true;
            int r = root(1);
            for (int i=1;i<=n;i++) {
                if (root(i)!=r) {
                    isConnected = false;
                    break;
                }
            }
            if (isConnected) secondBest = min(secondBest, sMSTWeight);
            sMSTWeight = 0;
        }

        cout<<MSTWeight<<" "<<secondBest<<endl;
    }
}