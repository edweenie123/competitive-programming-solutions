#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int seg1[MAXN*4], seg2[MAXN*4];
int arr[MAXN];

unordered_map<int, vector<int>> idx;
unordered_map<int, bool> sorted;

void build(int id, int l, int r, int* seg, string type) {
    if (l==r) {
        seg[id] = arr[l];
    } else {
        int mid = (l + r) / 2;
        build(id*2, l, mid, seg, type);
        build (id*2+1, mid+1, r, seg, type);

        int c1 = seg[id*2], c2 = seg[id*2+1];

        if (type=="min") seg[id] = min(c1, c2);
        else seg[id] = __gcd(c1, c2);
    }
}

void update(int id, int l, int r, int val, int idx, int* seg, string type) {

    if (l==r) {
        arr[idx] = val;
        seg[id] = val;
    } else {

        int mid = (l + r) / 2;

        if (l<=idx&&idx<=mid) 
            update(id*2, l, mid, val, idx, seg, type);
        else
            update(id*2+1, mid+1, r, val, idx, seg, type);
        
        if (type=="min") seg[id] = min(seg[id*2], seg[id*2+1]);
        else seg[id] = __gcd(seg[id*2], seg[id*2+1]);

    }

}

int query(int id, int l, int r, int ql, int qr, int*seg, string type) {
    
    if (qr < l || ql > r) {
        if (type=="min") return 1e9;
        return 0;
    } 

    if (ql <= l && qr >= r)
        return seg[id];

    int mid = (l + r) / 2;

    int c1 = query(id*2, l, mid, ql, qr, seg, type);
    int c2 = query(id*2+1, mid+1, r, ql, qr, seg, type);

    if (type=="min") return min(c1, c2);
    else return __gcd(c1, c2);

}

int findFreq(int l, int r, int val) {
    if (!sorted[val]) {
        sort(idx[val].begin(), idx[val].end());
        sorted[val] = true;
    }

    int left = lower_bound(idx[val].begin(), idx[val].end(), l) - idx[val].begin();
    int right = upper_bound(idx[val].begin(), idx[val].end(), r) - idx[val].begin();

    // cout<<left<<" "<<right<<"\n";
    return right - left;
}


int main() {
    int n, m;
    cin>>n>>m;

    for (int i=1;i<=n;i++) cin>>arr[i];
    build(1, 1, n, seg1, "min");
    build(1, 1, n, seg2, "gcd");

    for (int i=1;i<=n;i++) {
        idx[arr[i]].push_back(i);
    }

    char t; int l, r;

    while (m--) {
        cin>>t>>l>>r;

        if (t=='C') {
            update(1, 1, n, r, l, seg1, "min");
            update(1, 1, n, r, l, seg2, "gcd");
        } else if (t=='M'){
            int ans = query(1, 1, n, l, r, seg1, "min");
            cout<<ans<<"\n";
        } else if (t=='G') {
            int ans = query(1, 1, n, l, r, seg2, "gcd");
            cout<<ans<<"\n";
        } else {
            int gcdVal = query(1, 1, n, l, r, seg2, "gcd");
            int ans = findFreq(l, r, gcdVal);
            cout<<ans<<"\n";
        }
    }
}