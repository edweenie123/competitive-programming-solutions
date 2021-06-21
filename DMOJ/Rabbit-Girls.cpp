/*
~~~ Rabbit Girls ~~~

Key Concepts: Simple Math
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k; cin>>n>>k;
    long long rem = n%k;

    cout<<(n<k ? k-n : min(rem, k-rem));
}