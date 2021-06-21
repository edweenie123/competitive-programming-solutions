/*
~~~ K - Stones ~~~

Key Concepts: Dynamic Programming (obv)

Use Decision Tree to solve

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 101;
const int MAXK = 1e5+1;
int N, K, A[MAXN];
int dp[MAXK];

int canWin(int s) {
    // printf("s : %d\n", s);
    if (~dp[s]) return dp[s];

    for (int i=0;i<N;i++)  // try all possible moves
        if (s>=A[i]&&!canWin(s-A[i])) 
            return dp[s] = true;
    
    return dp[s] = false;
}

int main() {
    cin>>N>>K;
    for (int i=0;i<N;i++) cin>>A[i];
    memset(dp, -1, sizeof(dp));

    cout<<(canWin(K)? "First\n" : "Second\n");

}