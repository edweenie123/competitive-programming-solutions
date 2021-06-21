/*
~~~ 287B - Pipelines ~~~

Key Concepts: Greedy, BS, Math

Insight 1:
The problem is basically just asking for a subset in:
    1,2,3,4,5,6,...,k-1     such that the sum is equal to n-1

Insight 2:
Notice that there is never a case where if we take a split that is too large
    we end up with a suboptimal answer
        -> this is just the nature of numbers 1,2,3,4,5,...k-1

Therefore we can take a greedy approach:
    -> we always take the largest pipe that we can until we have a sum of n-1

Insight 3:
Notice that the above algorithm implemented naively is too slow
    -> we can use binary search to speed it up!
    -> Notice that we sometimes take long chains of consecutive pipes 
        -> we can BS for the ending point of the chain!

*/



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;

// sum from pipe l to pipe r
ll rsq(ll l, ll r) {
    ll tot = (r + 1) * r / 2; 
    ll rem = (l) * (l-1) / 2;

    return tot - rem;
}

// returns idx such that rsq(idx, splitNum) <= rem
ll bs(ll splitNum, ll rem) {
    ll lo = 1, hi = splitNum, mid, best;

    while (lo <= hi) {
        mid = (lo + hi) / 2;

        ll addPipes = rsq(mid, splitNum);

        if (addPipes <= rem) {
            hi = mid - 1;
            best = mid;
        } else {
            lo = mid + 1;
        }
    }

    return best;
}

ll solve() {

    ll pipesWanted = n - 1;
    ll splitIdx = k - 1;

    // yucky edges cases
    if (rsq(1, splitIdx) < pipesWanted) return -1;
    if (pipesWanted == 0) return 0;

    splitIdx = min(pipesWanted, splitIdx);
    ll totalSplit = 0;

    while (true) {

        ll left = bs(splitIdx, pipesWanted);
        totalSplit += splitIdx - left + 1;

        pipesWanted -= rsq(left, splitIdx);
        if (pipesWanted == 0) break;
        splitIdx = pipesWanted;
    }   

    return totalSplit;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;

    ll ans = solve();
    cout<<ans<<"\n";
}