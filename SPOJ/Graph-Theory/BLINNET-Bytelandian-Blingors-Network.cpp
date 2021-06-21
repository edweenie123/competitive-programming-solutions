/*
~~~ BLINNET - Bytelandian Blingors Network ~~~

Key Concepts: Kruskal's Algorithm (+disjoint union find)

Trivial Implementation of Kruskal's algorithm to find weight of MST
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pipii;

int cases;
int N, M=0;
int par[1000000], ranks[1000000];
pipii edges[1000000];


int root(int i) {
    while (i != par[i]) 
        i = par[i];
    return i;
}

void init() {
    memset(par, -1, sizeof(par));
    memset(ranks, -1, sizeof(ranks));
    for (int i=0;i<N;i++) {
        par[i] = i;
        ranks[i] = 1;
    }
}

bool merge(int a, int b) { // returns true if no cycle is formed
    int rootA = root(a), rootB = root(b);

    if (rootA==rootB) return false;

    if (ranks[rootA]<rootB) {
        par[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    } else {
        par[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    }
    return true;
}

int kruskal() {
    init();
    sort(edges, edges+M);

    int weightSum = 0;

    for (int i=0;i<M;i++) {
        pipii e = edges[i];
        int u=e.second.first, v=e.second.second, w=e.first;
        if (merge(u, v)) 
            weightSum += w;
    }

    return weightSum;
}

int main() {
    cin>>cases;
    string name;
    while (cases--) {
        cin>>N;
        M = 0;
        int mtemp;
        for (int i=1;i<=N;i++) {
            cin>>name;
            cin>>mtemp;

            int weight, dest;
            for (int j=M;j<M+mtemp;j++) {
                cin>>dest>>weight;
                edges[j] = make_pair(weight, make_pair(i, dest));
            }
            M += mtemp;
        }

        int ans = kruskal();
        cout<<ans<<endl;
    }
}