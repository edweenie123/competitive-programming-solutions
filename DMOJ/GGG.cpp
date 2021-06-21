/*
~~~ VM7WC '16 #2 Gold - GGG ~~~

Key Concepts: Dynamic Programming

Let ranges[i] = the index of arr1[i] in arr2
    - ranges can be generated in O(n) by storing the indices of each elem of arr2 in indArr2

Through oberservation, any increasing subsequence of ranges will yield a common subsequence of arr1 and arr2

Thus, the problem is simplified to finding the length of LIS of ranges:
    - this can be done in O(nlogn) time

Time Complexity: O(nlogn)
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;
int n1, n2, arr1[MAXN];

int ranges[MAXN], L[MAXN];

vector<int> indArr2(MAXN, -1);
int main() {
    cin.sync_with_stdio(0); cin.tie(0); 

    cin>>n1;
    for (int i=0;i<n1;i++) cin>>arr1[i];
    cin>>n2;

    int tmp;
    for (int i=0;i<n2;i++) {
        cin>>tmp;
        indArr2[tmp] = i;
    }

    // generate ranges
    int rangeIdx = 0;
    for (int i=0;i<n1;i++) {
        if (indArr2[arr1[i]]==-1) continue;
        ranges[rangeIdx] = indArr2[arr1[i]];
        rangeIdx++;
    }

    // find LIS of ranges
    int lenLIS = 0;
    for (int i=0;i<rangeIdx;i++) {
        int pos = lower_bound(L, L+lenLIS, ranges[i]) - L;
        L[pos] = ranges[i];
        if (pos+1>lenLIS) lenLIS++;
    }
    cout<<lenLIS<<"\n";
}