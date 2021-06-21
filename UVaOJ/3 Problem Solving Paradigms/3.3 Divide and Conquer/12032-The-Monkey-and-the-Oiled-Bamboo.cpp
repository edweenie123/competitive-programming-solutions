/*
~~~ UVa 12032 - The Monkey and the Oiled Bamboo ~~~

Key Concepts: Binary Search, Greedy

Very Similar to UVa 11413 - Fill the Containers

isPossible(int k) checks if it is possible to climb the ladder with k strength
    - Binary Search the optimal k value
*/

#include <bits/stdc++.h>

using namespace std;

int tests, n, rungs[100005];

bool isPossible(int k) {
    int height = 0, dif;
    for (int i=0;i<n;i++) {
        dif = rungs[i]-height;
        if (dif==k) k--;
        else if (dif>k) return false;
        height = rungs[i];
    }
    return true;
}

int bs() {
    int lo=1, hi=1e7, mid, best;

    while (lo<=hi) {
        mid = (lo+hi)/2;

        if (isPossible(mid)) {
            best = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    return best;
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin>>tests;

    for (int i=1;i<tests+1;i++) {
        cin>>n;
        for (int i=0;i<n;i++) cin>>rungs[i];

        cout<<"Case "<<i<<": "<<bs()<<endl;
    }
}