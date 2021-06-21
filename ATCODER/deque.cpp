/*
~~~ L - Deque ~~~

Key Concepts: Dynamic Programming

Slightly more complicated decision tree 

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 3001;

int N, A[MAXN];
ll dp[MAXN][MAXN][2];

ll opt(int l, int r, int p) { // returns x-y with range(l, r)
    // printf("looking at %d-%d for player %d\n", l, r, p);
    if (~dp[l][r][p]) return (dp[l][r][p]);

    if (l==r) {
        if (p==0) return A[l];
        else return -A[l];
    }
    if (p==0) {
        ll back = opt(l+1, r, 1) + A[l];
        ll front = opt(l, r-1, 1) + A[r];
        return dp[l][r][p] = max(back, front);       
    } else {
        ll back = opt(l+1, r, 0) - A[l];
        ll front = opt(l, r-1, 0) - A[r];
        return dp[l][r][p] = min(back, front);
    }
}

int main() {
    cin>>N;
    for (int i=0;i<N;i++) cin>>A[i];
    memset(dp, -1, sizeof(dp));
    cout<<opt(0, N-1, 0)<<"\n";
}