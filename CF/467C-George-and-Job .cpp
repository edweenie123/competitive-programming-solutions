/*
~~~ 467C - George and Job ~~~

Key Concepts: DP

Very simple DP -> once you realize its dp


*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e3 + 5;

int n, m, k;
ll arr[MAXN], psa[MAXN];
ll dp[MAXN][MAXN];

ll rsq(int l, int r) {
    return psa[r] - psa[l-1];
}

ll maxSum(int idx, int left) {
    if (left == 0) return 0;
    if (idx > n) return 0;
    if (dp[idx][left] != -1) return dp[idx][left];

    ll take = rsq(idx, idx + m -1) + maxSum(idx + m, left-1);
    ll notTake = maxSum(idx + 1, left);

    return dp[idx][left] = max(take, notTake);
}

int main() {
    cin>>n>>m>>k;

    for (int i=1;i<=n;i++) {
        cin>>arr[i]; psa[i] = psa[i-1] + arr[i];
    }

    for (int i=0;i<MAXN;i++) for (int j=0;j<MAXN;j++) dp[i][j] = -1;

    ll ans = maxSum(1, k);

    cout<<ans<<"\n";
}