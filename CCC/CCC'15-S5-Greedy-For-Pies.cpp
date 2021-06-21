/*
~~~ CCC '15 S5 - Greedy For Pies ~~~

Key Concepts: Dynamic Programming

Make the oberservation that the M pies from the 2nd group don't have to be inserted at the beginning:
    They can be inserted at any point while going through the N pies from the first group (just like carrying a bag of pies)

Bag Pies serve 2 purposes:
    Separators: used to separate two pies from the original group (so that you can take both)
    Inserters: insert the pies into the line so that you can take it

If you sort the bag pies in increasing order:
    Separator pies should always be taken from the beginning of the list (to avoid wasting suger)
    Inserter pies should always be taken from the end of the list (to maximize suger)

With this, analyze the possible choices we can make when processing the list:
    1. Skip the current pie
    2. Take the current pie (only if you can)
    3. Insert a separator pie and take the current pie 
    4. Instert a inserter pie into the list and take it

The solution is to simply make a recurive function that tries all possible choices and the memoimize the results

Time Complexity: O(N x M^2)

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3005;
const int MAXM = 105;

int n, m, line[MAXN], bag[MAXM];

int dp[MAXN][2][MAXM][MAXM];

int opt(int ind, int tl, int l, int r) {
    if (dp[ind][tl][l][r]!=-1) return dp[ind][tl][l][r];

    int skip, sep, take, insert = 0;
    if (ind<=n) {
        skip = opt(ind+1, 0, l, r); // skip current pie

        if (tl) {
            sep = 0;
            if (l<=r) sep = line[ind] + opt(ind+1, 1, l+1, r); // insert a separator pie from bag
            return dp[ind][tl][l][r] =  max(sep, skip);
        } 

        // last pie was taken
        take = line[ind] + opt(ind+1, 1, l, r); // take pie from line
        if (l<=r) 
            insert = bag[r] + opt(ind, 1, l, r-1); // insert pie from bag
        return dp[ind][tl][l][r] =  max(max(take, insert), skip); 
    }

    // no pies left in line 
    if (l<=r) {
        if (tl) 
            return dp[ind][tl][l][r] = opt(ind, 0, l+1, r); // add separator pie from bag
        else 
            return dp[ind][tl][l][r] = bag[r] + opt(ind, 1, l, r-1); // insert pie from bag
    }

    return dp[ind][tl][l][r] = 0;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>line[i];
    cin>>m;
    for (int i=1;i<=m;i++) cin>>bag[i];
    sort(bag+1, bag+m+1);

    memset(dp, -1, sizeof(dp));
                
    cout<<opt(1, 0, 1, m)<<"\n";
}