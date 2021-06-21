/*
~~~ CCO '10 P2 - Tree Pruning ~~~

Key Concepts: Dynamic Programming

dp[u][e] = # of prunes needed to fix tree rooted at u with error e  

To build the dp table, traverse the tree with DFS
    If u has one child v: 
        dp[u][e] is simply dp[v][e]
    If u has 2 children v1 and v2: 
        each child could fix any portion of the error
        dp[u][e] = min(dp[v1][i] + dp[v2][e-i]) for i in range(0-e)  

*/

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e7;
const int MAXN = 300;

int N, D;
int color[MAXN]; // 0 = black, 1 = white
vector<int> tree[MAXN];
int delta[MAXN]; // delta[u] = change to current diff if you prune node u
int dp[MAXN][MAXN+MAXN]; // dp[u][e] = # of prunes needed to fix tree rooted at u with error e  
 

void dfs(int u) {
    if (tree[u].size()==0) {
        if (color[u]) delta[u] = -1; // remove a white
        else delta[u] = 1; // remove a black
        return;
    }
    for (auto v : tree[u]) {
        dfs(v);
        delta[u] += delta[v];
    }

    if (color[u]) delta[u]--; // node is white
    else delta[u]++; // node is black;
}

int minPrune(int u, int error) {
    if (error==0) return 0; // no error => no pruning
    if (error+delta[u]==0) return 1; // pruning node u yield correct D
    
    if (dp[u][error+MAXN]!=-1) return dp[u][error+MAXN];

    if (tree[u].size()==1) { // check if only child can fix error
        int nPrune = minPrune(tree[u][0], error);
        return dp[u][error+MAXN] = nPrune;
    } else if (tree[u].size()==2) { // each child can fix a different fraction of the error
        int ans = INF;
        for (int f=0;f<=abs(error);f++) {
            int nPrune1, nPrune2;
            if (error>0) {
                nPrune1 = minPrune(tree[u][0], f);
                nPrune2 = minPrune(tree[u][1], error-f);
            } else {
                nPrune1 = minPrune(tree[u][0], -f);
                nPrune2 = minPrune(tree[u][1], error+f);
            }
            ans = min(ans, nPrune1+nPrune2);
        }
        return dp[u][error+MAXN] = ans;
    }

    return dp[u][error+MAXN] = INF;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N>>D;

    int u, type, c, v;
    for (int i=0;i<N;i++) {
        cin>>u>>type>>c;
        color[u] = type;

        for (int j=0;j<c;j++) {
            cin>>v; tree[u].push_back(v);
        }
    }

    dfs(0);

    memset(dp, -1, sizeof(dp));
    int error = -delta[0] - D; // how far current diff is from D
    int ans = minPrune(0, error);

    cout<<(ans!=INF ? ans : -1)<<"\n";
}