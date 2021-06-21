/*
~~~ 1061C - Multiplicity ~~~

Key Concepts: DP (ordered)

Similar to lazy fox again (ordered dp)

Insight 1:
Let dp[l] be the # of valid subsequences of length l

For every index in the array:
    we find the all the factors of a[i] in O(sqrt(1e6))

    If a[i] is divisible by k:
        The # of valid subsequences of length k ending at a[i] is
            = # of valid subsequences of length k-1 that ends before a[i]

If we iterate through the array, it will guarantee that the order is correct

Note: we have to becareful when updating, because we might overcount as we're updating
    -> therefore we always update the highest divisors first (think about it and it will make sense)


*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

int n;
int arr[MAXN];

ll valid[MAXN]; // valid[i] = # of subsequences of length i

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    valid[0] = 1;

    for (int i=1;i<=n;i++) {

        vector<int> divs;

        for (int k=1;k*k<=arr[i];k++) {
            if (arr[i] % k != 0) continue;
            if (k>i) break;

            divs.push_back(k);
            if (arr[i]/k != k && arr[i]/k<=i) divs.push_back(arr[i]/k);
        }

        sort(divs.begin(), divs.end(), greater<int>());

        for (auto d : divs) {
            valid[d] = (valid[d] + valid[d-1]) % MOD;
        }
    }

    ll ans = 0;

    for (int i=1;i<=n;i++) {
        ans = (ans + valid[i]) % MOD;
    }

    cout<<ans<<"\n";
}