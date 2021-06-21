/*
~~~ 372A - Counting Kangaroos is Fun ~~~

Key Concepts: Greedy, Binary Search 

This problem proved that i suck at greedy

Insight 1:
Our minimum possible answer is n/2
    - since each kangaroo can only hold one other kangaroo

This means that at most n/2 kangaroos can another kangaroo

Insight 2:
The n/2 largest kangaroos to potentially hold another kangaroo
    - we put these kangaroos in the bigBoi array
    - all other kangaroos are in the smallBoi array

For each smallBoi we use bs to find the smallest possible kangarro in the bigBoi array
    that can house the smallBoi

*/


#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> sz;
multiset<int> kLeft;

int main() {
    cin>>n;

    int tmp;
    for (int i=0;i<n;i++) {
        cin>>tmp;
        sz.push_back(tmp);
    }

    sort(sz.begin(), sz.end(), greater<int>());

    for (int i=0;i<n/2;i++)
        kLeft.insert(sz[i]);
    
    int removed = 0;
    for (int i=n/2;i<n;i++) {
        auto big = kLeft.lower_bound(sz[i]*2);

        if (big == kLeft.end()) continue;

        kLeft.erase(big);
        removed++;
    }

    int ans = n - removed;
    cout<<ans<<"\n";
}