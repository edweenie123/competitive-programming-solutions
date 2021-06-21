/*
~~~ 983B XOR-pyramid ~~~

Key Concepts: DP, XOR

Kinda interesting problem -> you have to do two dps
    => the first insight you have to make is kinda dumb tho

Insight 1:
Let dp(l, r) be the answer to f(a[l],...,a[r])

Through some yucky observations about the nature of XOR
    you realize that dp(l, r) = dp(l+1, r) ^ dp(l, r+1)

Insight 2:
Now that we have a efficient method of finding the value of f for every range
    -> given l and r we have to find the largest f of every segemnt within the range [l, r]

We can do this pretty simply with another dp

*/


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 5e3 + 5;
const ll MOD = 1e9 + 7;

int n;
int a[MAXN];

int dp[MAXN][MAXN];
int dpMAX[MAXN][MAXN];

int calcF(int l, int r) {
    if (l==r) return a[l];

    if (dp[l][r] != -1) return dp[l][r];

    int left = calcF(l, r-1);
    int right = calcF(l+1, r);

    return dp[l][r] = left ^ right;
}

int calcMax(int l, int r) {
    if (l==r) return a[l];

    if (dpMAX[l][r] != -1) return dpMAX[l][r];


    int leftMax = calcMax(l, r-1);
    int rightMax = calcMax(l+1, r);

    int entire = calcF(l ,r);

    return dpMAX[l][r] = max({leftMax, rightMax, entire});
}

void solve() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];

    memset(dp, -1, sizeof(dp));
    memset(dpMAX, -1, sizeof(dpMAX));

    int q; cin>>q;
    while (q--) {
        int l, r; cin>>l>>r;

        int ans = calcMax(l, r);
        cout<<ans<<endl;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}