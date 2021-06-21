/*
~~~ CCC'07-S5 Bowling for Numbers ~~~

Key Concepts: Dynamic Programming

pins[i] = the score you would get if you hit pin i


*/

#include <bits/stdc++.h>

using namespace std;

int TC, n, k, w, pins[30005];

int memo[505][30005];
int score(int b, int p) {
    if (b==0) return 0;
    if (p>=n) return 0;

    if (memo[b][p]!=-1) return memo[b][p];

    int hit = pins[p] + score(b-1, p+w);
    int notHit = score(b, p+1);

    return memo[b][p] = max(hit, notHit);
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin>>TC;

    while (TC--) {
        cin>>n>>k>>w;
        memset(pins, 0, sizeof(pins));
        memset(memo, -1, sizeof(memo));
        int ps;
        for (int i=0;i<n;i++) {
            cin>>ps;
            pins[i] += ps;
            // cout<<"pin "<<ps<<endl;
            for (int j=1;j<w;j++) {
                if (i-j>=0) pins[i-j] += ps;
            }
        }

        // for (int i=0;i<n;i++) cout<<pins[i]<<" ";
        // cout<<endl;

        cout<<score(k, 0)<<"\n";
    }
}