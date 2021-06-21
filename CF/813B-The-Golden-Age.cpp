/*
~~~ 813B - The Golden Age ~~~

Key Concepts: BF, Math

Pretty ez bf problem
    -> just bf all possible values of a and b
        since they can be at most 60

    and then once you find all unlucky numbers
        -> you find the longest different between two unlucky numbers in the range l-r

    Be careful not to overflow boi!!!

*/


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
const ll MAXN = 1e18;
const ll MOD = 1e9 + 7;

set<ii> ranges;

void solve() {
    ld x, y, l, r;
    cin>>x>>y>>l>>r;
    
    ranges.insert({l, r});

    ld xPart, yPart;

    for (ld a=0;a<=62;a++) {
        xPart = pow(x, a);

        if (xPart > MAXN) break;

        for (ld b=0;b<=62;b++) {
            yPart = pow(y, b);

            if (xPart + yPart > MAXN) break;

            ll sum = (ll)xPart + (ll)yPart;

            ii del = {-1, -1};

            for (auto r : ranges) {
                if (r.f<=sum && sum <= r.s) {
                    del = r;
                    break;
                }
            }

            if (del != ii{-1, -1}) {

                ranges.erase(del);

                ranges.insert(ii{del.f, sum-1});
                ranges.insert(ii{sum+1, del.s});
            }

        }
    }

    ll maxLen = 0;

    for (auto r : ranges) {
        ll len = r.s - r.f + 1;
        maxLen = max(maxLen, len);
    }

    cout<<maxLen<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}