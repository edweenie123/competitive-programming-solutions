/*
~~~ 11503 - Virtual Friends ~~~

Key Concepts: Disjoint Set

Simple Implementation of dsu to find size of connected component

Since node are names not numbers, we use a map which maps between the name --> index
*/

#include <bits/stdc++.h>
using namespace std;

const int maxE = 1000000;
int parents[maxE], ranks[maxE];
map<string, int> ntoI;

int cases, ind=0, fs;

void nametoInd(string name) {
    if (ntoI.find(name)==ntoI.end()) {
        ntoI[name] = ind;
        ind++;
    } 
}

int root(int i) {
    while (i!=parents[i]) {
        i = parents[i];
    }
    return i;
}

void unionSet(int a, int b) {
    int rootA = root(a), rootB = root(b);
    if (rootA==rootB) return;

    if (ranks[rootA]<ranks[rootB]) {
        parents[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    } else {
        parents[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    }
}

void init() {
    memset(parents, 0, sizeof(parents));
    memset(ranks, 0, sizeof(ranks));
    ntoI.clear();

    for (int i=0;i<2*fs;i++) {
        parents[i] = i;
        ranks[i] = 1;
    }
}

int main() {
    cin>>cases;

    while (cases--) {
        cin>>fs;
        init();
        string n1, n2;
        while (fs--) {
            cin>>n1>>n2;
            nametoInd(n1);
            nametoInd(n2);

            unionSet(ntoI[n1], ntoI[n2]);
            
            cout<<ranks[root(ntoI[n1])]<<endl;
        }
    }
}