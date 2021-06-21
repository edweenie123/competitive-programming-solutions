/*
~~~ 325B - Statdium and Games ~~~

Key Concepts: BS, Math

Insight 1:
Let x be the # of teams when you do the round robin
    y be the # of round where case 1 is true (you halve the teams)

Use the sum of geometric series to get:

    x(x-1)/2 + x*(2^y-1) = n

    x + x(2^y-1) = # of teams at beginning

Notice that if we know one of the variables (x / y), we can calculate the other

Since the bound for x are super high (1414213563):
    we will instead iterate through y (the max value of y is 63 since it increases expontially)

    Once we know y, we can use binary search to find the value of x

    alternatively we could use quadratic formula to directly compute the value of x
        but binary searching is easier
    
    Becareful for the bounds of x when you're binary searching or you might overflow!!!


*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef unsigned long long ll;
typedef pair<int, int> ii;
const ll MAXN = 1e18;
const ll MOD = 1e9 + 7;

ll n;
set<ll> ans;

ll calcN(ll x, ll y) {
    return x*((1ll<<y)-1) + x*(x-1)/2;
}

void bs(ll y) {
    ll lo = 0, hi = 1414213563, mid;

    ll xVal=-1;

    while (lo <= hi) {
        // print(mid);
        ll mid = (lo+hi) / 2;

        ll maybeN = calcN(mid, y);
        if (maybeN < n) 
            lo = mid + 1;
        else if (maybeN > n) 
            hi = mid - 1;
        else {
            if (mid % 2 == 1) // x must be odd
                xVal = mid;
            break;
        }
    }

    if (xVal!=-1) {
        ll teams = xVal + xVal * ((1ll<<y)-1);
        ans.insert(teams);
    }
}

void solve() {
    cin>>n;

    // x * (2^y - 1) + x(x-1)/2 = n

    for (int y=0;(1ll<<y)<=MAXN;y++) {
        bs(y);
    }

    if (ans.empty()) {
        cout<<"-1\n"; return;
    } else {
        for (auto a : ans) cout<<a<<"\n";
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}