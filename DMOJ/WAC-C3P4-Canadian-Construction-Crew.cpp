/*
~~~ Wesley's Anger Contest 3 Problem 4 - Canadian Construction Crew ~~~

Key Concepts: Eulerian Path

The key insight is to realize that it is possible to pave the roads if there exists a eulerian path in the graph

We can check if the graph is connected quickly by using the disjoint union DS

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, q;
int deg[MAXN]; // stores degree of each node
set<int> seenNodes;
int numOdd; // stores number of vertices with odd degree

int par[MAXN], sizes[MAXN];

int root(int k) {
    while (k != par[k]) 
        k = par[k];
    
    return k;
}

void merge(int a, int b) {
    int rootA = root(a), rootB = root(b);
    if (rootA == rootB) return;

    if (sizes[rootA]>sizes[rootB]) {
        par[rootB] = rootA;
        sizes[rootA] += sizes[rootB];
    } else {
        par[rootA] = rootB;
        sizes[rootB] += sizes[rootA];
    }
}

void init() {
    for (int i=0;i<MAXN;i++) {
        par[i] = i;
        sizes[i] = 1;
    }
}

// graph is eulerian if everything is connected and numOdd = 0 or 2
bool isEulerian() {
    if (seenNodes.size() == sizes[root(*seenNodes.begin())]) // check if connected
        if (numOdd == 0 || numOdd == 2) 
            return true;
    
    return false;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;

    init();
    int a, b, x;
    for (int i=0;i<q;i++) {
        cin>>a>>b>>x;

        // update number of vertices with odd degree        
        if (deg[a]%2==0 && x%2==1) numOdd++;
        if (deg[a]%2==1 && x%2==1) numOdd--;
        if (deg[b]%2==0 && x%2==1) numOdd++;
        if (deg[b]%2==1 && x%2==1) numOdd--;
        
        deg[a] += x, deg[b] += x;
        
        seenNodes.insert(a), seenNodes.insert(b); 
        merge(a, b);

        cout<<(isEulerian() ? "YES" : "NO")<<"\n";
    }
}