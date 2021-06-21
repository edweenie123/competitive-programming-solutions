/*
~~~ 1360G - A/B Matrix ~~~

Key Concepts: Constructive algorithms?

Watch algopedia's video for a better explanation

We will generate the matrix row by row

We use a vector to keep a running total of the # of bits in each column

At every step, we increase the running total of exactly A colums
    - we do this until all columns have a total of B

HOWEVER, if we pick the same columns again and again -> they might fill up too quickly!
    - this means we can no longer put bits in those column -> less than A!

Therefore, we always pick A smallest columns to increase

This makes intuitive sense, but i can't really prove it mathematically


*/


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int MAXN = 50 + 3;

int n, m, a, b;
int matrix[MAXN][MAXN];

void solve() {
    memset(matrix, 0, sizeof(matrix)); // be careful with memset!

    vector<ii> columnSum; // {val, idx}

    for (int i=0;i<m;i++) 
        columnSum.push_back({0, i});
    
    // choose A columns and add 1 (always pick the A smallest columns)
    // repeat N times (for each row)

    for (int i=0;i<n;i++) {

        sort(columnSum.begin(), columnSum.end());

        for (int j=0;j<a;j++) {
            int curSum = columnSum[j].first;
            int idx = columnSum[j].second;

            columnSum[j] = {curSum + 1, idx}; // add one to the current column sum

            matrix[i][idx] = 1;
        }
    }

    // print the matrix

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) 
            cout<<matrix[i][j];
        cout<<"\n";
    }

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int TC; cin>>TC;

    while (TC--) {
        cin>>n>>m>>a>>b;

        // n * a must equal m * b
        if (n*a != m*b) {
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
        solve();
    }
}