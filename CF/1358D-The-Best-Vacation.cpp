/*
~~~ 1358D - The Best Vacation ~~~

Key Concepts: Binary Search, PSA, implementation

Key Observations:
The optimal subsection will always end with the end of a month

Therefore we can just iterate throughe the end of every month
    - and use binary search to find the max sum from that end

The implementation is kinda yucky tho (or im just bad at consise code)


*/


#include<bits/stdc++.h>

typedef long long  ll;
using namespace std;
const int MAXN = 2e6 * 2 + 5;

ll n, x;

ll day[MAXN];
ll psa1[MAXN]; // psa for sum # of days in month
ll psa2[MAXN]; // psa from 1 - 1e6
ll psa3[MAXN]; // psa for sum of days from month l to r

ll rsq(int l, int r, ll* psa) {
    return psa[r] - psa[l-1];
}

// returns the left idx given the right side
ll bs(int idx) {
    int lo = 1, hi = idx, mid=-1, best=-1;

    while (lo<=hi) {
        mid = (lo + hi) / 2;

        if (rsq(mid, idx, psa1) <= x) {
            hi = mid - 1;
            best = mid;
        } else {
            lo = mid + 1;
        }
    }

    return best;
}

ll findMaxSum(int idx) {
    int bestLeft = bs(idx);

    ll taken;

    if (bestLeft==-1) taken = 0;
    else taken = rsq(bestLeft, idx, psa1);

    ll delta = x - taken;

    int leftIdx;    
    if (bestLeft==-1) leftIdx = idx;
    else leftIdx = bestLeft - 1;

    ll extraLeft;
    ll startDay = day[leftIdx] - delta + 1;

    if (leftIdx>=1) extraLeft = rsq(startDay, day[leftIdx], psa2);
    else extraLeft = 0;

    ll sumComplete;

    if (bestLeft == -1) sumComplete = 0;
    else sumComplete = rsq(bestLeft, idx, psa3);

    sumComplete += extraLeft;

    return sumComplete;
}


ll solve() {
    cin>>n>>x;

    for (int i=1;i<=n;i++) 
        cin>>day[i];

    // generate psa's

    for (int i=1;i<=1e6;i++) 
        psa2[i] = psa2[i-1] + i;
    
    for (int i=1;i<=n;i++) 
        psa1[i] = psa1[i-1] + day[i];
      
    
    // double the length for the psa for cyclic property
    for (int i=n+1;i<=2*n;i++) 
        psa1[i] = psa1[i-1] + day[i-n];
    
    // sum of day #'s from month L to R
    for (int i=1;i<=2*n;i++) {
        int mIdx = i % n;
        if (i==n) mIdx = n;

        psa3[i] = psa3[i-1] + rsq(1, day[mIdx], psa2);
    }

    ll ans = 0;
    for (int i=1;i<=2*n;i++) {
        ll maxSum = findMaxSum(i);

        ans = max(ans, maxSum);
    }

    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    ll ans = solve();
    cout<<ans<<"\n";
}