/*
~~~ CCC '09 S5 - Wireless ~~~

Key Concepts: Difference Array, Binary Search

Each row in d represents a 1D difference array

For each circle, we start at the top and find the right-most point that the range can reach using BS
    - We then update the difference array using this point

After we do this for every circle, we reconstruct each row of the difference array
    - Find the max value of each element in the array and the frequency of it to get the answer

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXM = 3e4 + 5;
const int MAXN = 1e3 + 5;

int m, n, k;

int d[MAXM][MAXN];
int a[MAXM][MAXN];

void update(int l, int r, int row, int amt) {
    if (row<=0||row>m) return;

    // ensure that the range stays within bounds
    l = max(1, l);      
    r = min(n, r);         

    d[row][l] += amt;
    d[row][r+1] -= amt;
}

double distSquared(double r1, double c1, double r2, double c2) {
    return pow(r1-r2, 2) + pow(c1-c2, 2);
}

int bs(int row, int centCol, int centRow, double range) {
    int low, high, mid, best;
    double rangeSquared = range * range;
    low = 0;
    high = min(1001, (int)range);
    best = 0;

    while (low<=high) {
        mid = (low + high) / 2;
        if (distSquared(centRow, centCol, row, centCol + mid) <= rangeSquared) {
            low = mid+1;
            best = mid;
        } else {
            high = mid-1;
        }
    }
    return best;
}

void reconstruct() { // reconstructs the difference array
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (j==1) a[i][1] = d[i][1];
            else {
                a[i][j] = a[i][j-1] + d[i][j];
            }
        } 
    }   
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>m>>n>>k;

    int col, row, r, b;

    int highest, lowest, out;
    for (int i=0;i<k;i++) {
        cin>>col>>row>>r>>b;

        highest = min(r, m-row);
        lowest = max(-r, 1-row);

        for (int up=highest;up>=lowest;up--) {
            out = bs(row+up, col, row, r);
            update(col-out, col+out, row+up, b);
        }
    }

    reconstruct();
    
    int maxBitRate = -1, freq = 0;

    // get the largest bit rate the frequency of it
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j] > maxBitRate) {
                freq = 1;
                maxBitRate = a[i][j];
            } else if (a[i][j] == maxBitRate) {
                freq++;
            }
        } 
    }

    cout<<maxBitRate<<"\n"<<freq<<"\n";
}