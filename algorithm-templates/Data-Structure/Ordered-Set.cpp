/*

The Ordered Set is an implementation of a "Balanced Binary Search Tree"

Its basically the same thing as a set, but it can perform more operations

find_by_order(k) - returns iterator to the kth largest element (counting from 0)
order_of_key(k)  - returns the # of elements that are strictly less than k

Both operations are O(log n)

NOTE: ordered sets don't work with duplicate items
To get duplicate items to work, you can make the ordered set to use pairs instead
    - the second element in a pair will contain a unique number

You have to change the typedef to do this though:

tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, 
            tree_order_statistics_node_update> 
            ordered_set; 

*/




#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, 
            tree_order_statistics_node_update> 
            ordered_set; 

int main() {
    ordered_set o_set;

    o_set.insert(1);
    o_set.insert(2);
    o_set.insert(3);
    o_set.insert(4);
    o_set.insert(5);
    o_set.insert(6);
    o_set.insert(7);

    int fourthLargest = *o_set.find_by_order(3);
}