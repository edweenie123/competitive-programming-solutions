/*
~~~ IOI '94 P1 - The Triangle ~~~

Key Concepts: DP

Very simple DP

*/

#include<bits/stdc++.h>
using namespace std;

int dp[101][101];
int tri[101][101];
int n;

int maxSum(int i, int j) {

    if (dp[i][j]!=-1) return dp[i][j];
    if (i == n-1 && tri[i][j]!=-1)
        return tri[i][j];
    
    int ans = 0;

    if (tri[i+1][j]!=-1)
        ans = max(ans, tri[i][j] + maxSum(i+1, j));
    if (tri[i+1][j+1]!=-1)
        ans = max(ans, tri[i][j] + maxSum(i+1, j+1));

    return dp[i][j] = ans;   
}

int main () {
    cin>>n;

    for (int i=0;i<101;i++) {
        for (int j=0;j<101;j++) {
            tri[i][j] = -1;
            dp[i][j] = -1;
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<i+1;j++) {
            cin>>tri[i][j];
        }
    }

    int answer = maxSum(0, 0);

    cout<<answer<<endl;
}