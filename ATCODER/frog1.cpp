#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
int n, h[MAX_N], memo[MAX_N];

int cost(int s) {
    if (s==n-1) return 0;

    if (memo[s]!=-1) return memo[s];

    int j1 = abs(h[s]-h[s+1]) + cost(s+1);
    int j2 = s <= n-3 ? abs(h[s]-h[s+2]) + cost(s+2) : 1e6;

    return memo[s] = min(j1, j2);
}

int main() {
    cin>>n;
    for (int i=0;i<n;i++) cin>>h[i];
    memset(memo, -1, sizeof(memo));

    cout<<cost(0)<<endl;
}