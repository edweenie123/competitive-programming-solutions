/*
~~~ FOXLINGS - Foxlings ~~~

Key Concepts: DSU

Simple implementation of DSU to count # of connect components
If you are connected two nodes with different roots, cc--

The constrant of n is 10^9 --> using an array to store the parents will exceed memory limit
But there are at most 10^5, which means that there are at most 2*10^5 unique nodes with connections
Thus, we can store only the parents that we need in a map to save memory 

*/

#include<bits/stdc++.h>
using namespace std;

int n, m, cc; 
map<int, int> arr, sizes;

int root(int i) {
    while (arr[i]!=i) {
        i = arr[i];
    }
    return i;
}

void unionRank(int a, int b) {
    int rootA = root(a);
    int rootB = root(b);

    if (rootA != rootB) {
        cc--;
        if (sizes[rootA] < sizes[rootB]) {
            arr[rootA] = rootB;
            sizes[rootB] += sizes[rootA];
        } else {
            arr[rootB] = rootA;
            sizes[rootA] += sizes[rootB];
        }
    }
}

int main() {
    cin>>n>>m;
    cc = n;
    int u, v;
    while (m--) {
        cin>>u>>v;

        if (arr.find(u)==arr.end()) {
            arr[u] = u;
            sizes[u] = 1;
        }

        if (arr.find(v)==arr.end()) {
            arr[v] = v;
            sizes[v] = 1;
        }
        unionRank(u, v);
    }
    cout<<cc;
}