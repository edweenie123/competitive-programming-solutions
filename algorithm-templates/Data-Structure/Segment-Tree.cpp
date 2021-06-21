/*
~~~ Segment Tree Data Structure ~~~


*/

#include <bits/stdc++.h>
using namespace std;

int n, A[100000], q;
int st[100000];

void build(int node, int start, int end) {
    if (start==end) {
        // left node will be single element
        st[node] = A[start];
    } else {
        int mid = (start + end) / 2;

        // recurse on left child
        build(node*2, start, mid);

        // recurse on right child
        build(node*2+1, mid+1, end);

        // internal node will be the sum of its children
        st[node] = st[node*2] + st[node*2+1];
    }
}

void update(int node, int start, int end, int idx, int val) {
    // increase A[idx] by val

    if (start==end) {
        // update leaf node
        A[idx] += val;
        st[node] += val;
    } else {
        int mid = (start + end) / 2;
        if (start<=idx&&idx<=mid) {
            // if idx is in the left child, recurse on the left child
            update(node*2, start, mid, idx, val);
        } else {
            // if idx is in the right child, recurse on the right child
            update(node*2+1, mid+1, end, idx, val);
        }

        // internal node will be the sum of its children
        st[node] = st[node*2] + st[node*2+1];
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start or l > end)
        // range of node is completely outside given range
        return 0;
    if (l <= start && r >= end)
        // range of node is completely inside given range
        return st[node];

    // range of node is partially inside the given range
    int mid = (start + end) / 2;
    int c1 = query(node*2, start, mid, l, r);
    int c2 = query(node*2+1, mid+1, end, l, r);

    return (c1+c2);
}

int main() {
    freopen("input.txt", "r", stdin);
    cin>>n>>q;
    for (int i=1;i<=n;i++)cin>>A[i];
    build(1, 1, n);

    char type;
    int l, r, idx, val;
    for (int i=0;i<q;i++) {
        cin>>type;
        if (type=='q') {
            cin>>l>>r;
            cout<<query(1, 1, n, l, r)<<endl;
        } else {
            cin>>idx>>val;
            update(1, 1, n, idx, val);
        }
    }
}