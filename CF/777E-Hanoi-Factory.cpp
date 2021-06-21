/*
~~~ 777E - Hanoi Factory ~~~

Key Concepts: Ordered DP, Segment Tree (RMQ)

Very good problem imo

Lets try sorting the rings by their outer radius (since it doesn't matter what order the rings are given in)
    -> Lets define two rings i and j

    Constraint 1:
    Notice that ring j can only go on top of ring i if it appears before ring i in the sorted arrray
    
    Constraint 2:
    Ring j must have a larger outer radius than the inner radisu of ring i
        -> this is so ring j doesn't fall into ring i
    
    Therefore the search space of ring j is some contiguous segment of the rings array [lo, hi]
        such that lo is the smallest idx such that rings[lo] has an outer radius greater than the inner radius of ring i

        and hi is the index of ring i - 1 

    Let dp[k] = the height of the structure if the base is ring k

    Because we want to find the optimal ring j to put on top of ring i:
        we want to find ring j such that dp[j] is maximized
    
    This givens a pretty simple bottom up ordered DP algorithm 
        where the number of states is O(n) and the state transition is O(n)
            So the Time Complexity is O(n^2) -> too slow!

    Wait a second...
        In the DP state transition, we want to find the maximum value within a contigous range
            -> use segment tree to optimize!!! (range maximum query)
                state transitions are now O(log n)
            -> this yields a time complexity of O(nlogn)

*** Edge case when you have multiple rings with the same outer radius
    Simply implementing this alg will yeild WA on testcase 17

    Consider the example where you only have rings with the same outer radius but different inner radius

        -> Notice it is always optimal to put the ring with the smallest inner radius at the top of the array
            -> any other arrangement may be suboptimal 
                because if the inner radius is larger, more rings would fall through it
                    You have a larger search space for ring j 
                        if the search space is larger -> more chances for a larger value

*/


#include<bits/stdc++.h>
using namespace std;

#define print(x) cout<<(#x)<<" = "<<x<<"\n";
typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 1e5 + 5;

struct ring {
    int in, out, h;
};

bool cmp(ring a, ring b) {
    if (a.out!=b.out)
        return a.out < b.out;

    // if same out then you want to put the ring with the smallest in at the top
    return a.in < b.in; 
}

int n;
vector<ring> rings;

ll dp[MAXN]; // dp[i] = max height of structure that has a base at ring i
ll seg[MAXN*4]; // seg tree for dp array

void update(int node, int l, int r, int idx, ll val) {
    if (l==r) {
        dp[idx] = val;
        seg[node] = val;
        return;
    }

    int mid = (l+r) / 2;

    if (l<=idx&&idx<=mid) update(node*2, l, mid, idx, val);
    else update(node*2+1, mid+1, r, idx, val);

    ll c1 = seg[node*2], c2 = seg[node*2+1];

    seg[node] = max(c1, c2);
}

ll query(int node, int l, int r, int ql, int qr) {
    if (ql>qr) return 0;

    if (qr<l || ql>r) return 0;

    if (ql<=l&&qr>=r) return seg[node]; // made mistake here lmao (i swaped the ranges around)

    int mid = (l+r)/2;
    ll c1 = query(node*2, l, mid, ql, qr);
    ll c2 = query(node*2+1, mid+1, r, ql, qr);


    return max(c1, c2);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>n;

    int a, b, h;
    for (int i=1;i<=n;i++) {
        cin>>a>>b>>h;
        rings.push_back({a, b, h});
    }

    rings.push_back({-1, -1, -1}); // dummy value
    sort(rings.begin(), rings.end(), cmp);

    for (int i=1;i<=n;i++) {
        // all processed rings have a smaller outer
        // but it might be too small -> falls through the current one
        // outer for the "hat" must be > inner of current ring

        int outer = rings[i].out;
        int inner = rings[i].in;
        int height = rings[i].h;


        int firstHat = upper_bound(rings.begin(), rings.end(), ring{(int)1e9, inner, (int)1e9}, cmp) - rings.begin();

        ll bestHatHeight = query(1, 1, n, firstHat, n) + height;

        update(1, 1, n, i, bestHatHeight);
    }

    ll ans = 0;

    for (int i=1;i<=n;i++) 
        ans = max(ans, dp[i]);
    
    cout<<ans<<"\n";
}