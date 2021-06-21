/*
~~~ 1392C - Omkar and Waterslide ~~~

Key Concepts: Difference Array, Greedy

Very elegant solution, but difficult to come up with imo

The main idea is to look at the differences between elements instead of the actual values

    Let D[i] = A[i+1] - A[i] => difference array

Our goal is thus reassigned to be to make all elements in D[i] >= 0

Lets look at what an operation does to the difference array

    -> Note we can only perform an operation on [i, j]

        iff all elements D[i] -> D[j] are all positive

    When we perform an operation on [i, j]

        D[i-1] += 1
        D[j] -= 1

Lets say our difference array looks like:

    -2 0 0 0 -1 5 8 0 -4 0 0

    and we want to make all the negative numbers even

    We can do this optimally by going from right to left...

        for every negative number at index i

            we perform an operation in the range [i+1, n]

        In this way we will never do the D[j] -= 1 operation
            
            since j in outside of the array

*/



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

ll arr[MAXN];

void solve() {
    int n;
    cin>>n;

    for (int i=1;i<=n;i++) cin>>arr[i];

    int last = 0;
    ll ans = 0;

    for (int i=1;i<=n;i++) {
        int dif = arr[i] - last;
        last = arr[i];
        if (dif < 0) ans += abs(dif);
    }

    cout<<ans<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        solve();
    }
}