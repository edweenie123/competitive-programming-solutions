/*
~~~ 1362C - Johnny and Another Rating Drop ~~~

Key Concepts: yucky, Math

One of the most disgusting problems.

I honestly don't know how i solved this during the contest

I printed the first few terms of the sequence and somehow found a pattern


*/

#include<bits/stdc++.h>
using namespace std;

#define print(x) cout<<(#x)<<" = "<<x<<"\n";
typedef long long ll;

ll n;

ll solve() {
    cin>>n;
    n-=1;

    if (n==0) 
        return 1;
    

    ll tot = 0;

    for (int i=1;i<=63;i++) {
        ll modi = n - (1ll<<(i-1)) + 1;

        if (modi< 0) break;
        
        ll add = (modi / (1ll << i) + 1) * i;
        tot += add;
    }

    return tot;
}

int main() {
    int TC; cin>>TC;

    while (TC--) {
        ll ans = solve();
        cout<<ans<<"\n";
    }
}