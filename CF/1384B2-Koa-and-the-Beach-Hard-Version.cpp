/*
~~~ 1384B2 - Koa and the Beach (Hard Version) ~~~

Key Concepts: constuctive algs, implementation 

It actually not that hard if you think about it in a certain way

Insight 1:
Notice that pos x is valid (has a depth less than l)
    when t in the interval +-(l-d) where d is the original depth

    think about it if it doesn't make sense

From this insight, we realize that every position has an interval for which it has a depth of less than l
    -> we can use propagate the intervals forward
        and then check if the interval is value at the end
            to know if it is possible

    Note: if you reach a position where you can stay forever
        -> the interval resets to (-k, k)

*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define first f
#define second s

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

int d[MAXN];
int range[MAXN];

void solve() {
    int n, k, l;
    cin>>n>>k>>l;

    for (int i=1;i<=n;i++) cin>>d[i];

    for (int i=1;i<=n;i++) {
        if (d[i] > l) { // not possible
            cout<<"No\n"; return;
        }
        
        range[i] = min(l - d[i], k);
    }

    // possible ranges
    int lef = -range[1];
    int rig = range[1];

    for (int i=2;i<=n;i++) {
        int nL = -range[i], nR = range[i];

        if (nR == k) { // can stay here forever
            lef = -k;
            rig = k;
        } else { // range gets smaller
            lef = max(lef+1, nL);
            rig = min(rig+1, nR);
        }

        if (lef > rig) { // no range is possible
            cout<<"No\n"; return;
        }
    }

    cout<<"Yes\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        solve();
    }
}