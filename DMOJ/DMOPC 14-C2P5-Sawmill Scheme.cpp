/*
~~~ DMOPC '14 Contest 2 P5 - Sawmill Scheme ~~~

Key Concepts: Dynamic Programming

Fairly simple DP solution 

dp[i] stores the probability of a log getting to lake i
dp[i] = sum(dp[u]) for all lakes u which can reach lake i

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+1;

int n, m;
vector<int> graph[MAXN];
double dp[MAXN];

void solve() {
    dp[1] = 1.0;
    for (int i=1;i<=n;i++) {
        double numChild = graph[i].size();
        for (auto v : graph[i]) {
            dp[v] += dp[i]/numChild;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    int u, v;
    for (int i=0;i<m;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
    }

    solve();
    
    cout<<fixed; cout<<setprecision(9);
    
    for (int i=1;i<=n;i++) {
        if (graph[i].size()==0) {
            cout<<dp[i]<<"\n";
        }
    }
}