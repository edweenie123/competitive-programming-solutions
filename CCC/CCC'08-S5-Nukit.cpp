/*
~~~ CCC '08 S5 - Nukit ~~~

Key Concepts: Descision Tree + Dynamic Programming

Create a decision tree for each possible action a player could make 
*/

#include <bits/stdc++.h>
using namespace std;

int n, memo[31][31][31][31];
vector<vector<int>> react = {
    {2, 1, 0, 2},
    {1, 1, 1, 1},
    {0, 0, 2, 1},
    {0, 3, 0, 0},
    {1, 0, 0, 1}
};

bool win(int a, int b, int c, int d) {
    if (memo[a][b][c][d]!=-1) return memo[a][b][c][d];

    for (auto r : react) 
        if (a>=r[0]&&b>=r[1]&&c>=r[2]&&d>=r[3]) 
            if (!win(a-r[0], b-r[1], c-r[2], d-r[3])) 
                return memo[a][b][c][d] = true;
         
    return memo[a][b][c][d] = false;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin>>n;

    for (int i=0;i<31;i++)for (int j=0;j<31;j++) for (int k=0;k<31;k++) for (int l=0;l<31;l++)
        memo[i][j][k][l] = -1;
        
    int a, b, c, d;
    for (int i=0;i<n;i++) {
        cin>>a>>b>>c>>d;
        cout<<(win(a, b, c, d) ? "Patrick" : "Roland")<<endl; 
    }
}