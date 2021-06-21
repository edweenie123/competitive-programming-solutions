/*
~~~ DMOPC '19 Contest 2 P3 - Selection ~~~

Key Concepts: PBDS, Fenwick also works

We store a BBST for each goodness value -> stores indices

Updates are pretty straight forward 

We just the order_of_key operation to find the number for elements 
    with an index in the range [l, r]


*/


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

const int MAXN = 3e5 + 3;
const int MAXG = 20 + 3;

int n, m;
ordered_set items[MAXG];
int itemValues[MAXN];


int findCthBest(int l, int r, int c) {
    int itemCnt = 0;

    for (int val=20;val>=0;val--) {
        // # of items w/ index between [l, r] w/ goodness val
        int numItems = items[val].order_of_key(r+1) - items[val].order_of_key(l);
        itemCnt += numItems;

        if (itemCnt >= c) 
            return val;
    }

    return -1;

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    for (int i=1;i<=n;i++) {
        cin>>itemValues[i];
        items[itemValues[i]].insert(i);
    }

    int type, a, b, l, r, c;
    for (int i=0;i<m;i++) {
        cin>>type;
        if (type==1) {
            cin>>a>>b;

            items[itemValues[a]].erase(a);
            items[b].insert(a);

            itemValues[a] = b;
        } else {
            cin>>l>>r>>c;

            int ans = findCthBest(l, r, c);
            cout<<ans<<"\n";
        }
    }
}