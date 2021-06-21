/*
~~~ UVa 793 - Network Connections ~~~

Key Concepts: Disjoint Set

Trivial implementation of DSU
*/

#include <bits/stdc++.h>
using namespace std;

int parent[1000000], sizes[1000000];
int tests, numC, success, fail;


int root(int i) {
    while(parent[i]!=i) 
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    int rootA = root(a), rootB = root(b);

    if (sizes[rootA]<sizes[rootB]) {
        parent[rootA] = rootB;
        sizes[rootB] += sizes[rootA];
    } else {
        parent[rootB] = rootA;
        sizes[rootA] += sizes[rootB];
    }
}

bool findSet(int a, int b) {
    if (root(a)==root(b)) return true;
    else return false;
}

void initialize() {
    for (int i=0;i<numC;i++) {
        parent[i]=i;
        sizes[i]=1;
    }
}

int main() {
    cin>>tests;
    while(tests--) {
        scanf("\n%d\n", &numC);
        memset(parent, 0, sizeof(parent));
        memset(sizes, 0, sizeof(sizes));
        initialize();

        success = fail = 0;        
        string line;
        char type;
        int ci, cj;
        
        while (true) {
            getline(cin, line);
            if (line.length()==0) break;

            sscanf(line.c_str(), "%c %d %d", &type, &ci, &cj);

            if (type=='c') 
                unionSet(ci, cj);
            else 
                findSet(ci, cj) ? success++ : fail++;
        }
        cout<<success<<","<<fail<<endl;
        if (tests!=0) cout<<endl;
    }
}