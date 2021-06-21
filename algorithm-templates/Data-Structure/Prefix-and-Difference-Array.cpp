/*
~~~ Prefix Sum Array + Difference Array ~~~

Prefix Sum Array:
    Range Query - O(1)
    Point Update - O(n)

Difference Sum Array:
    Rebuild original - O(n)
    Range Update - O(1)

PSA[i] stores the cumulative sum from index ARR[0] to ARR[i]

D[i] stores the difference between ARR[i] and ARR[i-1]
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, ARR[MAXN], PSA[MAXN], D[MAXN];

int PSARangeQuery(int l, int r) { // return the sum from index l to r using prefix sum
    return PSA[r] - PSA[l-1];
}

void RangeUpdate(int l, int r, int k) { // increment ARR[l..r] by k using difference array
    D[l] += k;
    D[r+1] -= k;
}

void RebuildArray() { // rebuilds the ARRay from the difference ARRay
    ARR[0] = D[0];
    for (int i=1;i<n;i++) {
        ARR[i] = ARR[i-1] + D[i];
    }
}

void build() {
    // build PSA
    PSA[0] = ARR[0];
    for (int i=1;i<n;i++) {
        PSA[i] = PSA[i-1] + ARR[i];
    }
    // build D
    D[0] = ARR[0];
    for (int i=1;i<n;i++) {
        D[i] = ARR[i] - ARR[i-1];
    }
}

int main() {
    cin>>n;
    for (int i=0;i<n;i++) cin>>ARR[i];
    build();
}