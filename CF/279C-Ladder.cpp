/*
~~~ 279C - Ladder ~~~

Key Concepts: PSA, BS, dp (kinda)

Pretty fun problem -> cool trick with psa to determine if a subarray is increasing or decreasing

Insight 1:
We can determine if arr[l...r] is increasing or decreasing in O(1) using a cool PSA trick
    -> we define isIncreasing[i] = arr[i] <= arr[i+1]
        We create a PSA for this new array to perform range queries
            -> if psa[r-1] - psa[l-1] == r - l, then the entire range is increasing
    
    We use the same idea to determine if a subarray is decreasing

Insight 2:
In order to find a ladder
    -> we always want the increasing part at the beginning to be as long as possible
        this is pretty intuitive
    
    Therefore, we can BS for the end of the increasing sequence using the PSA in insight 1
        -> after you find the end, the rest of the subarray must be decreasing...

*/



#include<bits/stdc++.h>
using namespace std;

#define print(x) cout<<(#x)<<" = "<<(x)<<"\n";
const int MAXN = 1e5 + 5;

int n, m;
int arr[MAXN];
int psaIn[MAXN];
int psaDe[MAXN];

bool isIn(int l, int r) { // returns true if the subarray [l..r] is increasing
    if (l==r) return true;
    return psaIn[r-1] - psaIn[l-1] == r-l;
}

bool isDe(int l, int r) { // returns true if the subarray [l..r] is decreasing
    if (l==r) return true;
    return psaDe[r-1] - psaDe[l-1] == r-l;
}

bool isLadder(int l, int r) {
    if (isIn(l, r) || isDe(l, r)) return true;

    // bs for the furthest increasing seq
    int lo = l, hi = r, mid, best;
    while (lo <= hi) {

        mid = (lo + hi) / 2;

        if (isIn(l, mid)) {
            best = mid;
            lo = mid + 1;
        } else 
            hi = mid - 1;
    }

    // the rest must be decreasing for it be a ladder
    return isDe(best, r);
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    for (int i=1;i<=n;i++) 
        cin>>arr[i];


    for (int i=1;i<n;i++) {
        psaIn[i] = psaIn[i-1] + (arr[i] <= arr[i+1]);
        psaDe[i] = psaDe[i-1] + (arr[i] >= arr[i+1]);
    }

    int l, r;
    while (m--) {
        cin>>l>>r;

        bool ans = isLadder(l ,r);
        cout<<(ans ? "Yes" : "No")<<"\n";
    }
}