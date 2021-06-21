/*
~~~ 580D - Kefa and Dishes ~~~

Key Concepts: Travelling Salesman DP

This is bascially the same thing as finding the longest path in a graph
    -> which can be done with the travelling salesman dp

except you can only visit m nodes

Same idea is also used in CCO '15 P2 - Artskjid

*/



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> ii;
const int MAXN = 18;
const ll MOD = 1e9 + 7;

int n, m, k;
int arr[MAXN];
vector<ii> rules[MAXN];

ll dp[(1<<MAXN)+5][MAXN];

ll maxSatification(int vis, int cur) {
    // can only take m dishes
    if (__builtin_popcount(vis)==m) return 0;

    if (dp[vis][cur] != -1) return dp[vis][cur];

    ll best = 0;
    for (int i=0;i<n;i++) {
        if ((1<<i) & vis) continue; // don't go to visited nodes

        ll pot = arr[i] + maxSatification(vis | (1<<i), i);
        
        for (auto r : rules[cur]) {
            if (r.f == i) {
                pot += r.s;
                break;
            }
        }

        best = max(best, pot);
    }

    return dp[vis][cur] = best;
}


void solve() {
    memset(dp, -1, sizeof(dp));
    cin>>n>>m>>k;

    for (int i=0;i<n;i++) cin>>arr[i];

    int x, y, c;
    for (int i=0;i<k;i++) {
        cin>>x>>y>>c;
        rules[x-1].push_back({y-1, c});
    }

    ll ans = 0;

    for (int i=0;i<n;i++) // try starting at every node
        ans = max(ans, maxSatification((1<<i), i) + arr[i]);

    cout<<ans<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}