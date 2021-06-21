/*
~~~ 161D - Distance in Tree ~~~

Key Concepts: DP, DFS

I struggled on this problem 
    the dp state is not intuitive to come up with
    and using the dp table to find the answer is also not that intuitive

dp[u][l] stores the # of nodes that have a distance of l from node u 
    -> ** this only counts nodes that have node u as an ancestor

The recurrence is pretty simple its just dp[u][l] += dp[v][l-1] for every dist l and every child v

Here comes the tricky part...

Notice that if a node u has x paths with a distance of i
    AND y paths with a distance of k-i AND the two sets of paths are contained within different children
        -> we can build x * y paths of length k using these two sets 

Therefore we can iterate over all values of x to find the number of paths of length kwhich use node u
    as a "bending point".

    Note: we have to divide the sum by 2 before we add to the global total because the path (a, b) is the same (b, a)


*/



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e4 + 5;
const int MAXK = 5e2 + 5;
int n, k;
vector<int> graph[MAXN];

int distCnt[MAXN][MAXK];

ll pairCnt = 0;

void dfs(int u, int par) {
    distCnt[u][0] = 1;

    for (auto v: graph[u]) {
        if (v == par) continue;

        dfs(v, u);

        for (int i=1;i<MAXK;i++) {
            distCnt[u][i] += distCnt[v][i-1];
        }
    }

    ll cnt = 0;
    for (auto v : graph[u]) {
        if (v == par) continue;
        for (int i=1;i<k;i++) {
            ll childPos = distCnt[v][i-1]; // child
            ll parentPos = distCnt[u][k-i] - distCnt[v][k-i-1]; // par pos

            cnt += childPos * parentPos;
        }

    }
    cnt /= 2;
    cnt += distCnt[u][k];
    pairCnt += cnt;

}

int main() {
    cin>>n>>k;

    int u, v;

    for (int i=0;i<n-1;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);
    cout<<pairCnt<<"\n";
}