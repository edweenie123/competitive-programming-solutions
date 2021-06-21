/*
~~~ 1360H - Binary Median ~~~

Key Concepts: constructive algorithms, binary search?

Here is the idea...

After removing n strings, it is obvious that the median is greater than
    exactly (2^m - n - 1) / 2 other strings 

We call (2^m - n - 1) / 2 the "order" of the median

With this, we can build the string for the median constructively

Start from the most significant bit and continue to the least significant bit

    -> try turning bit b on 
            if this causes the order of the current string to be greater than the order of median
                this bit must be off
            otherwise
                this bit must be on 


i got screwed over by the long long's and wasted a lot of time debugging


*/



#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int MAXM = 60 + 1;

ll n, m;
vector<ll> removed;

// returns the # of #'s that is less than k
ll orderOfKey(ll k) {

    auto iter = lower_bound(removed.begin(), removed.end(), k) - 1ll;

    ll inRemoved = iter - removed.begin() + 1ll;

    return k - inRemoved;
}


ll solve() {

    // this is the # of elements that must be smaller than the median
    ll order = ((1ll<<m) - n - 1ll) / 2ll;

    ll curNum = 0;

    // use constructive alg to generate the curNum
    for (int idx=m-1;idx>=0;idx--) {
        ll addOne = curNum | (1ll<<idx);
        
        ll addOneOrd = orderOfKey(addOne);
        ll addZeroOrd = orderOfKey(curNum);

        if (addOneOrd == order) {
            return addOne; // ??
        } else if (addZeroOrd == order) {
            return curNum;
        }
        
        if (addOneOrd < order)
            curNum = addOne;
    }

}

int main () {
    cin.sync_with_stdio(0); cin.tie(0);

    int TC; cin>>TC;

    while (TC--) {
        removed.clear();

        cin>>n>>m;

        string tmp;
        for (int i=0;i<n;i++) {
            cin>>tmp;

            // use bitset to convert binary into decimal
            removed.push_back(bitset<MAXM>(tmp).to_ullong());
        }

        sort(removed.begin(), removed.end());
        
        ll ans = solve();

        while (true) {
            if (!binary_search(removed.begin(), removed.end(), ans)) {
                break; 
            }  
            ans++;
        }

        // convert decimal to binary using bitmask
        string bs = bitset<MAXM>(ans).to_string().substr(MAXM-m, m);

        cout<<bs<<"\n";
    }
}