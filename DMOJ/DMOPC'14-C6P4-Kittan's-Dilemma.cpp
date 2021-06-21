/*
~~~ DMOPC '14 Contest 6 P4 - Kittan's Dilemma ~~~

Key Concepts: Binary Search, PSA

Read Editorial (pretty ez if you use your brain)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 1;
int n, m;
ll bp[MAXN], gp[MAXN];
vector<ll> bad, good;

int bs(ll spaceLeft) {
    int low = 0, high = bad.size(), mid, best = 0;

    while (low<=high) {
        mid = (low+high)/2;
        if (bp[mid]<=spaceLeft) {
            best = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }

    return best;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    ll space, type;
    for (int i=0;i<n;i++) {
        cin>>space>>type;
        if (type==1) bad.push_back(space);
        else good.push_back(space);
    }
    sort(bad.begin(), bad.end());
    sort(good.begin(), good.end());

    for (int i=1;i<=bad.size();i++) bp[i] = bp[i-1] + bad[i-1];
    for (int i=1;i<=good.size();i++) gp[i] = gp[i-1] + good[i-1];
    
    ll spaceLeft; 
    int ans = 0;
    for (int i=0;i<=good.size();i++) {
        spaceLeft = m - gp[i];
        if (spaceLeft<0) break;
        int idx = bs(spaceLeft);
        // printf("%d good bois yields a pv: %d\n", i, idx+i*2);
        ans = max(ans, idx + i*2);
    }

    cout<<ans<<"\n";
}