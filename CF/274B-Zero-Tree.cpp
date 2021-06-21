/*
~~~ 274B - Zero Tree ~~~

Key Concepts: DP on tree

Difficult Tree DP problem that i don't really understand

First we must root the tree at 1 (because intuition)

Let DP[u] be {i, j} such that i and j and the minium # of add and sub operations
    needed to make the subtree rooted at u all 0

The dp recurance is as follows:
    DP[u] = {max(DP[v].first), max(DP[v].second)} for all children v of u
            if (the node value is positive) => increase DP[u].second
            else                            => increase DP[u].first

It kinda makes sense i guess?

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> llll;
const int MAXN = 1e5 + 5;

ll n, vals[MAXN];
vector<int> graph[MAXN];

// {increments, decrements} to make subtree u all 0
llll error(int u, int par) {

    ll totalAddCnt = 0;
    ll totalSubCnt = 0;

    for (auto v: graph[u]) {

        if (v == par) continue;

        llll child = error(v, u);

        totalAddCnt = max(totalAddCnt, child.first);
        totalSubCnt = max(totalSubCnt, child.second);
    }

    ll nodeVal = vals[u] + totalAddCnt - totalSubCnt;
    
    if (nodeVal < 0) totalAddCnt += abs(nodeVal);
    else             totalSubCnt += nodeVal;

    return {totalAddCnt, totalSubCnt};
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    int u, v;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1;i<=n;i++) cin>>vals[i];

    llll node1 = error(1, 0);
    ll ans = node1.first + node1.second;

    cout<<ans<<"\n";
}