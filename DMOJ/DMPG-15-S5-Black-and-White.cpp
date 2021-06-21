/*
~~~ DMPG '15 S5 - Black and White ~~~

Key Concepts: 2D Difference Array

Pretty straight implementation of 2D difference array

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
int n, m;
unsigned char a[MAXN][MAXN], d[MAXN][MAXN];

// d[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1]

void update(int r1, int c1, int r2, int c2, int amt) {
    d[r1][c1] += amt;
    d[r1][c2+1] -= amt;
    d[r2+1][c1] -= amt;
    d[r2+1][c2+1] += amt;
}

void rebuild() {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            a[i][j] = d[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    int r, c, w, h;
    while (m--) {
        cin>>r>>c>>w>>h;

        r++;
        c++;

        update(r, c, r+w-1, c+h-1, 1);
    }

    rebuild();

    int cnt = 0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j] % 2 == 1) {
                cnt++;
            }
            //cout<<a[i][j]<<" ";
        }//cout<<endl;
    }

    cout<<cnt<<"\n";
}