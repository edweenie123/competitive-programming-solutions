/*
~~~ CCCHK '15 S1 - Finding number of pairs ~~~

Key Concepts: BS

Very ez bs problem, once you actually realize its bs

*/




#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll n, m;
vector<ll> a;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    ll tmp;
    for (int i=0;i<n;i++) {
        cin>>tmp; a.push_back(tmp);
    }

    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i=0;i<n;i++) {
        int bestJ = m - a[i];
        auto iter1 = a.begin() + i;
        auto iter2 = upper_bound(a.begin(), a.end(), bestJ) - 1;
        ll dist = iter2 - iter1;
        if (dist>0) ans = (ans + dist) % MOD;
    }

    cout<<ans<<"\n";
}