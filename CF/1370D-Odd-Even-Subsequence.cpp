/*
~~~ 1370D - Odd-Even Subsequence ~~~

Key Concepts: Binary Search, Greedy

big sad -> i couldn't solve this during the contest
    but i should have been able to

I thought it was some yucky greedy solution, but bs was actually the key 

Insight 1:
We can either choose to minimize the max among the even indices OR 
    we minimize the max among the odd indices

Lets assume we minimize the odd indices for now

Let x be a potential answer
    -> for x to be valid all odd indices must have a value <= x

We can determine if for a given x, we can generate a valid subsequence in O(n) w/ greedy strategy
    -> iterate through the entire array
        if we are at a even index in the subsequence -> element to subsequence
        otherwise                                    -> all element only if <= x

    if we have at least k elements in the subsequence, then x is valid

*note we use the exact same logic if we wan't to optimize even indices

Insight 2: 
If x can give a valid subsequence, then x-1 is guaranteed to be valid as well
    -> because of this property, we can perform bs to find the minimum x that is still valid

let M = max element in array

Time Complexity: O(N * log M)


*/



#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, k;
int arr[MAXN];

bool isPossible(int x, int type) {

    int cnt = 0;
    for (int i=0;i<n;i++) {
        if (cnt % 2 == type) {
            if (arr[i] > x) continue;
        }
        cnt++;
    }

    if (cnt >= k) return true;
    return false;
}

int bs(int type) {
    int lo = 1, hi = 1e9, mid, best;

    while (lo<=hi) {
        mid = (lo + hi) / 2;

        if (isPossible(mid, type)) {
            hi = mid - 1;
            best = mid;
        } else {
            lo = mid + 1;
        }
    }

    return best;
}


int main() {
    cin>>n>>k;

    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }

    int minOdd = bs(0);
    int minEven = bs(1);

    int ans = min(minEven, minOdd);
    cout<<ans<<"\n";
}