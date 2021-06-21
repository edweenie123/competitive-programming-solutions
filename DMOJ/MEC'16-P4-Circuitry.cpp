/*
~~~ MEC '16 P4 - Circuitry ~~~

Key Concepts: Kruskal + Bridge finding algorithm

Group edges by their lengths and process each group all at once in Kruskals

If adding an edge leads to the creation of a cycle => edge is "not useful"

To find "useful" edges:
    Create a graph where verticies are connected components. 
    There exists a edge between verticies if there is an edge with length w connecting them
    Run a bridge finding algo to find the bridges in the graph:
        Bridges will always be "useful" edges

After finding all "useful" and "not useful" edges, then rest of the edges will be "so so" edges 
*/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef pair<iii, int> iiii;

const int MAXN = 510;

int n, m, freqL[100010], par[MAXN], ranks[MAXN];
vector<iiii> edges; // (len, (u, v), order)
vector<ii> bridgeGraph[MAXN];
int ans[250000]; // -1 = "not useful", 0 = "so so", 1 = "useful"

int root(int i) {
    while(i!=par[i]) {
        i = par[i];
    }
    return i;
}

void merge(int a, int b) {
    int rootA = root(a), rootB = root(b);

    if (ranks[rootA]<ranks[rootB]) {
        par[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    } else {
        par[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    }
}

bool makeCycle(int a, int b) {
    if (root(a)==root(b)) return true;
    else return false;
}

void init() {
    for (int i=0;i<MAXN;i++) {
        par[i] = i;
        ranks[i] = 1;
    }
}

int dfs_low[MAXN], dfs_num[MAXN], dfs_parent[MAXN], dfsNumCnt;
void findBridges(int u) {
    if (bridgeGraph[u].size()==0) return;
    dfs_low[u] = dfs_num[u] = dfsNumCnt++;
    
    int hits[MAXN];
    for (int i=0;i<MAXN;i++) hits[i] = 0;
    for (auto adj : bridgeGraph[u]) {
        int v = adj.F, order = adj.S;
        if (dfs_num[v]==-1) {
            dfs_parent[v] = u;

            findBridges(v);

        
            if (dfs_low[v] > dfs_num[u]) {
                ans[order] = 1; // bridge is definitely useful
            }
            
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (dfs_parent[u]!=v||hits[v]>0) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else 
            hits[v]++;
        
    }
}

void kruskal() {
    init();
    sort(edges.begin(), edges.end());
    
    int ind = 0;
    while (true) {
        if (ind>=m) break;

        iiii topE = edges[ind];
        int topEFreq = freqL[topE.F.F];
        
        for (int i=0;i<MAXN;i++) bridgeGraph[i].clear();
        for (int i=0;i<topEFreq;i++) {
            iiii e = edges[ind+i];
            int order = e.S;
            if (makeCycle(e.F.S.F, e.F.S.S)) {
                ans[e.S] = -1; // definitely not useful
            } else {
                int root1 = root(e.F.S.F), root2 = root(e.F.S.S);
                bridgeGraph[root1].push_back(ii(root2, order));
                bridgeGraph[root2].push_back(ii(root1, order));
            }
        }

        dfsNumCnt = 0;
        for (int i=0;i<MAXN;i++) {
            dfs_num[i] = -1;
            dfs_parent[i] = -1;
        }
        for (int i=0;i<MAXN;i++) {
            if (dfs_num[i]==-1) {
                findBridges(i);
            }
        }

        for (int i=0;i<topEFreq;i++) {
            iiii e = edges[ind+i];
            if (!makeCycle(e.F.S.F, e.F.S.S))
                merge(e.F.S.F, e.F.S.S);
        }
                
        ind += topEFreq;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    int a, b, l;
    for (int i=0;i<m;i++) {
        cin>>a>>b>>l;
        freqL[l]++;
        edges.push_back(iiii(iii(l, ii(a, b)), i));
    }

    kruskal();

    for (int i=0;i<m;i++) {
        if (ans[i]==-1) cout<<"not useful"<<"\n";
        else if (ans[i]==0) cout<<"so so"<<"\n";
        else if (ans[i]==1) cout<<"useful"<<"\n";
    }
}