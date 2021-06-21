/*
~~~ 1379C - Choosing Flowers ~~~

Key Concepts: Greedy, BS, BF

I'm sad i couldn't solve this during the contest
    -> i couldn't find the edge case for my greedy sol

Insight 1:
The optimal solution can always consist for picking the same flower for the b's
    -> think about it and it will make sense

    Note the optimal b flower is not necessarily the one with the max b value
        -> because the max b flower can have a really shit a value

Insight 2:
Let's fix the b flower...
    Now we need to find the rest of our selections,
        because there is only one b flower, we need to find all the a flowers which could increase our score

    Pretty obviously,
        it is optimal to pick all the flowers with an a value > than the b flower's b value

    Thus the strat is to:
        pick all flower's w/ a val > b flower's b value
        after you do that, you get the b flower until you reach n flowers


We can implement the strat in O(n log n) time
    using psa and bs => the implementation is pretty trivial
        -> be careful not to overcount the a value for the b flower

Why did i get confused??
    I got insight 1, but i got insight 2 wrong:
        for insight 2, i only got a flowers that were larger than the max b value
            but, in actuality i should have got all a flowers that were larger than the CURRENT b value


*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<ll, ll> ii;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

ii flows[MAXN];
ll first[MAXN];
ll psa[MAXN];

ll n, m;

void solve() {
    cin>>n>>m;

    ll a, b;
    for (int i=1;i<=m;i++) {
        cin>>a>>b;

        first[i] = a;
        flows[i] = {a, b};
    }
     
    sort(first+1, first+m+1);

    for (int i=1;i<=m;i++) {
        psa[i] = psa[i-1] + first[i];
    }

    ll ans = 0;

    for (int i=1;i<=m;i++) {
        ll a = flows[i].f;
        ll b = flows[i].s;

        ll idx = upper_bound(first+1, first+1+m, b) - (first);

        ll totHap = 0;

        int take = min(n, m-idx+1);

        totHap += psa[m] - psa[m-take];

        int left = n - take;

        if (left > 0) {
            if (a <= b) {
                totHap += a;
                totHap += (left-1) * b;
            } else 
                totHap += left * b;
        }

        ans = max(ans, totHap);
    }

    cout<<ans<<"\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        solve();
    }
}