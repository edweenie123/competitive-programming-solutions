/*
~~~ TLE '16 Contest 6 (Mock CCC) S3 - Hyper Fax ~~~

Key Concepts: DP, Greedy

First insight:
You always pick up pies if you run over them
    -> this creates a contigious range of positions where you have travelled

Kinda weird DP where the thing you memoize is the remaining amount of hype you have left for a given range


*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e3 + 5;
const ll INF = 2e15;

vector<ii> allPie;

ll pos[MAXN];
ll hype[MAXN];
ll psa[MAXN]; // psa for hype

ll dp[MAXN][MAXN][2];

int n;
int strIdx;

ll rangeSum(int l, int r) {
    return psa[r] - psa[l-1];
}

ll maxHypeLeft(int l, int r, bool isEnd) {

    if (l > r) return -INF;
    if (r < strIdx || l > strIdx) return -INF;
    if (l <= 0 || r > n) return -INF;
    if (l==r&&l==strIdx) return hype[strIdx];
    if (dp[l][r][isEnd] != -1) return dp[l][r][isEnd];

    ll close, far, leftClose, leftFar;

    if (isEnd) {
        
        close = maxHypeLeft(l, r-1, true);
        far = maxHypeLeft(l, r-1, false);

        leftClose = close - (pos[r] - pos[r-1]);
        leftFar = far - (pos[r] - pos[l]);

    } else {
        close = maxHypeLeft(l+1, r, false);
        far = maxHypeLeft(l+1, r, true);

        leftClose = close - (pos[l+1] - pos[l]);
        leftFar = far - (pos[r] - pos[l]);
    }

    ll bestLeft = -INF;

    if (leftClose >= 0)
        bestLeft = max(bestLeft, leftClose);

    if (leftFar >= 0)
        bestLeft = max(bestLeft, leftFar);    

    // add hype gained from current pie
    if (bestLeft >= 0) {
        ll pieHype = isEnd ? hype[r] : hype[l];
        bestLeft += pieHype;
    }

    return dp[l][r][isEnd] = bestLeft;
}


int main() {

    cin.sync_with_stdio(0); cin.tie(0);

    cin>>n;

    ll x, d;

    for (int i=0;i<n;i++) {
        cin>>x>>d;
        allPie.push_back({x, d});
    }

    sort(allPie.begin(), allPie.end());

    for (int i=0;i<n;i++) {

        pos[i+1] = allPie[i].first;
        hype[i+1] = allPie[i].second;

        psa[i+1] = psa[i] + hype[i+1];

        if (pos[i+1] == 0) 
            strIdx = i+1;
        
    }

    for (int i=0;i<MAXN;i++) 
        for (int j=0;j<MAXN;j++)
            for (int k=0;k<2;k++)
                dp[i][j][k] = -1;

    ll ans = 0;

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i<=strIdx && j>=strIdx) {
                if (maxHypeLeft(i, j, true) >= 0 || maxHypeLeft(i, j, false) >= 0) {
                    ans = max(ans, rangeSum(i, j));
                }
            }
        }
    }

    cout<<ans<<endl;
}