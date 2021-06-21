// Key Concepts: Implementation, DP (sorta)

#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int arr[100001];
int sums[100001];

void precompute() {
    memset(arr, 0, sizeof(arr));
    for (int i=0;i<n-1;i++) {
        if (s[i]==s[i+1]) arr[i]=1;
    }
    memset(sums, 0, sizeof(sums));
    sums[0] = arr[0];
    for (int i=1;i<n;i++) {
        sums[i] = sums[i-1]+arr[i];
    }
}
int query(int l, int h) {
    int cnt=sums[h-1]-sums[l-1];
    return cnt;
}

int main() {
    int m, l, r;
    cin>>s;
    n = s.length();

    precompute();
    cin>>m;
    for (int i=0;i<m;i++) {
        cin>>l>>r;
        cout<<query(l-1, r-1)<<endl;
    }
}