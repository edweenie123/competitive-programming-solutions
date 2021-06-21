/*
~~~ CCO '10 P3 - Wowow ~~~

Key Concepts: PBDS Cheese

Lol ez 20 points

*/


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<ll, int> ii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, 
            tree_order_statistics_node_update> 
            ordered_set; 

const int MAXN = 1e6 + 3;
const int MAXR = 5e5 + 5;
int n;

int idToRating[MAXN];

ordered_set ratings; // (rating, id)

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    char type;
    int x, r, k;
    for (int i=0;i<n;i++) {
        cin>>type;

        if (type=='N') {
            cin>>x>>r;

            ratings.insert(ii{r, x});
            idToRating[x] = r;
            

        } else if (type=='M') {
            cin>>x>>r;

            ratings.erase(ii{idToRating[x], x});
            ratings.insert(ii{r, x});
            idToRating[x] = r;

        } else {
            cin>>k;
            int ans = (*ratings.find_by_order(ratings.size()-k)).second;
            cout<<ans<<"\n";
        }
    }
}