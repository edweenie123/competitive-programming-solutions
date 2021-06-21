/*
~~~ 0-1 Knapsack ~~~

Given n items, each with its own value V_i and weight W_i and a maximum knapsack size S, compute the maximum value of the items we can carry. 
 
We create val(id,remW)
    - returns the maximum value with items id-end with remW remaining weight left in the knapsack. 
    
We can define val(id,remW) recusively, and use a memoization table to store the intermediate results


Time Complexity: O(NS) N = # items, S = Knapsack Capacity
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100+5;
const int MAX_S = 1e5 + 5;

int n, s;

int V[MAX_N], W[MAX_N], memo[MAX_N][MAX_S];

int val(int id, int remW) {
    if (id==n||remW==0) return 0; // base case 

    if (memo[id][remW]!=-1) return memo[id][remW];

    if (W[id]>remW) // we have no choice but to ignore this item
        return memo[id][remW] = val(id+1, remW);
    
    if (W[id]<=remW) { // we can either take or ignore this item; choice the option which maximizes value
        int take = V[id] + val(id+1, remW-W[id]);
        int notTake = val(id+1, remW);
        return memo[id][remW] = max(take, notTake);
    }
}

void getInput() {
    cin>>n>>s;

    int v, w;
    for (int i=0;i<n;i++) {
        cin>>w>>v;
        V[i] = v;
        W[i] = w;
    }
}

int main() {
    getInput();
    memset(memo, -1, sizeof(memo));
    cout<<val(0, s)<<endl;
}