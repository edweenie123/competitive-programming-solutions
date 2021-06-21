#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
int n, k, h[MAX_N], memo[MAX_N];

int cost(int s) {
    if (s==n-1) return 0;

    if (memo[s]!=-1) return memo[s];

    int bestJumpCost = 1e9;

    for (int i=1;i<=k;i++) {
        if (s<=n-1-i) {
            int jumpCost = abs(h[s]-h[s+i]) + cost(s+i);
            bestJumpCost = min(bestJumpCost, jumpCost);
        }
    }

    return memo[s] = bestJumpCost;
}

int main() {
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>h[i];
    memset(memo, -1, sizeof(memo));

    cout<<cost(0)<<endl;
}