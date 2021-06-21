/*
~~~ Joey and Biology ~~~

Key Concepts: DP

Kinda simple but the recurrence isn't that intuitive


*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int INF = 1e9;

int n, m;
int dp[MAXN][MAXN];
string s1, s2;

int minEdit(int idx1, int idx2) { // returns the minimum edits for s1[..idx1] and s2[..idx2]
    if (idx1 < 0 || idx2 < 0) return INF; // invalid
    if (idx1==0 && idx2==0) return 0; // compare two empty strings
    if (s1[idx1-1] == s2[idx2-1]) return minEdit(idx1-1, idx2-1); // no edits need to be made

    if (dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    int ans = INF;

    ans = min(ans, minEdit(idx1-1, idx2-1) + 1); // change a char at the end

    for (int i=1;i<=3;i++) {
        ans = min(ans, minEdit(idx1-i, idx2) + 1); // insert i char at the end of s1
        ans = min(ans, minEdit(idx1, idx2-i) + 1); // insert i char at the end of s2
    }

    return dp[idx1][idx2] = ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>s1>>s2;

    memset(dp, -1, sizeof(dp));

    int ans = minEdit(n, m);
    cout<<ans<<"\n";
}