/*
~~~ 1337C - Linova and Kingdom ~~~

Key Concepts: DFS, Greedy kinda

Here's the main idea...

Let dist[u] be the distance of u from the root
    sz[u] be the # of nodes in the subtree u (not including u)
    score[u] be dist[u] - sz[u];

Through intuition and observation the nodes with the highest score are the best industry nodes

Simply, sort the nodes by the score and choose the k'th best ones to be the industry nodes

*/

#include<bits/stdc++.h>
using namespace std;

#define PB push_back
typedef long long ll;
const int MAXN = 2e5 + 5;

int n, k;
vector<int> graph[MAXN];

struct node {
    int id;
    int depth; // distance from capital
    int sz; // # nodes in the subtree
};

bool cmp(const node &a, const node &b) {
    int netA = a.depth - a.sz;
    int netB = b.depth - b.sz;
    
    return netA > netB; 
}

// stores all nodes in order of preference for industry
vector<node> allNodes;

int dist[MAXN]; // dist from capital
int sz[MAXN]; // size of subtree

void getDistAndSz(int u, int par) {
    if (u!=1) dist[u] = dist[par] + 1;

    int size = 0;
    for (auto v : graph[u]) {
        if (v == par) continue;

        getDistAndSz(v, u);

        size += sz[v] + 1;
    }

    sz[u] = size;
}

bool isIndustry[MAXN];

ll totalHappiness = 0;
void calcHappiness(int u, int par, int indSeen) {

    if (isIndustry[u])
        totalHappiness += (ll)dist[u] - (ll)indSeen;
    
    for (auto v : graph[u]) {
        if (v == par) continue;

        if (isIndustry[u])
            calcHappiness(v, u, indSeen + 1);
        else
            calcHappiness(v, u, indSeen);
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;

    int u, v;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v;

        graph[u].PB(v);
        graph[v].PB(u);
    }

    dist[1] = 0;
    getDistAndSz(1, -1);

    for (int i=1;i<=n;i++) 
        allNodes.PB(node{i, dist[i], sz[i]});
    
    
    sort(allNodes.begin(), allNodes.end(), cmp);

    // flag the k best nodes for industry
    for (int i=0;i<k;i++) {
        node best = allNodes[i];
        isIndustry[best.id] = true;
    }

    calcHappiness(1, -1, 0);

    cout<<totalHappiness<<"\n";
}