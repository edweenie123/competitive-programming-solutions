/*
~~~ 1401D - Maximum Distributed Tree ~~~

Key Concepts: Greedy, DFS

Glad i guessed the greedy sol during the contest

I didn't know the m numbers were prime so i wasted time implemting sieve for prime factorization

Insight 1:
The number of times an edge (u, v) is used distribuation index 
    is x * y

    where x is the size of the subtree of u
    and y is the size of the subtree of v

We can calculate this value for every edge using a simple dfs

Therefore we should put our best edge weights on the edges with the highest frequency

Insight 2:
Now the issue is figuring out how to distribute the edge weights optimally
    such that their product is k

Through some intuition is guessed that it is optimal to try to maximize a single edge

    This makes sense as multipling two numbers together is better than adding

        -> idk how to prove this stuff, but it makes sense intuitively

Therefore we just try to make the largest edge weight possible
    by sorting the prime factors of k
        and combining all the factors at the end together

*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 1e5 + 5;
const int MAXX = 6e4 + 5;
const ll MOD = 1e9 + 7;

int n;
vector<int> graph[MAXN];
vector<ll> edgeFreq;
vector<ll> factors;

ll stsz[MAXN];

void dfs(int u, int par) {
    stsz[u] = 1;

    for (auto v : graph[u]) {
        if (v==par) continue;
        dfs(v, u);
        stsz[u] += stsz[v];
    }

    ll useFreq = stsz[u] * (n - stsz[u]);
    if (useFreq!=0)
        edgeFreq.push_back(useFreq);
}


void solve() {
    cin>>n;

    for (int i=0;i<=n+3;i++) graph[i].clear();

    edgeFreq.clear();
    factors.clear();

    for (int i=0;i<=n+3;i++) stsz[i] = 0;

    int u, v;
    for (int i=1;i<=n-1;i++) {
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);
    sort(edgeFreq.begin(), edgeFreq.end());

    int m, p;
    cin>>m;
    for (int i=0;i<m;i++) {
        cin>>p;
        factors.push_back(p);
    }

    while (factors.size() < n-1) {
        factors.push_back(1);
    }

    sort(factors.begin(), factors.end());

    while (factors.size() > n-1) {
        ll last = factors[factors.size()-1];
        ll last2 = factors[factors.size()-2];

        ll prod = (last * last2) % MOD;

        factors.pop_back();
        factors.pop_back();
        factors.push_back(prod);
    }

    ll ans = 0;

    for (int i=0;i<n-1;i++) 
        ans = (ans + factors[i] * edgeFreq[i]) % MOD;
    
    cout<<ans<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); 
    int TC; cin>>TC;

    while (TC--) {
        solve();
    }
}