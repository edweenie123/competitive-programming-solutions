/*
~~~ CCO '11 P4 - Reorganization ~~~

Key Concepts: Data Structures (std::set), Greedy Algorithms

To greedily solve this problem, we need a DS which can perform:
    - insertion: log n
    - deletion: log n
    - binary search: log n

A std::set is perfoct for this

*/


#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef pair<int, int> ii; // (rank, id)
const int MAXN = 1e5+1;

int n, ranks[MAXN];
int employ[MAXN]; // number of workers for employee i

set<ii> seen;

int bs(int comp) {
    auto bestInd = seen.lower_bound(ii(-comp, -100)); // use bs to find a supervisor

    ii best = *bestInd;

    if (best.S==0) return 0; // can't find a supervisor

    int bestId = best.S;
    employ[bestId]++;

    if (employ[bestId]==2) { // remove elem from set if full
        seen.erase(bestInd);
    }

    return 1;
}


int solve() {

    for (int i=1;i<n;i++) {
        seen.insert(ii(-ranks[i], i));
    
        if (bs(ranks[i+1])) // continue if able to find supervisor
            continue;
        
        return 0;
    }

    return 1;

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=1;i<=n;i++) 
        cin>>ranks[i];
    
    int ans = solve();
    
    cout<<(ans!=0 ? "YES" : "NO")<<"\n";
}