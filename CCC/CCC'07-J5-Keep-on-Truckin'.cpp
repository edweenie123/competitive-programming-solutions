/*
~~~ CCC '07 J5 - Keep on Trucken' ~~~

Key Concepts: Dynamic Programming


*/


#include<bits/stdc++.h>

using namespace std;

int a, b, n;
vector<int> dist = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

long long memo[40];

long long ways(int c) {
    if (dist[c]>=7000) return 1;

    if (memo[c]!=-1) return memo[c];
    long long ans = 0;

    for (int i=c+1;i<dist.size();i++) {
        int d = dist[i]-dist[c];
        if (d>=a&&d<=b)
            ans += ways(i);
    }

    return memo[c] = ans;
}


int main() {
    freopen("input.txt", "r", stdin);
    cin>>a>>b>>n;
    memset(memo, -1, sizeof(memo));

    int d;
    for (int i=0;i<n;i++) {
        cin>>d;
        dist.push_back(d);
    }

    sort(dist.begin(), dist.end());

    cout<<ways(0)<<endl;
}