/* 
~~~ DMOPC '19 Contest 6 P4 - Grade 12 Math ~~~

Key Concepts: PBDS (wow)

The indended solution is to use some yucky segment tree stuff

For each possible opinion value, we have a BBST:
    - The BBST stores all the indices of ppl with that specific opinion value

updates are relatively straight forward:
    - You just remove an index from a BBST and put it in another

queries can be answered using the order_of_key operation on the PBDS
    - order_of_key(k) returns the # of elements in the BBST that are strictly less than k

Time Complexity: O((N+Q)*log N)

*/


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
            tree_order_statistics_node_update> 
            ordered_set; 

const int MAXN = 5e5 + 5;
const int ADD = 5e5; // we add this number to every opinion get rid of negative values
int n, q;

int opin[MAXN];

// use a bbst to store the indices of each person with certain opinion i
ordered_set indices[MAXN*2]; 

// finds the # of values between index l and r with value c
int findAmtInRange(int l, int r, int c) {
    return indices[c].order_of_key(r+1) - indices[c].order_of_key(l);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;

    // add indices start with a opinion of 0
    for (int i=1;i<=n;i++) 
        indices[0+ADD].insert(i);
    
    int type, x, l, r, c;
    for (int i=0;i<q;i++) {
        cin>>type;

        if (type==1) {
            cin>>x;

            // move x up a level
            indices[opin[x]+ADD].erase(x);
            indices[opin[x]+ADD+1].insert(x);

            opin[x]++;

        } else if (type==2) {
            cin>>x;

            // move x down a level
            indices[opin[x]+ADD].erase(x);
            indices[opin[x]+ADD-1].insert(x);

            opin[x]--;
        } else {
            cin>>l>>r>>c;
            cout<<findAmtInRange(l, r, c+ADD)<<"\n";
        }
    }
}