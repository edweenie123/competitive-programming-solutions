/*
~~~ TLE '16 Contest 3 P4 - Gaussian Elimination ~~~

Key Concepts: Pattern Finding in DP

Using a normal DP solution will TLE because time complexity is O(NM)

The trick is to print the DP table to find a patten in the solutions
    - The DP table forms a checkerboard pattern!
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[51][51];

bool win() {
    for (int i=0;i<51;i++) dp[i][1] = 1;
    for (int i=0;i<51;i++) dp[1][i] = 1;

    for (int i=2;i<=n;i++) {
        for (int j=2;j<=m;j++) {
            dp[i][j] = !(dp[i-1][j] && dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int main() {
    cin>>n>>m;
    win();

    for (int i=1;i<15;i++) {
        for (int j=1;j<15;j++) {
            cout<<dp[i][j]<<" ";
        } cout<<endl;
    }
    if (n==1||m==1) cout<<"First"<<endl;
    else cout<<((n+m)%2==0 ? "Second" : "First")<<endl; 
}