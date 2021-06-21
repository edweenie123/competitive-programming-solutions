/*
~~~ Binary Search Tree Test ~~~

Key Concepts: PBDS

Kinda straight implementation of PBDS

Since there are duplicate elements in the array -> we need to use the pair<int,int> trick for the elements

However, if we do this, how can we use the find_by_order / order_of_key operations
    - we don't know the specific id that each element has been given!

Answer we use the lower_bound operation to get the elements id and check if it exists

*/


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> ii;

typedef tree<ii, null_type, less<ii>, rb_tree_tag, 
            tree_order_statistics_node_update> 
            ordered_set; 

int n, m;
ordered_set arr;

map<int, set<int>> firstOccurenceIdx;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>n>>m;

    int elem; int id=0;
    for (int i=1;i<=n;i++) {
        cin>>elem; arr.insert(ii{elem, id++});
    }

    char type; int v;
    int lastAns = 0;

    while (m--) {
        cin>>type>>v;
        
        v = v ^ lastAns; // decript the value of v

        if (type=='I') arr.insert(ii{v, id++});
        else if (type=='R') {
            ii maybeV = *arr.lower_bound(ii{v, -1});

            if (maybeV.first==v)
                arr.erase(maybeV);
        }
        else if (type=='S') {
            ii vthSmallest = *arr.find_by_order(v-1);
            cout<<vthSmallest.first<<"\n";
            lastAns = vthSmallest.first;
        } else {
            ii maybeV = *arr.lower_bound(ii{v, -1});

            int ans;
            if (maybeV.first==v) ans = arr.order_of_key(maybeV) + 1;
            else ans = -1;

            cout<<ans<<"\n";
            lastAns = ans;
        }
    }

    for (auto e : arr) 
        cout<<e.first<<" ";
    cout<<"\n";
}   