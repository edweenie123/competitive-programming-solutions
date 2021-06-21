/*
~~~ UVa 11136 - Hoax or What ~~~

Key Concepts: Multiset

std::sets in cpp are implementations of Balance Binary Search Trees
    insert + delete + findMin/findMax can all be done in O(log n)

urn.begin() returns an iterator which points to the min number
urn.end() returns an iterator which points to 1 past the max number so do --urn.end()
*/

#include <bits/stdc++.h>

using namespace std;

multiset<int> urn;
multiset<int>::iterator lowest, highest;

int main() {
    int n, k, temp;

    long long paid;
    while (cin>>n&&n) {
        paid = 0;
        urn.clear();
        for (int i=0;i<n;i++) {
            cin>>k;
            for (int j=0;j<k;j++) {
                cin>>temp;
                urn.insert(temp);
            }

            lowest = urn.begin();
            highest = --urn.end();
            paid += *highest - *lowest;
            
            urn.erase(lowest);
            urn.erase(highest);
        }
        cout<<paid<<endl;
    }
}