/*
~~~ Binary Indexed (Fenwick) Tree Data Structure ~~~

Point Update - O(log n)
Range Query - O(log n)
*/

#include<bits/stdc++.h>
using namespace std;

int n, q, arr[100005], bit[100005];

void update(int k, int val) {
    while(k<=n) {
        bit[k] += val;
        k += k & -k;
    }
}

void build() {
    for (int i=1;i<=n;i++)
        update(i, arr[i]);
}

int query(int k) {
    int total = 0;
    while(k>0) {
        total += bit[k];
        k -= k & -k;
    }

    return total;
}

int queryRange(int l, int r) {
    return query(r) - query(l-1);
}

int main() {
    cin>>n>>q;

    for (int i=1;i<=n;i++) cin>>arr[i];
    build();
    
    char type;
    int a, b;

    while (q--) {
        cin>>type>>a>>b;
        if (type=='C') {
            update(a, b);
        } else {
            cout<<queryRange(a, b)<<endl;
        }
    }
}