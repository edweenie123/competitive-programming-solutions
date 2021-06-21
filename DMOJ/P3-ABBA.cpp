/*
~~~ P3 - ABBA ~~~

Key Concepts: Greedy Algorithms

Work backwards

if the end of t is 'A' -> we must have performed the 1st operation
if the end of t is 'B' -> we must have performed the 2nd operation

*/


#include<bits/stdc++.h>
using namespace std;

string s, t;

bool isPossible() {
    if (t.length() < s.length()) return false;

    while (t.length() > s.length()) {
        if (t.back()=='A')
            t.pop_back();
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    return s == t;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        cin>>s>>t;

        cout<<(isPossible() ? "YES" : "NO")<<"\n";
    }
}