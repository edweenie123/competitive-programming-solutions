/*
~~~ IOI '01 P1 - Mobile Phones ~~~

Key Concepts: 2D Fenwick Tree

Trivial 2D Fenwick Tree Implementation
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXS = 1025;
int s, bit[MAXS][MAXS];

int LSB(int k) {return k&(-k);}

void update(int x, int y, int a) {
    for (int i=x;i<=s;i+=LSB(i)) {
        for (int j=y;j<=s;j+=LSB(j)) {
            bit[i][j] += a;
        }
    }
}

int query(int x, int y) {
    int cnt = 0;
    for (int i=x;i>0;i-=LSB(i)) {
        for (int j=y;j>0;j-=LSB(j)) {
            cnt += bit[i][j];
        }
    }
    return cnt;
}

int queryRange(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int t, x1, y1, x2, y2, a;
    while (1) {
        cin>>t;
        if (t==0) cin>>s;
        else if (t==1) {
            cin>>x1>>y1>>a;
            update(x1+1, y1+1, a);
        } else if (t==2) {
            cin>>x1>>y1>>x2>>y2;
            cout<<queryRange(x1+1, y1+1, x2+1, y2+1)<<"\n";
        } else if (t==3) break;
    }

}