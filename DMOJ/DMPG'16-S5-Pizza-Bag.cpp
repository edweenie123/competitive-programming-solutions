/*
~~~ DMPG '16 S5 - Pizza Bag ~~~

Key Concepts: RMQ, PSA

High IQ problem

Treat the pizza as a line to simplify

Construct a PSA using the pizza's deliciousness level

The best sector of pizza you can take ending at pizza e is:
    minVal = min(PSA[i] | for i in (e-k-1, e))
    PSA[e] - minVal

Thus we have to compute the minVal foreach e -> sliding range minimum query

This can be solved in O(n log n) using a set, but can also be done in O(n) using a deque
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 1;

int n, k;
ll psa[MAXN*2], arr[MAXN];
multiset<ll> dVals;

ll RMQ() {
    ll ans = 0;

    for (int i=1;i<=k;i++) dVals.insert(psa[i]);
    for (int i=k+1;i<=n*2;i++) {
        ll minVal = *dVals.begin();
        ans = max(ans, psa[i] - minVal);
        dVals.erase(psa[i-k]);
        dVals.insert(psa[i+1]);
    }

    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;

    for (int i=0;i<n;i++) cin>>arr[i];

    for (int i=1;i<=2*n;i++) {
        psa[i] = psa[i-1] + arr[(i-1)%n];
    }

    cout<<RMQ()<<"\n";
}