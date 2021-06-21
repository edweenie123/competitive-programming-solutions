/*
~~~ Disjoint Set Data Structure ~~~

Union-Find Algorithm performs 2 useful operations on the DS Data structure:
    1. Find(A, B) --> returns true if there exists a path between A and B
    2. Union(A, B) --> merges the 2 subsets/connected component into a single one

- Naive Implementation -

Idea: Arr[i] stores the representative of each connected component
Union(A, B) - change all nodes with Arr[A] as a representative have Arr[B] as a representative
Find(A, B) - check if A and B have the same representative

Time Complexities:
    Union --> O(n) *very ineffiecient
    Find --> O(1)

- Better Approach -

Idea: Arr[i] stores the parent of the each connected component
    Root(i) returns the "representative" of the component 
        the only node which parent is itself (R=Arr[R])

Union(A, B) - Sets the Root(B) to be the parent of the Root(A) --> Arr[Root(A)] = Root[B]
Find(A, B) - check if A and B have the same root 

How do we find Root(i):
1. Repeatedly chases the parent of i until Arr[i] = i (its parent is itself)

Time Complexities:
    Union --> O(n) because Root(i) --> O(n)
    Find --> O(n)

This is even worse! How do we optimize this?

- Optimizations - 

Union by Rank:
    Idea: Maintain a Size array which returns the size of each connected component
        i.e. Size[Root(i)] = # nodes in i's connected component
    
    During union, we always want to connect the set with the smaller size to the set with larger size
    Doing this will lead to a balanced tree - Root() now takes O(log2(n))!

    Time Complexities:
        Union --> O(log2(n))
        Find --> O(log2(n))

Path Compression:
    Idea: when calculating the Root[i] we set each node's parent to be it's grandparent

    This halves the path length which causes Root --> O(log* n)

    O(log* n) is much better than O(log n) 

    Time Complexities:
        Union --> O(log* n)
        Find --> O(log* n)
*/

#include <bits/stdc++.h>
using namespace std;

int arr[1000000]; // points to parent of node i
int sizes[1000000]; // points to size of connected component that contains node i

int N, Q;

int root(int i) { // returns root of node i
    while (arr[i]!=i) {
        arr[i] = arr[arr[i]]; // path compression
        i = arr[i];
        
    }
    return i;
}

bool find(int A, int B) { // returns true if A and B are connected
    if (root(A)==root(B)) return true;
    else return false;
}

void unionRank(int A, int B) { // merges set A and set B
    int rootA = root(A);
    int rootB = root(B);

    if (rootA==rootB) return; // cycle found!!

    if (sizes[rootA] < sizes[rootB]) { // union by rank
        arr[rootA] = arr[rootB];
        sizes[rootB] += sizes[rootA];
    } else {
        arr[rootB] = arr[rootA];
        sizes[rootA] += sizes[rootB]; 
    }
}

void initialize() { // initialize sizes arr and parent arr
    for (int i=0;i<N;i++) {
        arr[i] = i;
        sizes[i] = i;
    }
}

int main() {
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