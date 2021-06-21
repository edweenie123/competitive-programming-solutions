/*
~~~ DMPG '17 S1- Molly and Difference ~~~
Key Concepts: Implementation

Finding all pairs and finded the minimum absolute difference --> O(n^2)

This is too slow as N can be 10^6

To optimize this, we can sort the array first and just compare adjacent pairs --> O(nlog(n))

*/

#include <bits/stdc++.h>
using namespace std;

int n, a[10000000], d=2e9;
int main() {
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];

    sort(a, a+n);

    for (int i=0;i<n-1;i++) {
        int temp = abs(a[i]-a[i+1]);
        if (temp<d) d = temp;
    }
    cout<<d;
}