/*
~~~ 1027D - Mouse Hunt ~~~

Key Concepts: DFS

Insight 1: 
All nodes eventually lead to a cycle
    -> draw examples out to see this

Insight 2:
We will always have to put a trap in all of the cycles
    -> doing this also resolves all the other nodes since they lead to the cycle

Thus we must pick a cheapest trap in each cycle and place it there

Insight 3:
We can use a simple cycle detection dfs algorithm to find all the cycles
    -> then we can simply sort all nodes within each cycle by their cost and pick the cheapest one


*/

#include<bits/stdc++.h>
using namespace std;

#define PB push_back
typedef vector<int> vi;
const int MAXN = 2e5 + 5;

int n;
int cost[MAXN];
int nxt[MAXN];
int vis[MAXN];

vector<vi> allCycleCosts;

void dfs(int u) {

    vis[u] = 1; // processing
    
    int v = nxt[u];
    if (vis[v] == 1) { // found cycle
        vi cycleCosts;

        cycleCosts.PB(cost[u]);

        int bro = v;
        while (true) {
            if (bro == u) break;
            cycleCosts.PB(cost[bro]);
            bro = nxt[bro];
        }
        allCycleCosts.PB(cycleCosts);
    } else if (vis[v] == 0)
        dfs(v);

    vis[u] = 2; // finished processing
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=1;i<=n;i++) 
        cin>>cost[i];
    
    for (int i=1;i<=n;i++)
        cin>>nxt[i];

    for (int i=1;i<=n;i++)
        if (!vis[i]) dfs(i);

    int ans = 0;

    // put a trap in every cycle

    for (auto c : allCycleCosts) {
        sort(c.begin(), c.end());
        ans += c[0];
    }

    cout<<ans<<"\n";
}