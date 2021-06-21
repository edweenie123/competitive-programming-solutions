/*
~~~ CCC '14 S4 - Tinted Glass Window ~~~

Key Concepts: Difference Array, Coordinate Compression

In order to not exceed on memory, we have to perform coodinate compression on the glass windows


*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;
typedef unsigned long long ull;
int n, t;

ull d[MAXN][MAXN];

struct rect {
    int c1, r1, c2, r2, tint;
};

set<int> rows, cols;
vector<rect> rects;

ull itor[MAXN], itoc[MAXN];
unordered_map<ull, int> rtoi, ctoi;

int main() {
    cin.sync_with_stdio(0);
    cin>>n>>t;

    int c1, r1, c2, r2, b;
    for (int i=0;i<n;i++) {
        cin>>c1>>r1>>c2>>r2>>b;
        rects.push_back(rect{c1, r1, c2, r2, b});
        rows.insert(r1); rows.insert(r2);
        cols.insert(c1); cols.insert(c2);
    }

    int idx = 0;
    for (auto r : rows) {
        // printf("row of %d\n", r);
        itor[idx] = r;
        rtoi[r] = idx;
        idx++;
    }

    idx = 0;
    for (auto c : cols) {
        // printf("col of %d\n", c);

        itoc[idx] = c;
        ctoi[c] = idx;
        idx++;
    }
    
    int startI, endI, tint, startJ, endJ;
    for (auto rec : rects) {
        // printf("considering (%d, %d) - (%d, %d)\n", rec.r1, rec.c1, rec.r2, rec.c2);
        startI = rtoi[rec.r1];
        endI = rtoi[rec.r2] - 1;
        // printf("    startI: %d, endI: %d\n", startI, endI);
        tint = rec.tint;

        startJ = ctoi[rec.c1];
        endJ = ctoi[rec.c2] - 1;

        // printf("    startJ: %d, endJ: %d\n", startJ, endJ);

        for (int i=startI;i<=endI;i++) {
            d[i][startJ] += tint;
            d[i][endJ+1] -= tint;
        }
    }

    ull totArea = 0;
    ull deltaRow, deltaCol;

    ull lastTint;
    ull curTint;
    for (int i=0;i<n*2;i++) {
        for (int j=0;j<n*2;j++) {
            if (j==0) {
                curTint = d[i][j]; 
                // arr[i][j] = d[i][j];
            } else {
                lastTint = curTint;
                curTint = lastTint + d[i][j];
            }
            // cout<<arr[i][j]<<" ";

            if (curTint >= t) {
                // printf("(%d, %d) is greater than t!\n", i, j);
                deltaRow = itor[i+1] - itor[i];
                deltaCol = itoc[j+1] - itoc[j];

                totArea += deltaCol * deltaRow;
                // printf("add area: %d\n", deltaCol * deltaRow);
            } 
        } //cout<<endl;
    }

    cout<<totArea<<"\n";

}