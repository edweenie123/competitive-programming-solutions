/*
~~~ Esdeath ~~~

Key Concepts: Graph Theory, Greedy
*/


#include<bits/stdc++.h>
using namespace std;

#define PB push_back
const int MAXN = 5000 + 5;

int n, s;
vector<int> graph[MAXN];

int par[MAXN];

struct node {
    int id;
    int distRoot; // distance from root

    friend bool operator<(const node &a, const node &b) {
        return a.distRoot>b.distRoot; // sort in reverse order
    }
};

vector<node> allNodes; 
void rootTree(int u, int dist) {
    allNodes.PB(node{u, dist});
    for (auto v : graph[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        rootTree(v, dist+1);
        
    }
}

bool cov[MAXN]; // keeps track of what nodes have been covered 
void fill(int u, int p, int left) {
    if (left==0) return;
    for (auto v: graph[u]) {
        if (v==p) continue;

        cov[v] = true;
        fill(v, u, left-1);
    }
}

bool canCover(int d) {
    memset(cov, false, sizeof(cov));
    
    int boiCount = 0;
    for (auto boi : allNodes) {
        int node = boi.id;
        if (cov[node]) {
            
            continue;
        }
        boiCount++;

        if (boiCount>s) return false;
        int awayNode = node;
        for (int i=0;i<d;i++) awayNode = par[awayNode];
        cov[awayNode] = true;
        fill(awayNode, awayNode, d);

    }
    return true;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>s;

    int u, v;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v;
        graph[u].PB(v), graph[v].PB(u);
    }
    par[1] = 1;
    rootTree(1, 0);

    sort(allNodes.begin(), allNodes.end());


    for (int d=0;d<=n;d++) { // try all possible values of d
        if (canCover(d)) {
            cout<<d<<"\n";
            return 0;
        } 
    }


}