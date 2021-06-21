/*
~~~ UVa 00315 - Network ~~~

Key Concepts: Articulation Points 

Trivial implementation of finding arituclation points

Took a long time because I'm stupid and don't understand the algorithm
    - copied from the template, but it turns out I wrote the template wrong :(
*/

#include <bits/stdc++.h>

using namespace std;

int n;

int dfs_num[101], dfs_low[101], dfsIterCnt, parent[101], dfsRoot, rootChildCnt;
bool isAP[101];
vector<int> graph[101];

void dfs(int u) {
    dfs_low[u] = dfs_num[u] = dfsIterCnt++;


    for (auto v : graph[u]) {
        if (dfs_num[v]==-1) {
            parent[v] = u;

            if (u==dfsRoot) rootChildCnt++;
            dfs(v);

            if (dfs_low[v]>=dfs_num[u]) 
                isAP[u] = true;
            
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (parent[u]!=v) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }  
    }
}

int main () {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    while (cin>>n) {
        if (n==0) break;

        for (int i=0;i<101;i++) {
            dfs_num[i]=-1;
            parent[i] = 0;
            isAP[i] = false;
            graph[i].clear();
        }
        dfsIterCnt = 0;

        string line;
        while (getline(cin, line)) {
            if (line=="0") break;
            
            stringstream ss(line);
            int u, v;
            ss>>u;
            while (ss>>v) {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        for (int i=1;i<=n;i++) {
            if (dfs_num[i]==-1) {
                dfsRoot = i;
                rootChildCnt = 0;
                dfs(i);
                isAP[dfsRoot] = rootChildCnt > 1;
            }
        }

        int APCnt = 0;

        for (int i=1;i<=n;i++) 
            if (isAP[i]) APCnt++;
        
        cout<<APCnt<<"\n";
    }
}