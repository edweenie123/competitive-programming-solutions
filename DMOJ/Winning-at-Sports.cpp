/*
~~~ Winning at Sports ~~~

Key Concepts: Dynamic Programming

Fairly simple counting paths DP problem

Beware of edge case where tarY = 0
*/

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int TC, tarX, tarY;
int dp1[2001][2001], dp2[2001][2001]; // dp for stress-free, dp for stressful

int count1(int x, int y) { // for stress-free
    if (dp1[x][y]!=-1) return dp1[x][y];
    if (x==tarX&&y==tarY) return 1;

    int res = 0;

    if (x<tarX) res = ((res%MOD) + (count1(x+1, y)%MOD))%MOD; // you win
    if (x-y>=2) res = ((res%MOD) + (count1(x, y+1)%MOD))%MOD; // opp win

    return dp1[x][y] = res;
}

int count2(int x, int y) { // for stressful
    if (dp2[x][y]!=-1) return dp2[x][y];
    if (x==tarX&&y==tarY) return 1;

    int res = 0;

    if (x==y) res = ((res%MOD) + (count2(x, y+1)%MOD))%MOD; // equal score (opp must win)
    else if (y==tarY) res = 1; // no more branching (you win every point from here)
    else {
        res = ((res%MOD) + (count2(x, y+1)%MOD))%MOD;  // opp win
        if (x<y) res =  ((res%MOD) + (count2(x+1, y)%MOD))%MOD;  // you win
    }

    return dp2[x][y] = res;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>TC;
    for (int i=1;i<=TC;i++) {
        char d;
        cin>>tarX>>d>>tarY;

        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));

        if (tarY==0) {
            cout<<"Case #"<<i<<": 1 1"<<"\n";
            continue;
        }
        cout<<"Case #"<<i<<": "<<count1(0, 0)<<" "<<count2(0, 0)<<"\n";
    }
}