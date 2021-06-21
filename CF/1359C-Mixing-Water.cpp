/*
~~~ 1359C - Mixing Water ~~~

Key Concepts: BS, yucky edge cases

Let a = (h + c) / 2

Print the first few cups and you will realize that the temp in the well is
    p1, a, p2, a, p3, a, p4, a, p5...

The p1, p2, p3, p4... start at h and are strictly decreasing towards a

Because its decreasing -> you can perform bs to find the optimal # of cups

Becareful with the yucky edge cases tho

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<double, int> ii;

long double h, c, t;
vector<ii> pot; // stores the potential answers {absDif, # cups}

void bs() {
    ll lo = 0, hi = 1e9, mid;
    
    ll bestN = -1;
    long double bestDif=1e9;

    while (lo<=hi) {
        mid = (lo+hi) / 2;

        double tmp = ((mid + 1) * h + mid*c) / (2*(mid+1) - 1);
        double error =  abs(tmp - t);

        if (tmp > t) lo = mid+1;
        else hi = mid-1;

        if (error < bestDif) {
            pot.clear();
            bestN = mid;
            bestDif = error;
            pot.push_back({bestDif, (2*(bestN+1)) - 1});
        } else if (error == bestDif) 
            pot.push_back({error, (2*(mid+1)) - 1}); // this might be ans if mid is smaller than bestN
        
    }
}

ll solve() {
    pot.clear();

    bs();

    double avg = (h+c) / 2;

    // edge cases
    pot.push_back({abs(avg - t), 2});
    pot.push_back({abs(h - t), 1});

    sort(pot.begin(), pot.end());

    return pot[0].second;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        cin>>h>>c>>t;

        ll ans = solve();

        cout<<ans<<"\n";
    }
}