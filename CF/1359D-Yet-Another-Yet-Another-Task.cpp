/*
~~~ 1359D - Yet Another Yet Another Task ~~~

Key Concepts: Kadane's algorithm

Insight 1: Bob will always remove the maximum element in the subarray

Insight 2: assuming alice plays optimally the max element in the subarray is between 1-30

Lets assume that the max element in the optimal subarray is x...

We use kandanes algorithm to find the best subarray w/ this constraint
    - we ignore all elements > x
    - lets call S the max sub array sum 

The best score alice can get w/ this constraint is therefore S - x

Now we can simply iterate through all values of x and repeat this process to fine the optimal answer

NOTE that the max sumarray range may not actually contain x, but we can keep the score S - x
    because if it doesn't contain x (S - x) is smaller than the optimal answer! 

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
int arr[MAXN];
int dp[MAXN][31];

int kadane(int idx, int maxVal) {
    if (arr[idx] > maxVal)
        return 0;

    if (idx==1) 
        return max(0, arr[idx]);

    if (dp[idx][maxVal] != -1) return dp[idx][maxVal];
    
    return dp[idx][maxVal] = max(arr[idx], kadane(idx-1, maxVal) + arr[idx]);
}

int solve() {
    int ans = 0;

    for (int i=0;i<MAXN;i++)
        for (int j=0;j<=30;j++)
            dp[i][j] = -1;

    for (int mv=30;mv>=1;mv--) 
        for (int i=1;i<=n;i++) 
            ans = max(ans, kadane(i, mv) - mv);

    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=1;i<=n;i++) 
        cin>>arr[i];

    int ans = solve();
    cout<<ans<<"\n";
}