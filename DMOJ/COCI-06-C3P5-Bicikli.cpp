/*
~~~ COCI '06 Contest 3 #5 Bicikli ~~~

Key Concepts: Graph Theory, DP

Fairly good graph theory / dp problem

*/

#include<bits/stdc++.h>
using namespace std; 

typedef long long ll;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9;

int n, m;
vector<int> graph[MAXN];
bool reach[MAXN];
int vis[MAXN];

ll dp[MAXN]; // dp[i] = # of ways to go from node i to the end

// gets all the nodes that can actually reach the end
void prune(int u) {
    if (vis[u]) return;

    vis[u] = true;
    for (auto v : graph[u]) {
        prune(v);

        // if one of u's children can reach the end, then u can reach the end
        if (reach[v]) reach[u] = true;
    }
}

bool overNine = false;
ll waysToEnd(int u) { // returns the # of ways to the end from node u
    if (!reach[u]) return 0;
    if (u == 2) return 1; // base case
    if (dp[u]!=-1) return dp[u]; // memoization speed up

    vis[u] = 1;

    ll ways = 0; 
    for (auto v : graph[u]) {
        // if there is cycle -> there are infinite paths
        if (vis[v] == 1) { // trying to visit an unparsed node that's already visited
            cout<<"inf\n";
            exit(0);
        }

        ways += waysToEnd(v);
        if (ways >= MOD) {
            overNine = true;
            ways %= MOD; // prevent overflow
        }
    }

    vis[u] = 2; // finished parsing for node u
    return dp[u] = ways;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    int a, b;
    for (int i=0;i<m;i++) {
        cin>>a>>b;
        graph[a].push_back(b);
    }

    reach[2] = true; // you can reach the end from the end
    prune(1);

    memset(vis, 0, sizeof(vis));
    memset(dp, -1, sizeof(dp));

    ll ans = waysToEnd(1);

    if (overNine) {
        // print the yucky leading zeros
        cout<<setfill('0')<<setw(9)<<ans%MOD<<"\n";
    } else {
        cout<<ans<<"\n";
    }
}