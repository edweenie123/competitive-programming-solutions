/*
~~~ CCC '16 S4 - Combining Riceballs ~~~

Key Concepts: High IQ DP

DP(l, r) = {
    1   if riceball l-r can be combined into 1 riceball
    0   otherwise
}

Loop through all possible values of l and r 

- DP recurences -

DP(l, r) {
    1    if l==r
    1    if there exist k such that rSum(l, k) == rSum(k+1, r) AND DP(l, k) AND DP(k+1, r)
    1    if there exist a, b such that rSum(l, a) == rSum(b, r) AND DP(l, a) AND DP(b, r) AND DP(a+1, b-1)
    0    otherwise
}

Find pairs a, b can be done in O(n) using a two-pointer technique

Since we each recursive call's time complexity is O(n), the total time complexity is O(n^3) 

*/

#include <bits/stdc++.h>
using namespace std;

int n, psa[401], memo[401][401];

int rSum(int l, int r) {
    return psa[r] - psa[l-1];
}

bool dp(int l, int r) {
    if (l==r) return 1;

    if (memo[l][r]!=-1) return memo[l][r];

    for (int k=l;k<=r;k++) 
        if (rSum(l, k)==rSum(k+1, r)&&dp(l, k)&&dp(k+1, r)) 
            return memo[l][r] = 1;
    
    int a=l, b=r;
    while (true) {
        if (a>=b) return memo[l][r] = 0;

        int leftSum = rSum(l, a), rightSum = rSum(b, r);
        if (leftSum<rightSum) a++;
        else if (leftSum>rightSum) b--;
        else if (dp(l, a)&&dp(b, r)&&dp(a+1, b-1))
            return memo[l][r] = 1;
        else a++;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    int tmp;
    for (int i=1;i<=n;i++) {
        cin>>tmp;
        psa[i] = psa[i-1] + tmp;
    }

    for (int i=0;i<401;i++) for (int j=0;j<401;j++) memo[i][j] = -1;
    int ans = 0;
    for (int l=1;l<=n;l++) 
        for (int r=l;r<=n;r++) 
            if (dp(l, r)) 
                ans = max(ans, rSum(l, r));
    
    cout<<ans<<"\n";
}