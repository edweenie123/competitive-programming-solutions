/*
~~~ UVa 10943 - How do you add? ~~~

Key Concepts: DP

Because problem requires the problem mod 1M, we have to mod 1M to every intermidiate calculation
*/

#include <bits/stdc++.h>

using namespace std;

int memo[101][101];

int ways(int n, int k) {
    if (k == 1) return 1;

    if (memo[n][k]!=-1) return memo[n][k];

    int sum = 0;
    for (int i=0;i<=n;i++)
        sum = (sum % 1000000 + ways(n-i, k-1)%1000000)%1000000;
    
    return memo[n][k] = sum;
}

int main() {
    int n, k;
    
    while(cin>>n>>k) {
        if (n==0&&k==0) break;
        memset(memo, -1, sizeof(memo));

        cout<<ways(n, k)<<endl;
    }
}