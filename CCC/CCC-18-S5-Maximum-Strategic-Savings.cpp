/*
~~~ CCC '18 S5 - Maximum Strategic Savings ~~~

Key Concepts: Graph Theory, Big Brain

The trick is to speed up kruskals by imagining the system as grid

Let imagine our system as a n*m grid
    Each row represents a planet and each column represents cities w/ the same number
    Realize that N flights connects two columns and M portal connects two rows

If all rows are connected AND all columns are connected:
    This implies that the entire system is connected!

- With this in mind, let's begin with the optimization -

In the naive approach we add ALL edges to the edge list...

We can do better than this!
    Instead, each element in the edge list will represent a connection between two rows OR two columns
        This means we have P flights and Q portals in the edge list

When merging two rows:
    Check if the two rows are already connected (using disjoint set union DS)
    If not:
        MSTWeight += cost of portal * # of unmergedColumns 

The reason why we multiply by # of unmergedColumns is because we need a M portals to connect a row:
    However if a set columns has already been merged -> we can treat the set as just ONE column
        This is to prevent created cycles (useless edges)

The exact same logic can be applied when merging two columns      

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 3;

struct edge {
    int u, v, w;
    char type; // 'F' = flight, 'P' = portal
};

bool compareEdge(edge a, edge b) {
    return a.w < b.w;
}

int n, m, p, q;
vector<edge> edges;
ll totalWeight = 0; ll MSTWeight = 0;

void getInput() {
    cin>>n>>m>>p>>q;

    int a, b, c;
    for (int i=0;i<p;i++) {
        cin>>a>>b>>c;
        edges.push_back(edge{a, b, c, 'F'});
        totalWeight += (ll)c * (ll)n;
    }

    for (int i=0;i<q;i++) {
        cin>>a>>b>>c;
        edges.push_back(edge{a, b, c, 'P'});
        totalWeight += (ll)c * (ll)m;
    }
}

int parCol[MAXN], ranksCol[MAXN];
int parRow[MAXN], ranksRow[MAXN];

int root(int k, int* par) {
    while (k != par[k]) {
        par[k] = par[par[k]];
        k = par[k];
    }
    return k;
}

void initKruskals() {
    for (int i=1;i<MAXN;i++) {
        parCol[i] = i, ranksCol[i] = 1;
        parRow[i] = i, ranksRow[i] = 1;
    }

    sort(edges.begin(), edges.end(), compareEdge);
}

bool canMerge(int a, int b, int* par, int* ranks) {
    int rootA = root(a, par), rootB = root(b, par);

    if (rootA == rootB) return false; // merging would create cycle

    if (ranks[rootA] > ranks[rootB]) {
        par[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    } else {
        par[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    }

    return true;
}

void kruskals() {

    int unmergedRows = n, unmergedCols = m;

    for (auto e : edges) {
        if (unmergedCols==1&&unmergedRows==1) break;

        if (e.type=='F') { // connecting two columns
            if (canMerge(e.u, e.v, parCol, ranksCol)) {

                MSTWeight += (ll)e.w * (ll)unmergedRows;
                unmergedCols--;

            } 
        } else { // connecting two rows
            if (e.type=='P') {
                if (canMerge(e.u, e.v, parRow, ranksRow)) {

                    MSTWeight += (ll)e.w * (ll)unmergedCols;
                    unmergedRows--;

                }
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cin.tie(0);

    getInput();
    initKruskals();
    kruskals();

    ll ans = totalWeight - MSTWeight;
    cout<<ans<<"\n";
}