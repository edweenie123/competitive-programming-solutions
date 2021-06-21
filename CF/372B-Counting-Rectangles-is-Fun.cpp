/*
~~~ 372B - Counting Rectangles is Fun ~~~

Key Concepts: DP, PSA

The DP state is kinda weird so i had to ask zeyu for help...

Insight 1: 
The DP state is dp(i, j, k, l)
    which returns the number of good rectangles where the TR corner 
        has the cordinates (i, j) and the BL corner is somwhere within the rectangle
            (i, j) -> (k, l)
    
    The DP recurrence is pretty intuitive and is basically the same way you contruct a 2d psa
        -> make sure to count the cord (k, l) as a possible BL corner

Insight 2: 
With all the DP states precomputed, we can answer queries by considering
    all the possible TR corners within the query rectangle
        too sum up all the possible good rectangles in the range
    
This gives a Time Complexity of O(n^4 + n^2 * q) which TLE's barely

Insight 3:
Since we are summing up elements in a rectangular range to answer queries
    -> we can precompute all the answer to each rectangular range using a PSA
        -> we can do this in n^4 time => now we answer queries in O(1)!

    The psa is kinda weird since its upside down

Time Complexity: O(n^4 + q)

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 40 + 5;

int n, m, q;
int grid[MAXN][MAXN];

int dp[MAXN][MAXN][MAXN][MAXN];
ll psa[MAXN][MAXN][MAXN][MAXN]; // n^2 2d psas

// # of good rectangles such that the TR corner is (x1, y1)
// and the BL corner is somewhere within the rectangle (x1, y1) -> (x2, y2)
int howMany(int x1, int y1, int x2, int y2) {

    int h = y2 - y1 + 1;
    int w = x2 - x1 + 1;

    if (h==0 || w==0) return 0;
    
    if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];

    int count =  howMany(x1, y1, x2 - 1, y2) + 
                howMany(x1, y1, x2, y2-1) - 
                howMany(x1, y1, x2-1, y2-1);
    
    if (count == h*w - 1 && grid[x2][y2]==0) count++;

    return dp[x1][y1][x2][y2] = count;
}

ll rsq(int x1, int y1, int x2, int y2) {
    return psa[x2][y2][x1][y1];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>n>>m>>q;

    char val;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>val, grid[i][j] = val-'0';

    memset(dp, -1, sizeof(dp));

    // contruct n^2 weird upside down 2d psa's
    for (int i=1;i<=n;i++) 
        for (int j=1;j<=m;j++) 
            for (int k=i;k>0;k--) 
                for (int l=j;l>0;l--) 
                    psa[i][j][k][l] =   psa[i][j][k+1][l] + 
                                        psa[i][j][k][l+1] -
                                        psa[i][j][k+1][l+1] +
                                        howMany(k, l, i, j);

    int x1, y1, x2, y2;
    while (q--) {
        cin>>x1>>y1>>x2>>y2;

        ll ans = 0;
        ans = rsq(x1, y1, x2, y2);

        cout<<ans<<"\n";
    }
}