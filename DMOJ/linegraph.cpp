#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii; 
typedef pair<int, ii> iii;
#define PB push_back
#define F first
#define S second 

const int MAXN = 1e5 + 5;

int n, k;
int par[MAXN], ranks[MAXN];
vector<iii> edges;

int root(int i) {
    while (i != par[i]) {
        par[i] = par[par[i]];
        i = par[i];
    }
    return i;
}

bool canMerge(int A, int B) {
    int rootA = root(A);
    int rootB = root(B);
    if (rootA==rootB) return false;
    
    if (ranks[A] > ranks[B]) {
        par[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    } else {
        par[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    }
    return true;
}

void initDSU () {
    for (int i=0;i<MAXN;i++) {
        ranks[i] = 1;
        par[i] = i;
    }
}

int kruskals() {
    sort(edges.begin(), edges.end());
    initDSU();

    int sum = 0;
    for (auto e : edges) {
        int v1 = e.S.F; 
        int v2 = e.S.S;
        int w = e.F;
        if (canMerge(v1, v2)) 
            sum += w;
    }

    return sum;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;

    int w;
    for (int i=0;i<n-1;i++) {
        cin>>w;
        edges.PB(iii(w, ii(i, i+1)));
        if (i+k<n) 
            edges.PB(iii(0, ii(i, i+k)));
    }
    
    int ans = kruskals();
    
    cout<<ans<<"\n";
}