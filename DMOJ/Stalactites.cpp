/*
~~~ Stalactites ~~~

Key Concepts: Fenwick Tree

Quite overvalued - implement a 3D BIT

Coming with the query formula is the only difficult part
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 250+1;

int n, q, length[MAXN][MAXN][MAXN]; 
ll bit[MAXN][MAXN][MAXN];

int LSB(int k) {return k&(-k);}

void update(int x, int y, int z, int l) {
    ll delta = l - length[x][y][z];
    for (int i=x;i<=n;i+=LSB(i)) 
        for (int j=y;j<=n;j+=LSB(j))
            for (int k=z;k<=n;k+=LSB(k))
                bit[i][j][k] += delta;
}

ll query(int x, int y, int z) {
    ll cnt = 0;
    for (int i=x;i>0;i-=LSB(i))
        for (int j=y;j>0;j-=LSB(j))
            for (int k=z;k>0;k-=LSB(k))
                cnt += bit[i][j][k];
    return cnt;
} 

ll querySum(int x1, int y1, int z1, int x2, int y2, int z2) {
    return query(x2,y2,z2)
            -query(x2,y1-1,z2)
            -query(x1-1,y2,z2)
            -query(x2, y2, z1-1)
            +query(x1-1,y1-1,z2)
            +query(x2,y1-1,z1-1)
            +query(x1-1,y2,z1-1)
            -query(x1-1,y1-1,z1-1);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    char t;
    int x1, x2, y1, y2, z1, z2, l;
    ll ans = 0;
    while(q--) {
        cin>>t;
        if (t=='C') {
            cin>>x1>>y1>>z1>>l;
            update(x1, y1, z1, l);
            length[x1][y1][z1] = l;
        } else {
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            ans += querySum(x1, y1, z1, x2, y2, z2);
        }
    }
    cout<<ans<<"\n";
}