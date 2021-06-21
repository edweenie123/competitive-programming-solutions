/*
~~~ P4 - HEIGHT ~~~

Key Concepts: LIS

Same logic as LIS except we are optimizing sum instead of length

*/

#include<bits/stdc++.h>
using namespace std;

int n, arr[1001], dp[1001];

int solve() {
    for (int i=0;i<n;i++) dp[i] = arr[i];
    
    for (int i=0;i<n;i++) {
        for (int j=0;j<i;j++) {
            if (arr[j]<arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    int ans = 0;
    for (int i=0;i<n;i++) ans = max(ans, dp[i]);

    return ans;
}

int main() {
    cin>>n;
    for (int i=0;i<n;i++) cin>>arr[i];

    cout<<solve()<<endl;
}