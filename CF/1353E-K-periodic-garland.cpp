/*
~~~ 1353E - K-periodic Garland ~~~

Key Concepts: DP

Pretty simple dp actually

omg i was trolled by memset and wasted a lot of time debugging

heres the scoop...

i used memset to reset the dp array (and lamp array) after every test case

however, because memset resets the ENTIRE array, the time complexity is O(1e6)
    - we only need to reset the first N element tho

this caused by to TLE because there can be 25000 test cases
    - O(25000 * 1e6) is way too large


Time Complexity O(n)


*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int n, k;
int lamps[MAXN], psa[MAXN];

int rsq(int l, int r) {
    return psa[r] - psa[l-1];
}

int dp[MAXN];

int minMoves(int idx) {
    if (idx==n) return !lamps[idx];
    if (idx>n) return 0;

    if (dp[idx]!=-1) return dp[idx];

    // place another lamp to the right (dist k away)
    int goNext = rsq(idx+1, min(idx+k-1, n)) + minMoves(idx+k) + !lamps[idx];

    // kill all lamps to the right
    int done = rsq(min(idx+1, n), n) + !lamps[idx];

    return dp[idx] = min(goNext, done);
}


int solve() {
    for (int i=1;i<=n;i++) 
        dp[i] = -1;

    int best = 1e9;

    // decide where to start the lamp chain
    for (int i=1;i<=n;i++) {
        int maybeBest = max(rsq(1, i-1), 0) + minMoves(i);

        best = min(best, maybeBest);
    }

    // edge case: you turn everything off
    best = min(best, rsq(1, n));

    return best;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        cin>>n>>k;

        for (int i=1;i<=n;i++)
            lamps[i] = 0;
        
        char c;
        for (int i=1;i<=n;i++) {
            cin>>c;
            if (c=='1') 
                lamps[i] = 1;
            
            psa[i] = psa[i-1] + lamps[i];
        }

        int ans = solve();

        cout<<ans<<"\n";
    }
}

