/*
~~~ 455A - Boredom ~~~

Key Concepts: DP

Very simple dp

*/

#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound
#define ALL(x) x.begin(), x.end()

typedef long long ll;
const int MAXN = 1e5 + 5;

int n;
vector<ll> seq;

ll dp[MAXN];

ll maxScore(int idx) {
    if (idx == n) return 0;
    if (dp[idx] != -1) return dp[idx];

    ll nextIdx = UB(ALL(seq), seq[idx]+1) - seq.begin();
    ll numSame = UB(ALL(seq), seq[idx]) - seq.begin() - idx;

    ll take = seq[idx]*numSame + maxScore(nextIdx);

    ll noTake = maxScore(idx+1);

    return dp[idx] = max(take, noTake);
}

int main() {
    cin>>n;

    int tmp;
    for (int i=1;i<=n;i++) 
        cin>>tmp, seq.PB(tmp);
    
    sort(seq.begin(), seq.end());

    memset(dp, -1, sizeof(dp));

    ll ans = maxScore(0);
    cout<<ans<<"\n";
}