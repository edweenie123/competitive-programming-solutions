/*
~~~ DMOPC '14 Contest 3 P6 - Not Enough Time! ~~~

Key Concepts: Bottom-Up Knapsack

Use the "space saving trick" for bottom-up Knapsack

You only need the previous DP row to compute the current DP row

Therefore, your DP table only has to be 2 x t in size    
*/

#include <bits/stdc++.h>
using namespace std;

int n, t;
int prep[2005][3], value[2005][3], dp[2][10005];

int money() {
    for (int i=0;i<=t;i++) dp[0][t] = 0;

    for (int i=0;i<n;i++) {
        for (int j=0;j<=t;j++) {
            int ans = dp[0][j];

            for (int k=0;k<3;k++) 
                if (prep[i][k]<=j) ans = max(ans, value[i][k] + dp[0][j-prep[i][k]]) ;
            
            dp[1][j] = ans;
        }

        for (int j=0;j<=t;j++) dp[0][j] = dp[1][j];
    }

    return dp[1][t];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin>>n>>t;
    
    for (int i=0;i<n;i++) 
        for (int j=0;j<3;j++) 
            cin>>prep[i][j]>>value[i][j];

    cout<<money();       
}