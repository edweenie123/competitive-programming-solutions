/*
~~~ Longest Increasing Subsequence ~~~

Find the length of the LIS of an array of integers

- O(n^2) Solution -

dp[i] stores the length of LIS that ends that A[i]

In order to compute dp[i], we must find j such that:
    - dp[j] is maximized and j < i and A[j] < A[i] (the tail of dp[i])

    Once this j has been found (test all values of j):
        - dp[i] = dp[j] + 1 (length of tail + head)

The length of the LIS for the entire array is simply:
    - max(dp[i] | for i in [0..n-1])

- O(nlogn) Solution -

Let L(i) = the smallest ending value of all length i increasing subsequence.

Realize that L(i-1) will always be less than L(i)
    - Therefore L is sorted and is permeable to binary search

For each element in A:
    Update L by finding the k = (first element in L which is greater than or equal to A[i]) - use BS
    Update L[k] = A[i]
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;
int n, A[MAXN];

int dp[MAXN];

int LIS() {
    memset(dp, 0, sizeof(dp));

    int ans = 0;

    for (int i=0;i<n;i++) dp[i] = 1; // Length of LIS is at least 1

    for (int i=1;i<n;i++) {
        for (int j=0;j<i;j++) { // find best j value
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j]+1); 
            }
        }
        ans = max(ans, dp[i]); // find the MAXN value of dp[i]
    }
    return ans;
}

int L[MAXN];
int LIS_OPT() {
    int lenLIS = 0, pos;

    for (int i=0;i<n;i++) {
        pos = lower_bound(L, L+lenLIS, A[i]) - L; // returns index of first elem which is >= A[i]
        L[pos] = A[i]; // update L[pos] to a more optimal value 

        if (pos+1>lenLIS) lenLIS = pos + 1;
    }

    return lenLIS;
}

int main() {
    // freopen("input.txt", "r", stdin);

    cin>>n;
    for (int i=0;i<n;i++) cin>>A[i];

    cout<<"The length of the LIS of A is: "<<LIS_OPT()<<endl;

}   