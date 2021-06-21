#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
typedef long long ll;

int n, h;

vector<ll> boiHouse;

ll fuelCost(int l, int r) {
    return (boiHouse[l] - boiHouse[r]) * (boiHouse[l] - boiHouse[r]);
}

ll dp[MAXN];
// returns cheapest amount to clear criminals 0->idx
ll cheapest(int idx) {
    if (idx==0) return h;
    if (dp[idx]!=-1) return dp[idx];

    ll best = fuelCost(0, idx) + h, potential;

    // try all possible locations of placing a police boi
    for (int i=0;i<idx;i++) {
        potential = cheapest(i) + fuelCost(i+1, idx) + h;
        best = min(best, potential);
    }

    return dp[idx] = best;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>h;

    int tmp;
    for (int i=0;i<n;i++) {
        cin>>tmp; boiHouse.push_back(tmp);
    }

    for (int i=0;i<MAXN;i++) dp[i] = -1;
    ll ans = cheapest(n-1);

    cout<<ans<<"\n";
}