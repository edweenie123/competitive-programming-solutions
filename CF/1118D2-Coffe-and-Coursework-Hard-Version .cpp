/*
~~~ 1118D2 - Coffe and Coursework (Hard Version) ~~~

Key Concepts: Binary Search, Greedy

Insight 1:
We can binary search over the minimum number of days because:
    if we can write m pages with x days,
        it is guaranteed that we can write m mages with x+1 days

Insight 2:
For a given amount of days, we can maximize the number of pages we complete using a greedy strat
    -> we sort the coffees in decreasing caffeine order
        and fill each day one by one from left to right
        when we reach the end of the days, we restart at day 1
    
    This works because we minimize the amount of caffeine that is lost due to decay
        -> i can't really prove this, but its quite intuitive

Time Complexity: O(n log n)

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5;


int n, m;
vector<int> caf;

bool isPossible(int days) {

    ll pages = 0;

    for (int i=0;i<n;i++) {
        int sub = i / days;
        pages += max(0, caf[i] - sub);
    }

    return pages >= m;

}

int bs() {
    int lo = 1, hi = 2e5, mid, best=-1;

    while (lo <= hi) {

        mid = (lo + hi) / 2;

        if (isPossible(mid)) {
            hi = mid - 1;
            best = mid;
        } else {
            lo = mid + 1;
        }
    }

    return best;
}

int main() {
    cin>>n>>m;

    int tmp;
    for (int i=0;i<n;i++) 
        cin>>tmp, caf.push_back(tmp);
    
    sort(caf.begin(), caf.end(), greater<int>());

    int ans = bs();
    cout<<ans<<"\n";
}