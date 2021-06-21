/*
~~~ 1337D - Xenia and Colorful Gems ~~~

Key Concepts: Sorting, binary search, implementation

Similar to athena on zanzibar island, but higher quality

Let x be the weight of the optimal red gem
    y be the weight of the optimal green gem
    z be the weight of the optimal blue gem

Golden idea: lets assume that x <= y <= z

For any given y, the best x is the greatest red gem <= y
                 the best z is the smallest blue gem >= y

Both of these can be found in log n using binary search

Given the constrant x<=y<=z, we can find the answer by iterating through all possible values of y
    -> this gives a total time complexity of O(n log n)

What if the optimal answer doesn't follow the constrant x <= y <= z?
    -> we brute force all possible orders (y <= x <= z, z <= y <= x...etc)

*/


#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define all(x) x.begin(), x.end()
typedef unsigned long long ll;
typedef vector<int> vi;

vi r, g, b;

ll minCost(vi mid, vi left, vi right) {

    ll bestCost = (1ll << 63ll);

    for (auto val : mid) {
        auto iterLeft = UB(all(left), val);
        if (iterLeft == left.begin()) continue;
        iterLeft--; // greatest elem >= val

        auto iterRight = LB(all(right), val); // smallest element >= val
        if (iterRight == right.end()) continue;

        ll x = *iterLeft, y = val, z = *iterRight;

        ll cost = (x-y)*(x-y) + (y-z)*(y-z) + (x-z)*(x-z);

        bestCost = min(bestCost, cost);
    }

    return bestCost;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        r.clear(), g.clear(), b.clear();
        
        int nr, ng, nb;
        cin>>nr>>ng>>nb;

        int tmp;

        for (int i=0;i<nr;i++) cin>>tmp, r.PB(tmp);
        for (int i=0;i<ng;i++) cin>>tmp, g.PB(tmp);
        for (int i=0;i<nb;i++) cin>>tmp, b.PB(tmp);
        
        sort(r.begin(), r.end());
        sort(g.begin(), g.end());
        sort(b.begin(), b.end());

        // try all possible orders 
        ll ans = minCost(r, g, b);
        ans = min(ans, minCost(b, g, r));
        ans = min(ans, minCost(g, r, b));
        ans = min(ans, minCost(b, r, g));
        ans = min(ans, minCost(g, b, r));
        ans = min(ans, minCost(r, b, g));

        cout<<ans<<"\n";    
    }
}