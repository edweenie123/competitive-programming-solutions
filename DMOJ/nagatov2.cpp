/*

Root the tree arbitarily at any node

Step 1: Generate dp_down[i] => gives the longest path from node i if you go down the tree

Step 2: 

*/






// #include<bits/stdc++.h>
// using namespace std;

// const int MAXN = 5e5 + 5;

// int n;
// int par[MAXN], down[MAXN];

// vector<int> tree[MAXN];

// void dfs1(int u) {
//     int maxDist = 0;
    
//     for (auto v : tree[u]) {
//         if (v == par[u]) continue;
//         par[v] = u; 

//         dfs1(v);

//         maxDist = max(down[v] + 1, maxDist);
//     }
//     down[u] = maxDist;
// }

// int main() {
//     cin>>n;

//     int u, v;
//     for (int i=0;i<n-1;i++) {
//         cin>>u>>v;
//         tree[u].push_back(v);
//         tree[v].push_back(u);
//     }


// }

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define SIZE 500005

int n;
vector<vector<int>> adj(SIZE);
int path1[SIZE]; // longest path
int index1[SIZE];
int path2[SIZE]; // second longest path
int longest[SIZE];

void dfs(int i, int prev){
    for(int x = 0; x < adj[i].size(); x++){
        int next = adj[i][x];
        if(prev != next){
            dfs(next, i);
            if(path1[next] + 1 > path1[i]){
                path2[i] = path1[i];
                path1[i] = path1[next] + 1;
                index1[i] = x;
            }else if(path1[next] + 1 > path2[i]){
                path2[i] = path1[next] + 1;
            }
        }
    }
    path1[i] = max(path1[i], 0);
}

int dp(int i, int prev, int maxV){
    longest[i] = max(maxV, path1[i]);
    for(int x = 0; x < adj[i].size(); x++){
        int next = adj[i][x];
        if(next == prev)
            continue;
        if(x == index1[i])
            dp(next, i, max(maxV, path2[i]) + 1);
        else
            dp(next, i, max(maxV, path1[i]) + 1);
    }
}

int main(){
    scanf("%d", &n);
    for(int x = 0; x < n; x++){
        path1[x] = path2[x] = - (1 << 30);
    }
    for(int x = 0; x < n-1; x++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0, -1);
    dp(0, -1, 0);
    for(int x = 0; x < n; x++)
        printf("%d\n", longest[x]+1);
    return 0;
}