/*
~~~ 1393D - Rarity and New Dress ~~~

Key Concepts: DP

i totally could have solved this during the contest
    -> i didn't see that the other directions mattered as well!!!!

My code here is quite disgusting tho; there probably a more elegant way of doing it but whatever

The main idea is the find the largest valid square that can be w/ a center of [i, j]
    -> we do this for every [i, j]
    -> lets call this value f[i, j]

The answer is simply just the sum of all f[i, j] for every i and j

The thing i messed up was the dp recurrence for finding f[i, j]
    -> i only considered 2 directions, but all 4 directions actually mater

*/



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 2e3 + 3;
const ll MOD = 1e9 + 7;

char board[MAXN][MAXN];
int n, m;

short dp[MAXN][MAXN][26];

int rightdown(int i, int j, char let) {    
    if (i <= 0 || i >= n+1 || j <= 0 || j >= m+1) {
        return 0;
    } 
    if (board[i][j] != let) return 0;

    if (dp[i][j][let-'a'] != -1) return dp[i][j][let-'a'];

    int right = rightdown(i, j+1, let);
    int down = rightdown(i+1, j, let);

    int minBoi = min(down, right);
    
    return dp[i][j][let-'a'] = minBoi + 1;
}

int leftup(int i, int j, char let) {
    if (i <= 0 || i >= n+1 || j <= 0 || j >= m+1) {
        return 0;
    } 

    if (board[i][j] != let) return 0;

    if (dp[i][j][let-'a'] != -1) return dp[i][j][let-'a'];


    int up = leftup(i-1, j, let);
    int left = leftup(i, j-1, let);

    int minBoi = min(up, left);

    return dp[i][j][let-'a'] = minBoi + 1;
}

int rightup(int i, int j, char let) {
    if (i <= 0 || i >= n+1 || j <= 0 || j >= m+1) {
        return 0;
    } 

    if (board[i][j] != let) return 0;

    if (dp[i][j][let-'a'] != -1) return dp[i][j][let-'a'];


    int up = rightup(i-1, j, let);
    int right = rightup(i, j+1, let);

    int minBoi = min(up, right);

    return dp[i][j][let-'a'] = minBoi + 1;
}

int leftdown(int i, int j, char let) {
    if (i <= 0 || i >= n+1 || j <= 0 || j >= m+1) {
        return 0;
    } 

    if (board[i][j] != let) return 0;

    if (dp[i][j][let-'a'] != -1) return dp[i][j][let-'a'];


    int down = leftdown(i+1, j, let);
    int left = leftdown(i, j-1, let);

    int minBoi = min(down, left);

    return dp[i][j][let-'a'] = minBoi + 1;
}


short rd[MAXN][MAXN];
short lu[MAXN][MAXN];
short ru[MAXN][MAXN];
short ld[MAXN][MAXN];

void solve() {
    cin>>n>>m;

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>board[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    ll ans = 0;

    for (int i=1;i<=n;i++) 
        for (int j=1;j<=m;j++) 
            ru[i][j] = rightup(i, j, board[i][j]);
    
    memset(dp, -1, sizeof(dp));

    for (int i=1;i<=n;i++) 
        for (int j=1;j<=m;j++) 
            rd[i][j] = rightdown(i, j, board[i][j]);    

    memset(dp, -1, sizeof(dp));

    for (int i=1;i<=n;i++) 
        for (int j=1;j<=m;j++) 
            ld[i][j] = leftdown(i, j, board[i][j]);    
    
    memset(dp, -1, sizeof(dp));

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            lu[i][j] = leftup(i, j, board[i][j]);    
            ll cnt = min({lu[i][j], ru[i][j], rd[i][j], ld[i][j]});
            ans += cnt;
        }

    }

    cout<<ans<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}