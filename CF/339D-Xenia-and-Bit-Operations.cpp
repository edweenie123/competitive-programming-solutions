/*
~~~ 339D - Xenia and Bit Operations ~~~

Key Concepts: Segment tree

The operations can be modeled in the same way as a segment tree

    So you can perform updates the segment tree way in log n

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = (1<<17)+5;

// int arr[MAXN];
int seg[4*MAXN];

void update(int node, int l, int r, int idx, int val, bool isOR) {

    if (l==r) { // reach idx
        // arr[idx] = val;
        seg[node] = val;
    } else {
        int mid = (l+r)/2;

        if (idx>=l&&idx<=mid) update(node*2, l, mid, idx, val, !isOR);
        else update(node*2+1, mid+1, r, idx, val, !isOR);

        int c1 = seg[node*2], c2 = seg[node*2+1];

        if (isOR) seg[node] = c1 | c2;
        else seg[node] = c1 ^ c2;
    }
}

int n, m;

int main() {
    cin>>n>>m;

    int val;
    bool lastOp = n % 2 != 0;

    for (int i=1;i<=(1<<n);i++) {
        cin>>val;
        update(1, 1, (1<<n), i, val, lastOp);
    }

    int idx;
    while (m--) {
        cin>>idx>>val;
        update(1, 1, (1<<n), idx, val, lastOp);
        cout<<seg[1]<<"\n";
    }
}