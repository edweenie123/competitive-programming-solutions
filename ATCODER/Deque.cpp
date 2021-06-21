/*
~~~ AtCoder Deque ~~~

Key Concepts: DP

The state transition isn't that intuitive but makes a lot of sense in hindsight


if you call maxDiff(l+1, r) or maxDiff(l, r-1)
    it returns the max difference for your opponent ie Y - X

    Because you wanna find X - Y, so you do -(Y - X) + val[l / r] to find X - Y

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 3e3 + 5;

int vals[MAXN];

ll dp[MAXN][MAXN];
// assuming you go first what is the max difference between X - Y
ll maxDiff(int l, int r) {
    if (l==r) return vals[l];

    if (dp[l][r] != -1) return dp[l][r];

    ll oppDiff1 = maxDiff(l+1, r);
    ll oppDiff2 = maxDiff(l, r-1);

    ll takeLeftScore = -oppDiff1 + vals[l];
    ll takeRightScore = -oppDiff2 + vals[r];

    ll bestDiff = max(takeLeftScore, takeRightScore);


    return dp[l][r] = bestDiff;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n;

    cin>>n;

    for (int i=1;i<=n;i++) 
        cin>>vals[i];
    
    memset(dp, -1, sizeof(dp));

    ll ans = maxDiff(1, n);
    cout<<ans<<"\n";
}