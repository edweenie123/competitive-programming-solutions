/*
~~~ 960C - Subsequence Counting ~~~

Key Concepts: Binary, Constructive algorithms

Insight 1:
If we have K of the same elements
    -> this gives us 2^K - 1 valid subsequences

Insight 2:
Considered the array, [a, a, a, a, a, b, b, b]
    -> where b - a >= k

This gives use 2^K - 1 + 2^M - 1 valid subsequences
    -> where K is the number of a's and M is the number of b

We look at the binary representation of X 
    -> to determine the best way of creating the array


*/



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, d;
vector<ll> nums;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>x>>d;

    ll curNum = 1;

    for (ll i=32;i>=0;i--) {
        if (((1ll << i) - 1) <= x) {
            for (int j=0;j<i;j++) nums.push_back(curNum);
            curNum += d;
            x -= (1ll<<i) - 1;
        }
    }

    // i need to add some extra bois fsr
    while (x) {
        nums.push_back(curNum);
        x -= 1;
        curNum += d;
    }

    cout<<nums.size()<<"\n";
    for (auto val : nums) cout<<val<<" ";
    cout<<"\n";
}