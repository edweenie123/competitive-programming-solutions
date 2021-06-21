/*
~~~ 1016C - Vasya and the Musrooms ~~~

Key Concepts: PSA, Precompute, implementation

A pretty messy implementation problem where you have to precompute a lot of yucky arrays
    using yucky recurrances

Insight 1:
The first insigt you make is that a valid path must always been in the following format

    Step 1: Zig zag up and down for x columns
    Step 2: Go all the way to the right (n'th column)
    Step 3: Go up or down
    Step 4: Go all the way to the left and hit your zig zags

Because there are only n possible paths (n value for x)
    -> we can brute force through all possible paths

Now the problem is to find a method of quickly computing the cost for every path

    -> the way to do this is to precompute a lot of yucky arrays
        -> generate these arrays using a similar reccurrence to psa

*/



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 3e5 + 5;
const ll MOD = 1e9 + 7;

int n;
ll rate[MAXN][2];

ll psa[MAXN][2];

// sumltor[i][0] = 0 * a[i] + 1 * a[i+1] + 2 * a[i+2] + ... 
// sumrtol[i][0] = 2*n * a[i] + (2*n-1) * a[i+1]

ll sumltor[MAXN][2];
ll sumrtol[MAXN][2];

ll rsq(int l, int r, int col) {
    return psa[r][col] - psa[l-1][col];
}


void solve() {
    cin>>n;

    for (int i=1;i<=n;i++) cin>>rate[i][0];
    for (int i=1;i<=n;i++) cin>>rate[i][1];

    for (int i=1;i<=n;i++) {
        psa[i][0] = psa[i-1][0] + rate[i][0];
        psa[i][1] = psa[i-1][1] + rate[i][1];
    }
    

    // Generate the sumltor array
    // ---------------------------------------------------------
    ll firstBoiTop = 0;
    ll firstBoiBot = 0;
    for (int i=1;i<=n;i++) {
        firstBoiTop += rate[i][0] * (i-1);
        firstBoiBot += rate[i][1] * (i-1);
    }

    sumltor[1][0] = firstBoiTop;
    sumltor[1][1] = firstBoiBot;

    for (int i=2;i<=n;i++) {
        sumltor[i][0] = sumltor[i-1][0] - rsq(i, n, 0);
        sumltor[i][1] = sumltor[i-1][1] - rsq(i, n, 1);
    }
    // ---------------------------------------------------------

    // Generation the sumrtol array
    // ---------------------------------------------------------
    firstBoiTop = 0;
    firstBoiBot = 0;

    for (int i=1;i<=n;i++) {
        firstBoiTop += rate[i][0] * (2*n-i);
        firstBoiBot += rate[i][1] * (2*n-i);
    }

    sumrtol[1][0] = firstBoiTop;
    sumrtol[1][1] = firstBoiBot;

    for (int i=2;i<=n;i++) {
        sumrtol[i][0] = sumrtol[i-1][0] - ((2*n-1) * rate[i-1][0]) + rsq(i, n, 0);
        sumrtol[i][1] = sumrtol[i-1][1] - ((2*n-1) * rate[i-1][1]) + rsq(i, n, 1);
    }
    // ---------------------------------------------------------

    ll ans = 0;
    ll base = 0;


    for (int i=1;i<=n;i++) {

        ll time = (i-1)*2;

        ll pot = base;

        if (i%2==1) {
            pot += sumltor[i][0] + (psa[n][0] - psa[i-1][0]) * time;
            pot += sumrtol[i][1];

        } else {
            pot += sumltor[i][1] + (psa[n][1] - psa[i-1][1]) * time;
            pot += sumrtol[i][0];
        }

        ans = max(pot, ans);

        base += time * (rate[i][0] + rate[i][1]); 
        if (i%2==0) base += rate[i][0];
        else base += rate[i][1];
    }

    cout<<ans<<endl;


}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}