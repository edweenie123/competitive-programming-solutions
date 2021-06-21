/*
~~~ Coin Change ~~~

Classical DP problem

Given a target amount of V cents and n different denominations of coins, find the minimum number of coins needed to represent V cents

Can be easily solved using a memoization approach

We start with a complete search algorithm which look through every possible way of choosing the coins 
    - change(i) returns the # of coins needed to represent i cents (use recursive backtracking)
    - because the same change(i) needs to be computed again and again, we can store its answers in a memoization table (DP)

Time Complexity: O(nV)  
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6+5;
const int MAX_V = 1e4;

int n, V, coinValue[MAX_N], memo[MAX_V];

int change(int rem) { // returns the minimum number of coins needed to represent V
    if (rem==0) return 0;
    if (rem<0) return 1e7;
    cout<<"rem "<<rem<<endl;

    if (memo[rem]!=-1) return memo[rem];

    int numCoins = 1e7;
    for (int i=0;i<n;i++) {
        numCoins = min(numCoins, 1 + change(rem-coinValue[i]));
    }

    return memo[rem] = numCoins;
}

void getInput() {
    cin>>n>>V;

    for (int i=0;i<n;i++) cin>>coinValue[i];
}

int main() {
    getInput();

    memset(memo, -1, sizeof(memo));
    printf("You need %d coins to represent %d\n", change(V), V);
}