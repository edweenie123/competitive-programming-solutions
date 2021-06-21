/*
~~~ 1373D - Maximum Sum On Even Positions ~~~

Key Concepts: Kadane's

Pretty ez variation on kadanes; i probably could have solved this in contest

Insight 1: Reversing an odd length subarray doesn't do anything
    -> this is pretty obv
    -> therefore we will only consider reversing even length subarrays

Insight 2: 
When you reverse an even length subarray:
    all even indices become odd and all odd indices become even
    Let k be the sum of all even indices
        l be the sum of all odd indices

    After the operation... 
        the total sum of even indices gets increased by (l-k)

Insight 3: 
If we pretend all even indices are negative -> we can use kadanes algorithm to find
    the subarray with the largest l-k value


*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5 + 5;

int nums[MAXN];
ll dp[MAXN][2];

ll kadane(int k, bool evenLen) {
    if (k == 0) {
        if (!evenLen) return nums[k];
        return 0;
    }

    if (dp[k][evenLen] != -1) return dp[k][evenLen];

    ll takeLast = 0, notTake = 0;

    if (evenLen) {
        takeLast = nums[k] + kadane(k-1, false);
    } else {
        takeLast = nums[k] + kadane(k-1, true);
        notTake = nums[k];
    }

    return dp[k][evenLen] = max(takeLast, notTake); 
}

ll solve() {
    int n;
    cin>>n;

    for (int i=0;i<=n;i++) 
        dp[i][0] = -1, dp[i][1] = -1;

    // int tmp;
    ll evenSum = 0;
    for (int i=0;i<n;i++) {
        cin>>nums[i];
        if (i%2==0) evenSum+=nums[i];
    }

    for (int i=0;i<n;i+=2) { // make all evens negative
        nums[i] = -nums[i];
    }

    ll bestSub = 0;

    for (int i=0;i<n;i++) {
        bestSub = max(bestSub, kadane(i, true));
    }

    return bestSub + evenSum;
}

int main() {
    int TC; cin>>TC;

    while (TC--) {
        ll ans = solve();
        cout<<ans<<"\n";
    }
}