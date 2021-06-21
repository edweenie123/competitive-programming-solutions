/*
~~~ DMPG '17 S2 - Anime Conventions ~~~~

Key Concepts: DSU

Straight-forward classical implementation of the union find algorithm

*/

#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
int sizes[1000000]; 

int N, Q;

int root(int i) {
    while (arr[i]!=i) {
        // arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

bool find(int A, int B) {
    if (root(A)==root(B)) return true;
    else return false;
}

void unionRank(int A, int B) {
    int rootA = root(A);
    int rootB = root(B);

    if (sizes[rootA] < sizes[rootB]) {
        arr[rootA] = arr[rootB];
        sizes[rootB] += sizes[rootA];
    } else {
        arr[rootB] = arr[rootA];
        sizes[rootA] += sizes[rootB]; 
    }
}

void initialize() {
    for (int i=0;i<N;i++) {
        arr[i] = i;
        sizes[i] = i;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    initialize();
    string temp;
    int u, v;
    while (Q--) {
        cin>>temp;
        cin>>u>>v;
        if (temp=="A") {
            unionRank(u, v);
        } else {
            find(u, v) ? cout<<"Y" : cout<<"N";
            cout<<endl;
        }
    }
}