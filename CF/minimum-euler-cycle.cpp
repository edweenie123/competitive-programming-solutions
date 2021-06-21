#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
const int MAXN = 1e5 + 5;



int cost[MAXN][3];
int colors[MAXN][3];

vector<int> graph[MAXN];

ll dfs(int u, int par, vector<int> cols, int lev) {

    int tot = 0;

    int root = cols[0];

    if (lev==1) 
        colors[u][root] = root;
    
    else if (lev==2) {
        ll alt1 = cost[u][cols[1]];
        ll alt2 = cost[u][cols[2]];
        for (auto v : graph[u]) {
            if (v == par) continue;
            alt1 += cost[v][cols[2]];
            alt2 += cost[v][cols[1]];
        }

        if (alt1 < alt2) {
            colors[u][root] = cols[1];
        }
        else {
            colors[u][root] = cols[2];

        }
    }

    else if (lev==3) {
        if (colors[par][root] == cols[1])
            colors[u][root] = cols[2];
        else 
            colors[u][root] = cols[1];
    }

    tot += cost[u][colors[u][root]];

    int nextLev = (lev+1)%3;
    if (nextLev==0) nextLev = 3;

    for (auto v : graph[u]) {

        if (v == par) continue;

        ll child = dfs(v, u, cols, nextLev);
        tot += child;
    }

    return tot;

}

int main() {
    int n;
    cin>>n;

    for (int i=0;i<3;i++) 
        for (int j=1;j<=n;j++)
            cin>>cost[j][i];
    
    int u, v;

    for (int i=0;i<n-1;i++) {
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ii root1 = {dfs(1, 0, {0, 2, 1}, 1), 0};
    ii root2 = {dfs(1, 0 , {1, 0, 2}, 1), 1};
    ii root3 = {dfs(1, 0, {2, 0, 1}, 1), 2};

    vector<ii> bois = {root1, root2, root3};
    sort(bois.begin(), bois.end());

    cout<<bois[0].first<<"\n";

    // cout<<bois[0].second<<" asdf \n";

    for (int i=1;i<=n;i++) {
        cout<<colors[i][bois[0].second]+1<<" ";
    } cout<<"\n";
}