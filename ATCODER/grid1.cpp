/*
~~~ AtCoder DP Contest Grid 1 ~~~

Fairly simple DP Problem

let ways(i, j) = # of ways to get to tile (h, w) from tile (i, j)

ways(i, j) can be defined recursively
    - ways(i, j) = ways(i+1, j) + ways(i, j+1)

Use memo table to store intermediate results to significantly improve speed 
*/

#include <bits/stdc++.h>
using namespace std;

int h,w;
char grid[1001][1001];
int memo[1001][1001];

int ways(int r, int c) {
    if (r>h||r<1||c>w||c<1||grid[r][c]!='.') return 0;
    if (r==h&&c==w) return 1;

    if (memo[r][c]!=-1) return memo[r][c];
    return memo[r][c] = (ways(r+1, c)%(1000000007) + ways(r, c+1)%(1000000007))%(1000000007);
}

int main() {
    cin>>h>>w;
    for (int i=1;i<=h;i++) for (int j=1;j<=w;j++) cin>>grid[i][j];
    for (int i=0;i<1001;i++) for (int j=0;j<1001;j++) memo[i][j] = -1;
    cout<<ways(1, 1);
}