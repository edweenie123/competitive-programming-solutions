/*
~~~ 371D - Vessels ~~~

Key Concepts: Data Structures, binary search

This is a pretty fun problem

The solution is simply an improvement to the naive solution

Notice that the naive solution is slow because each update through at most N vessels 
    - you only go through vassels if the current vessel is full
    - therefore, you can just binary search for the first vessel that isn't full
    - Doing this will allow us to only look at the vessel's which aren't currently full

*/



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;

int n, m;
ll cap[MAXN]; // capacity of each vessel
ll water[MAXN]; // amt of water in each vessel

set<int> notFull;

void addWater(int idx, ll amt) {

    if (water[idx] == cap[idx]) { // boi is full!
        
        // bs for first vessel that isn't full
        auto next = notFull.upper_bound(idx); 

        if (next == notFull.end()) return; // everything full!

        addWater(*next, amt);
        
    } else { // boi is not full
        
        if (amt > (cap[idx] - water[idx])) { // overflow
            addWater(idx+1, amt - (cap[idx] - water[idx]));
        }

        water[idx] = min(cap[idx], water[idx] + amt);
        if (water[idx] == cap[idx]) 
            notFull.erase(idx);
    
    }


}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=1;i<=n;i++) {
        cin>>cap[i];
        notFull.insert(i);
    } 
    
    cin>>m;

    int t, p, x, k;
    while (m--) {
        cin>>t;

        if (t==1) {
            cin>>p>>x;

            addWater(p, x);
        } else {
            cin>>k;

            cout<<water[k]<<"\n";
        }
    }
}