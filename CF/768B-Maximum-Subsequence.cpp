/*
~~~ 768B - Maximum Subsequence ~~~

Key Concepts: Meet-in-the-middle, Bitmask BF

Seems like a pretty template meet in the middle problem

You find all the ss sum in the first half and do the same for the second half

Insight 1:
You can mod all the sum's by m

Then for each sum in the first half you can find the optimal value in the second half 
    using bs

Since all sums are less than m
    -> for each v1, you find the best v2 such that v1+v2 < m using bs

*/



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define all(x) begin(x), end(x)
#define first f
#define second s

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 35+5;;
const ll MOD = 1e9 + 7;

int n, m;
int arr[MAXN];

vector<ll> sum1;
vector<ll> sum2;

vector<ll> subsetSum(int l, int r) {
    vector<ll> ss;
    int len = r-l+1;

    for (int bm=0;bm<=(1<<len);bm++) {
        ll sum = 0;
        for (int i=0;i<len;i++) {
            if (bm & (1<<i)) sum += arr[l+i];
        }

        ss.push_back(sum % m);
    }

    return ss;
}

void solve() {
    cin>>n>>m;

    for (int i=1;i<=n;i++) cin>>arr[i];

    int mid = (1 + n) / 2;

    sum1 = subsetSum(1, mid);
    sum2 = subsetSum(mid+1, n);
    
    ll ans = 0;

    sort(sum2.begin(), sum2.end());

    for (auto v1 : sum1) {
        auto iter = lower_bound(all(sum2), m-v1);
        iter = prev(iter);

        ll v2 = (*iter);

        ans = max(ans, (v1 + v2) % m);
    }

    cout<<ans<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}