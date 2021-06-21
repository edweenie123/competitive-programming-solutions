/*
~~~ UVa 11450 - Wedding Shopping ~~~

Key Concepts: Dynamic Programming


*/
#include <bits/stdc++.h>

using namespace std;

int tests, m, c;

int memo[201][20], prices[20][21];

int dp(int money, int g) {
    if (money<0) return -1e9;
    if (g==c) return m-money;

    if (memo[money][g]!=-1) return memo[money][g];

    int ans = -1;
    for (int i=1;i<=prices[g][0];i++) 
        ans = max(dp(money-prices[g][i], g+1), ans);
    
    memo[money][g] = ans;
    return ans;
}

int main() {
    // freopen("input.txt", "r", stdin);

    cin>>tests;
    while(tests--) {
        cin>>m>>c;

        int k;
        for (int i=0;i<c;i++) {
            cin>>k;
            prices[i][0]=k;
            for (int j=1;j<=k;j++) {
                cin>>prices[i][j];
            }
        }

        memset(memo, -1, sizeof(memo));

        int ans = dp(m, 0);

        ans < 0 ? cout<<"no solution" : cout<<ans;
        cout<<endl;
    }
}