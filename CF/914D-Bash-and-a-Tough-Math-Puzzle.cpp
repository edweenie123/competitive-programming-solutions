/*
~~~ 914D - Bash and a Tough Math Puzzle ~~~

Key Concepts: GCD Segtree, Number Theory

Insight 1:
Let k be the # of elements in [l..r] that are not divisible by x

If k <= 1:
    The guess is almost correct => output "YES"
Else:
    The guess is not almost correct => output "NO"

The problem thus reduces to finding the # of elements in the query range that are not divsible by x

Insight 2:
This can be done using a GCD segtree!

Key idea...

If (seg[i] % x == 0):
    This means that all elements in the range of node i are divisble by x
        => so there we don't recurse don't this child
Else:
    There is at least one element that is not divisble by x in the range of node i
        => recurse down child to count how many

This will take nlog n time at worst

We can add an extra speed up!
    If both children are not divisible by x:
        This means that k >= 2:
            therefore it is guarantted that it is impossible
            so theres is no point is recursing again -> break

    So at most we recurse down one child -> log n time

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int n, q;
int arr[MAXN];
int seg[MAXN*4];

void update(int node, int l, int r, int idx, int val) {
    if (l==r) {
        seg[node] = val;
    } else {

        int mid = (l + r) / 2;

        if (l<=idx && idx <= mid) update(node*2, l, mid, idx, val);
        else update(node*2+1, mid+1, r, idx, val);

        int c1 = seg[node*2];
        int c2 = seg[node*2+1];

        seg[node] = __gcd(c1, c2);
    }
}

int notDiv = 0;

void query(int node, int l, int r, int ql, int qr, int x) {
    if (qr < l || ql > r) return;
    if (notDiv > 1) return; // no point in recursing

    // partially in range
    if (seg[node] % x == 0) // if all elements in range are div by x then stop recursing
        return;

    if (l==r) { // reached a leaf in the query range that is not divisible by x
        notDiv++;
        return;
    }

    int mid = (l + r) / 2;
    query(node*2, l, mid, ql, qr, x);
    query(node*2+1, mid+1, r, ql, qr, x);
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    int val;
    for (int i=1;i<=n;i++) {
        cin>>val;
        update(1, 1, n, i, val);
    }

    cin>>q;
    int t, l, r, x, i, y;
    while (q--) {
        cin>>t;

        if (t == 1) {
            cin>>l>>r>>x;
            notDiv = 0;
            query(1, 1, n, l, r, x);
            cout<<(notDiv<=1?"YES":"NO")<<"\n";
        } else {
            cin>>i>>y;
            update(1, 1, n, i ,y);
        }
    }
}