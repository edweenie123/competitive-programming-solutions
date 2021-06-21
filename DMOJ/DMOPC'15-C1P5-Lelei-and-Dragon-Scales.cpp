/*
~~~ DMOPC '15 Contest 1 P5 - Lelei and Dragon Scales ~~~

Key Concepts: Maximum Range Sum in 2D Matrix

*/

#include<bits/stdc++.h>
using namespace std;

int w, h, n;

int prefix[251][251];
int main() {
    // freopen("input.txt", "r", stdin);
    cin>>w>>h>>n;

    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;j++) {
            cin>>prefix[i][j];
            prefix[i][j] += prefix[i][j-1];
            prefix[i][j] += prefix[i-1][j];
            prefix[i][j] -= prefix[i-1][j-1];
        }
    }

    int ans = 0;
    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;j++) {
            for (int nw=1;nw<=w;nw++) {
                int nh = n/nw;
                int endCordW = min(w, j+nw-1), endCordH = min(h, i+nh-1);
                int rangeSum = prefix[endCordH][endCordW];
                rangeSum -= prefix[i-1][endCordW];
                rangeSum -= prefix[endCordH][j-1];
                rangeSum += prefix[i-1][j-1];
                ans = max(ans, rangeSum);
            }
        }   
    }

    cout<<ans;
}