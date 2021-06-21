/*
~~~ 1371D - Grid-00100 ~~~

Key Concepts: yucky latin square

Through the problem statement,
it should be pretty clear that you want the # of 1s in each column and row to be as close as possible

The main insight is the build the grid the same way you would create a latin square


*/



#include<bits/stdc++.h>
using namespace std;

#define print(x) cout<<(#x)<<" = "<<x<<"\n";
typedef long long ll;
typedef pair<int, int> ii;

int grid[305][305];
int n, k;

set<ii> cols;
set<ii> rows;

int solve() {
    cin>>n>>k;

    for (int i=1;i<=n;i++) 
        for (int j=1;j<=n;j++) 
            grid[i][j] = 0;
        
    

    int row1Idx = 1;

    int row = 1;
    int col = 1;

    for (int i=0;i<k;i++) {
        if (row==1) {
            col = row1Idx;
            row1Idx++;
        }

        grid[row][col] = 1;

        col++;
        row++;

        if (col>n) col = 1;
        if (row>n) row = 1;
    }

    if (k%n==0) cout<<"0\n";
    else cout<<"2\n";

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
}

int main() {
    int TC; cin>>TC;

    while (TC--) {
        solve();
        // cout<<ans<<"\n";
    }
}