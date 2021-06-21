/*
~~~ DMOPC '15 Contest 3 P4 - Contagion ~~~

Key Concepts: Dijkstra, Binary Search

Use classical variant of Dijkstra to optimize speed (for dense graphs, classical is better)

After dijsktra, sort the distance array and use binary search to answer queries in log n time
*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
typedef long long ll;
typedef pair<ll,ll> llll;
typedef pair<ll, int> lli;
const ll INF = 1e17;
const int MAXN = 3e3+5;

int n, q, src, vis[MAXN];
ll dist[MAXN];
vector<llll> cord;
ll graph[MAXN][MAXN];

void dijkstra() {
    for (int i=0;i<MAXN;i++) dist[i] = INF;
    for (int i=0;i<MAXN;i++) vis[i] = 0;
    dist[src] = 0;

    for (int i=1;i<=n;i++) {
        int u = 0;
        for (int j=1;j<=n;j++) 
            if (!vis[j]&&dist[j]<dist[u])
                u = j;
        

        vis[u] = 1;

        for (int v=1;v<=n;v++) {
            ll w = graph[u][v];

            if (!vis[v]&&dist[u]+w<dist[v]) 
                dist[v] = dist[u] + w;            
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin>>n;
    long long x, y;
    for (int i=0;i<n;i++) {
        cin>>x>>y;
        cord.PB(llll(x, y));
    }
    cin>>src;

    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            ll dist = pow(cord[i].F-cord[j].F, 2) + pow(cord[i].S-cord[j].S, 2);
            graph[i+1][j+1] = dist;
            graph[j+1][i+1] = dist;
        }
    }

    dijkstra();
    sort(dist, dist+n+1);

    cin>>q;
    ll hours;
    for (int i=0;i<q;i++) {
        cin>>hours;
        int ans = upper_bound(dist, dist+n, hours) - dist;
        cout<<ans<<"\n";
    }
}