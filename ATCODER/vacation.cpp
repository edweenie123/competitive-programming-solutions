#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5+5;
int n, act[MAX_N][3], memo[MAX_N][3];

int findHappiness(int d, int last) {
    if (d==n-1) {
        int ans = 0;
        for (int i=0;i<3;i++)
            if (i!=last) 
                ans = max(ans, act[d][i]);
        return ans;
    }

    if (memo[d][last]!=-1) return memo[d][last];

    int happiness = 0;
    for (int i=0;i<3;i++) 
        if (i!=last) 
            happiness = max(happiness, act[d][i] + findHappiness(d+1, i));
    
    return memo[d][last] = happiness;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;i++) for (int j=0;j<3;j++) cin>>act[i][j];
    memset(memo, -1, sizeof(memo));

    cout<<findHappiness(0, 69)<<endl;
}