/*
~~~ 269B - Greenhouse Effect ~~~

Key Concepts: DP (LIS)

Very simple problem; i can believe i didn't solve it

Insight 0: 
The exact location of the plants doesn't matter
    -> only the order does
    -> the question is yucky for giving you useless information

Insight 1:
In the optimal solution, there will be some number K plants that we don't move
    -> To achieve the minimum number of moves, we want ot maximize K

Insight 2:
The K plants that we don't move initially are already in non-decreasing order
    -> since we want to maximize K, this is equivalent to find the LIS in the original arrangement

Therefore all we need to do is find the LIS in the arrangement
    -> and the answer is simply N - K

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 5;

int n, m;
int type[MAXN];
int dp[MAXN];

int LIS(int idx) {
    if (dp[idx] != -1) return dp[idx];

    int ans = 1;

    for (int i=1;i<idx;i++) 
        if (type[i] <= type[idx])
            ans = max(ans, LIS(i) + 1);
    
    return dp[idx] = ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    double tmp;
    for (int i=1;i<=n;i++) 
        cin>>type[i]>>tmp;    

    memset(dp, -1, sizeof(dp));

    int LISLen = 1;
    for (int i=1;i<=n;i++) LISLen = max(LISLen, LIS(i));
    
    int ans = n - LISLen;
    cout<<ans<<"\n";
}