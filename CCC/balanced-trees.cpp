#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll numBalanced(int k) {
    if (k==1) return 1;
    ll sum = 0;
    for (int i=2;i<=k;i++)
        sum += numBalanced(k/i);
    return sum;
}


void solve() {
    int n;
    cin>>n;

    ll ans = numBalanced(n);
    cout<<ans<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}