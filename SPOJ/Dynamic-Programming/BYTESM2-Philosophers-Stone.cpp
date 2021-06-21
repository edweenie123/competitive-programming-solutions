// Use recursion to go through all possible paths
// Use memoization to store the maximum stones you can get if you start from (i,j)

#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int h,w;


vector<array<int,2>> getPositions(int r, int c) {
    array<array<int,2>, 3> pos = {{
        {r+1,c-1},
        {r+1,c},
        {r+1,c+1}
    }};
    vector<array<int,2>> possiblePos;
    for(auto p : pos) {
        if (p[1]<=w&&p[1]>=1) {
            possiblePos.push_back(p);
        }
    }
    return possiblePos;

}

map<array<int,2>,int> memo; // (i,j) --> maximum stones from (i,j)

int dp(int r, int c) {
    if (memo.count({r,c})==1) {
        return memo[{r,c}];
    } else if (r==h-1) {
        int max=0;
        for(auto p : getPositions(r,c)) {
            if (board[p[0]][p[1]]>max) max=board[p[0]][p[1]];
        }
        int result = board[r][c] + max;
        memo[{r,c}] = result;
        return result;
    } else {
        int max=0;
        for (auto p : getPositions(r,c)) {
            int temp = dp(p[0],p[1]);
            memo[{p[0],p[1]}] = temp;
            if (temp>max) {
                max = temp;
            }
        }
        int result = board[r][c] + max;
        memo[{r,c}] = result;
        return result;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>h>>w;
        memo.clear();
        for(int i=1;i<=h;i++) {
            for(int j=1;j<=w;j++) {
                cin>>board[i][j];
            }
        }
        int ans = 0;
        for (int i=1;i<=w;i++) {
            int temp = dp(1, i);
            if (temp>ans) ans = temp;
        }
        cout<<ans<<endl;
    }
}