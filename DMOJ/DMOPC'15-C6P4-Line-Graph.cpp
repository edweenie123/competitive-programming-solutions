/*
~~~ DMOPC '15 Contest 6 P4 - Line Graph ~~~

Key Concepts: Kruskal's Algorithm

Trivial Implementation of Kruskal's Algorithm

*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
const int MAXN = 1e6 + 1;
int n, k, par[MAXN], ranks[MAXN], MSTWeight = 0;
vector<iii> edges;

int root(int i) {
    while (i!=par[i]) 
        i = par[i];

    return i;
}

void merge(int a, int b, int w) {
    int rootA = root(a), rootB = root(b);
    
    if (rootA==rootB) return;
    MSTWeight += w;

    if (ranks[rootA]<ranks[rootB]) {
        ranks[rootB] += ranks[rootB];
        par[rootA] = rootB;
    } else {
        ranks[rootA] += ranks[rootB];
        par[rootB] = rootA;
    }
}

void init() {
    for (int i=0;i<MAXN;i++) {
        par[i] = i;
        ranks[i] = 1;
    }
}

void kruskal() {
    // cout<<"yo"<<endl;
    init();
    sort(edges.begin(), edges.end());

    for (auto e : edges) {
        int w = e.first, u = e.second.first, v = e.second.second;
        // printf("considering (%d, %d)\n", u, v);
        merge(u, v, w);
    }    
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    int w;
    for (int i=1;i<=n-1;i++) {
        cin>>w;
        edges.push_back(iii(w, ii(i, i+1)));
        if (i+k<=n) edges.push_back(iii(0, ii(i, i+k)));
    }

    kruskal();

    cout<<MSTWeight<<"\n";
}