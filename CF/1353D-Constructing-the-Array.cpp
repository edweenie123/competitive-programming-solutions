/*
~~~ 1353D - Constructing the Array ~~~

Key Concepts: Set (changing constructor)

The solution is pretty cool imo

The idea is to store all the ranges in a set
and change the comparator the set such that 
the minimum element will be the longest range 

After processing a range, 2 new ranges are added to the set

Time complexity: O(n log n)

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
typedef pair<int, int> ii;

// makes next range always at the minimum element in the set
bool cmp(const ii &a, const ii &b) {
    int lenA = a.second - a.first + 1;
    int lenB = b.second - b.first + 1;

    if (lenA == lenB) return a.first < b.first;

    return lenA > lenB;
}

// weird syntax to change comparator for the set
set<ii, decltype(cmp)*> ranges(cmp);
int arr[MAXN];

void solve(int n) {
    ranges.clear();
    memset(arr, 0, sizeof(arr));

    ranges.insert({1, n});

    for (int i=1;i<=n;i++) {
        // get first range in the set
        auto iter = ranges.begin();
        ranges.erase(iter);

        ii nextRange = *iter; 
        int l = nextRange.first, r = nextRange.second;

        int mid = (l + r) / 2;

        arr[mid] = i; // complete the operations

        // add the new ranges to the set
        ranges.insert({l, mid - 1});
        ranges.insert({mid+1, r});
    }
}


int main() {
    int TC; cin>>TC;

    int n;
    while (TC--) {
        cin>>n;

        solve(n);

        for (int i=1;i<=n;i++) {
            cout<<arr[i]<<" ";
        } cout<<"\n";
    }
    
}