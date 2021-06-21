#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int MAXN = 1e5 + 50;
int n, m, arr[MAXN];

ull bit1[MAXN], bit2[MAXN];

void update1(int k, int val) {
    val = (long long) val;
    while (k<=n) {
        bit1[k] += val;
        k += k & -k;
    }
}

void update2(int k, int val) {
    val = (long long) val;
    while (k<=MAXN) {
        bit2[k] += val;
        k += k & -k;
    }
}

void build() {
    for (int i=1;i<=n;i++) {
        update1(i, arr[i]);
        update2(arr[i], 1);
    }
}

ull querySum(int k) {
    ull total = 0;

    while (k>0) {
        total += bit1[k];
        // printf("total: %d\n", total);
        k -= k & -k;
    }

    return total;
}

ull queryCnt(int k) {
    ull total = 0;

    while (k>0) {
        total += bit2[k];
        k -= k & -k;
    }

    return total;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin>>n>>m;

    for (int i=1;i<=n;i++) cin>>arr[i];
    build();

    char q;

    while (m--) {
        cin>>q;
        if (q=='C') {
            int ind, val; cin>>ind>>val;
            update1(ind, val-arr[ind]);
            update2(arr[ind], -1);
            update2(val, 1);

            arr[ind] = val;
        } else if (q=='S') {
            int l, r; cin>>l>>r;
            cout<<querySum(r)-querySum(l-1)<<"\n";
        } else {
            int v; cin>>v;
            cout<<queryCnt(v)<<"\n";
        }
    }
}