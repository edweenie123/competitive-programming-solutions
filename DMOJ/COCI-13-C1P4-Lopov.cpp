/*
~~~ COCI '13 Contest 1 #4 Lopov ~~~

Key Concepts: Greedy, Binary Search

This reminds of CF problems fsr

The greedy solution is pretty intuitive:
    You just always take the jewel with the highest value and put it in the worst bag
        Finding the worse bag can be done quickly using a set

*/


#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
typedef long long ll;
typedef pair<ll, ll> ii;

const int MAXN = 3e5 + 5;

int n, k;
vector<ii> items;
multiset<ll> bags;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>n>>k;

    ll m, v;
    for (int i=0;i<n;i++) {
        cin>>m>>v;
        items.PB({v, m});
    }

    ll c;
    for (int i=0;i<k;i++) 
        cin>>c, bags.insert(c);

    // sort items by their value
    sort(items.begin(), items.end(), greater<ii>());

    ll ans = 0;

    for (int i=0;i<n;i++) {

        ll val = items[i].F, mass = items[i].S;

        // find the worst bag for this item
        auto bestBag = bags.lower_bound(mass);

        if (bestBag == bags.end()) continue;

        // always take the greatest possible value
        ans += val;
        bags.erase(bestBag);
    }

    cout<<ans<<"\n";
}