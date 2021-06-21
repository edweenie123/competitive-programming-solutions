/*
~~~ 231C - To Add or Not to Add ~~~

Key Concepts: BS, PSA

Pretty fun little problem

Insight 1:
The # that reaches the maximum # of occurances already exists in the original array
    - you always use less operations to achieve the same # of occurances
    - makes sense intuitively, read editorial to prove it

Insight 2:
If we know the # that has the most occurances in the end
    -> we can use BS + PSA to find the # of operations needed to achieve the max frequency

Therefore, because of insight 1 and 2, we can iterate through all elements e in the array
    -> and see how many occurrances we can achieve if we try to make as many e's as possible


*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;

int n, k;
vector<int> arr;
ll psa[MAXN];

int bs(int right) {
    int lo = 1, hi = right, mid, best=right;

    while(lo<=hi) {
        mid = (lo + hi) / 2;

        ll rsq = psa[right] - psa[mid-1];
        ll rLen = right - mid + 1;

        ll delta = (arr[right] * (rLen)) - rsq;

        if (delta <= k) {
            best = mid;
            hi = mid - 1;
        } else 
            lo = mid + 1;
    }

    return right - best + 1;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    int tmp;
    for (int i=0;i<n;i++) 
        cin>>tmp, arr.push_back(tmp);

    arr.push_back(-1e9 - 5); // add dummy value (for 1 based indexing)

    sort(arr.begin(), arr.end());

    for (int i=1;i<=n;i++) psa[i] = psa[i-1] + arr[i];

    int maxFreq = 0, val;

    for (int i=1;i<=n;i++) {
        int bestFreq = bs(i);

        if (bestFreq > maxFreq) {
            maxFreq = bestFreq;
            val = arr[i];
        }
    }

    cout<<maxFreq<<" "<<val<<"\n";
}