/*
~~~ 1195B - Sport Mafia ~~~

Key Concepts: binary search

very simple

there's probably a math way to solve it but whatever bs is easier

*/

#include<bits/stdc++.h>
using namespace std;

typedef double ll;

ll n, k;

ll candiesLeft(int numAte) {
    ll puts = n - numAte;

    ll ret = (puts + 1) * puts / 2 - (ll)numAte; 

    // ret might be negative
    return ret;
}

int solve() {
    int lo = 0, hi = n, mid;

    while (lo <= hi) {
        mid = (lo + hi) / 2;

        ll left = candiesLeft(mid);

        if (left == k)
            return mid;
        
        if (left<k) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return -1;
}

int main() {
    cin>>n>>k;

    int ans = solve();

    cout<<ans<<"\n";
}