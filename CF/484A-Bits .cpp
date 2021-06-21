/*
~~~ 484A - Bits ~~~

Key Concepts: constructive algorithm, greedy, bitmask

The greedy solution to maximize the bits is pretty ez to come up with

*/


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

void solve() {
    ll l, r;
    cin>>l>>r;

    ll val = l;

    for (int i=0;i<=60;i++) {
        ll newVal = val | (1ll<<i);
        if (newVal <= r) 
            val = newVal;
        else 
            break;
    }

    cout<<val<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        solve();
    }
}