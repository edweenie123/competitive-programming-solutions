#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

ii st[1000000];
int n, q, arr[100001];

void build(int node, int start, int end) {
    if (start==end) {
        st[node] = ii(1, arr[start]);
    } else {
        int mid = (start + end) / 2;
        build(node*2, start, mid);
        build(node*2+1, mid+1, end);

        ii c1 = st[node*2], c2 = st[node*2+1];
        if (c1.second==c2.second) {
            st[node] = ii(c1.first+c2.first, c1.second);
        } else {
            st[node] = max(c1, c2);
        }
    }
    printf("range %d-%d is %d\n", start, end, st[node]);
}

ii query(int node, int start, int end, int l, int r) {
    if (end<l || start>r)
        return ii(0, -123);
    if (start>=l && end<=r)
        return st[node];

    int mid = (start + end) / 2;
    ii c1 = query(node*2, start, mid, l, r);
    ii c2 = query(node*2, mid+1, end, l, r);

    if (c1.second==c2.second)
        return ii(c1.first+c2.first, c1.second);
    else 
        return max(c1, c2);
}

int main() {
    freopen("input.txt", "r", stdin);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>arr[i];
    build(1, 1, n);
    printf("all max: %d\n", st[1]);

    int l, r;
    for (int i=0;i<q;i++) {
        cin>>l>>r;
        cout<<query(1, 1, n, l, r).first<<endl;
    }
}