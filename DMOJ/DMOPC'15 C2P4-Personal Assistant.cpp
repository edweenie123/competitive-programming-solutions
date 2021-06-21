/*
~~~ DMOPC '15 Contest 2 P4 - Personal Assistant ~~~
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 1e5 + 1;

int n;
ll R[MAXN], L[MAXN], H[MAXN], memo[MAXN];

ll maxH(int idx) {
    if (idx>=n) return 0;

    if (memo[idx]!=-1) return memo[idx];

    int nextTime = lower_bound(R, R+n, R[idx] + L[idx]) - R;
    ll watch = H[idx] + maxH(nextTime);
    ll notWatch = maxH(idx+1);

    return memo[idx] = max(watch, notWatch);
}

int main() {
    cin>>n;
    // ll r, l, h;

    for (int i=0;i<n;i++) {
        cin>>R[i]>>L[i]>>H[i];
    }

    fill(memo, memo+MAXN, -1);

    cout<<maxH(0)<<"\n";
}