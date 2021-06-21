/*
~~~ CCC '16 S5 - Circle of Life ~~~

Key Concepts: Bit Operations

The trick is to notice that you can efficiently advance by k generations
    - if k is a power of 2

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, t;
string col; // circle of life

// advances a state by step generations (only works if step is a power of 2)
string advanceGen(string state, ll step) { 
    string newState = "";
    ll cell, left, right;
    for (int i=0;i<n;i++) {
        left = i-step, right = i+step;
        left %= n, right %= n; // cyclic property
        if (left<0) left = n+left;
        
        // Ck[i] = C[i-k] XOR C[i+k]
        int cell = (state[left] - '0') ^ (state[right] - '0');
        newState += to_string(cell);
    }

    return newState;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>t;
    cin>>col;

    ll LSB;
    while (t) {
        LSB = t & -t;
        t -= LSB;
        // advance by every set bit in T (to guarantee you're only advancing by powers of 2)
        col = advanceGen(col, LSB);
    }

    cout<<col<<"\n";
}