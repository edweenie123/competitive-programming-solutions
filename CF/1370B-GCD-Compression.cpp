/*
~~~ 1370B - GCD Compression ~~~

Key Concepts: Number Theory 

Super yucky problem...

Took me way to long to solve during the contest cause i tunnel visioned

Insight 1:
There are always at least n-1 pairs of elements in the array such that the sum is even
    -> because we have n-1 even sums, we satisfy the constraints (gcd > 1)

All we have to do is pair even elements with other even elements
    and odd elements with other odd elements

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n;

int solve() {
    vector<ii> even;
    vector<ii> odd;
    vector<ii> ans;
    
    cin>>n;

    int tmp;
    for (int i=1;i<=2*n;i++) {
        cin>>tmp; 

        if (tmp % 2 == 0) even.push_back(ii{tmp, i});
        else odd.push_back(ii{tmp, i});
    }


    for (int i=0;i<((int)even.size())-1;i+=2) {
        ans.push_back(ii{even[i].second, even[i+1].second});
    }
    

    
    for (int i=0;i<((int)odd.size())-1;i+=2) {
        ans.push_back(ii{odd[i].second, odd[i+1].second});
    }

    for (int i=0;i<n-1;i++) {
        ii a = ans[i];
        cout<<a.first<<" "<<a.second<<"\n";
    }
}

int main() {
    int TC; cin>>TC;

    while (TC--) 
        solve();
}