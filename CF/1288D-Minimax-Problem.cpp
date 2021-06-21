/*
~~~ 1288D - Minimax Problem ~~~

Key Concepts: Binary Search, bitmask

Fun problem to solve

The key insight is that we can bs over the min element in b

So we can fix x where x is the minimum element of b

To check if you can build b with this minimum element
    -> we use bitmasks!!!

        for each array, we generate a bitmask
            1 for if the value is greater than x at that index
    
    Lets store all our bitmasks in an array BMS

    The task is to find i, j such that i and j are elements in BMS
        and popcount(i | j) == m

            realize that if we combine these two arrays we will get a valid B array
    
    Instead of iterating through all possible elements in the array => O(n^2)

    We realize that BMS only has at most 256 unique elements
        -> so we can iterate through only unique elements instead
            this gives a time complexity of O(2^m * 2^m) = O(4^m) 

We need to perform this alg log(1e9) times because of bs
    so final time complexity is log(1e9 * 4^m)


*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 3e5 + 5;
const int MAXM = 8 + 5;
const ll MOD = 1e9 + 7;

int n, m;
int grid[MAXN][MAXM];
int bmIdx[300];

// check if its possible to construct b such that x is the min element
ii isPos(int x) {
    fill(bmIdx, bmIdx + 270, 0);

    for (int i=0;i<n;i++) {
        int bm = 0;
        
        for (int j=0;j<m;j++) 
            if (grid[i][j] >= x) bm |= (1<<j);
        
        bmIdx[bm] = i + 1;
    }

    for (int i=0;i<(1<<m);i++) {    
        
        // check if i exists
        if (bmIdx[i]==0) continue;

        // find the corresponding boi
        for (int j=0;j<(1<<m);j++) {
            
            // the union must cover all values
            if (__builtin_popcount(i|j) != m) continue;

            // check if j exists
            if (bmIdx[j]==0) continue;

            return {bmIdx[i], bmIdx[j]};
        }
    } 

    return {-1, -1};
}


void solve() {
    cin>>n>>m;

    for (int i=0;i<n;i++) 
        for (int j=0;j<m;j++)
            cin>>grid[i][j];

    ii ans;

    // do bs to find the maximume value of min(b_k)

    int lo = 0, hi = 1e9, mid;

    while (lo<=hi) {
        mid = (lo+hi) / 2;

        ii pot = isPos(mid);
        if (pot != ii{-1, -1}) {
            lo = mid + 1;
            ans = pot;
        } else 
            hi = mid -1;
    }

    cout<<ans.f<<" "<<ans.s<<endl;
}

int main() {
    solve();
}