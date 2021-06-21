/*
~~~ DMOPC '15 Contest 5 P4 - Steins;Number ~~~

Key Concepts: Bitmasks, Binary Search

The key is to represent steins numbers as a bitmask
    where each bit represents where or not a power of 3 is present in the sum

We can use binary search to find the first bm that is >= L      A
We can do the same thing to find the first bm that is <= R      B

Through observation, we realize that the number of steins numbers in [L, R] is
    B - A + 1

*/

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int MAXPOW = 38; // 3^37 is the largest power of 3 that <= 1e18

ull POW3[MAXPOW + 1];

// converts a bitmask to a steins number
ull bmToSn(ull bm) {
    ull total = 0;
    for (int i=0;i<=MAXPOW;i++) 
        if ((1ULL << i) & bm)
            total += POW3[i];
    
    return total;
}


// returns the smallest bm that gives a steins number >= k
ull bsGreaterEquals(ull k) {
    ull lo = 0, hi = (1ULL<<(MAXPOW+1)) - 1, mid, best = -1;

    while (lo <= hi) {
        mid = (lo + hi)/2 ;

        if (bmToSn(mid) >= k) {
            best = mid;
            hi = mid - 1;
        } else 
            lo = mid + 1;
    }

    return best;
} 

// returns the greatest bm that gives a steins number <= k
ull bsLessEquals(ull k) {
    ull lo = 0, hi = (1ULL<<(MAXPOW+1)) - 1, mid, best = -1;

    while (lo <= hi) {
        mid = (lo + hi)/2 ;

        if (bmToSn(mid) <= k) {
            best = mid;
            lo = mid + 1;
        } else 
            hi = mid - 1;
    }

    return best;
}


// find the # of steins numbers between l and r
ull steinsNumberCnt(ull l, ull r) {

    ull smallestBm = bsGreaterEquals(l);
    ull largestBm = bsLessEquals(r);

    ull ans = largestBm - smallestBm + 1;

    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    // precompute the powers of 3
    POW3[0] = 1;
    for (int i=1;i<=MAXPOW;i++)
        POW3[i] = POW3[i-1] * 3;
    
    int q; cin>>q;

    ull l, r;
    while (q--) {
        cin>>l>>r;

        ull ans = steinsNumberCnt(l, r);
        cout<<ans<<"\n";
    }
}