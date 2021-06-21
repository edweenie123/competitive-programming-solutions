/*
~~~ 1286A - Garland ~~~

Key Concepts: DP

Very ez dp; there is also a greedy method apparrently

*/




#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 1e2 +5;
const ll MOD = 1e9 + 7;

int n;
int arr[MAXN];
int dp[MAXN][MAXN][MAXN][2];


int minComp(int idx, int o, int e, int lastPar) {
    if (idx>n) return 0;
    if (dp[idx][o][e][lastPar]!=-1) return dp[idx][o][e][lastPar];

    if (arr[idx]==0) {
        int putOdd = 1e9, putEven = 1e9;
        if (o) putOdd = minComp(idx+1, o-1, e, 1);
        if (e) putEven = minComp(idx+1, o, e-1, 0);

        if (lastPar==1) putEven++;
        if (lastPar==0) putOdd++;

        return dp[idx][o][e][lastPar] = min(putOdd, putEven);
    } else {

        int force = minComp(idx+1, o, e, arr[idx]%2);

        if (arr[idx]%2!=lastPar && lastPar!=-1) force++;

        return dp[idx][o][e][lastPar] = force;
    }
}   


void solve() {
    memset(dp, -1, sizeof(dp));

    cin>>n;

    int odds = n/2 + (n%2!=0);
    int evens = n/2;

    int val;
    for (int i=1;i<=n;i++) {
        cin>>arr[i];
        if (arr[i]!=0) 
            if (arr[i]%2==0) evens--;
            else odds--;
    }

    int ans = minComp(1, odds, evens, -1);

    cout<<ans<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}