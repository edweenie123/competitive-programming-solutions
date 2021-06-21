/*
~~~ DMOPC '13 Contest 3 P5 - A Romantic Dinner ~~~

Key Concepts: Dynamic Programming (0-1 Knapsack)

Overvalued problem; very simple problem same thing as 0-1 knapsack basically
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXR = 151;
const int MAXU = 101;
const int MAXM = 301;

int M, U, R; // maxTime, food capacity, # restaurants 
int V[MAXR], T[MAXR], F[MAXR]; // impression val, time, food amount
int dp[MAXR][MAXU][MAXM];

int opt(int r, int u, int m) {
    if (dp[r][u][m]!=-1) return dp[r][u][m];

    if (r==R) return 0; 
    int res = opt(r+1, u, m); // skip restaurant
    
    if (F[r]<=u&&T[r]<=m) { // enough time and enough food capacity
        res = max(res, V[r] + opt(r+1, u-F[r], m-T[r])); // go to restaurant
    }

    return dp[r][u][m] = res;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>M>>U>>R;

    for (int i=0;i<R;i++) {
        cin>>V[i]>>T[i]>>F[i];
    }

    memset(dp, -1, sizeof(dp));
    cout<<opt(0, U, M);
}