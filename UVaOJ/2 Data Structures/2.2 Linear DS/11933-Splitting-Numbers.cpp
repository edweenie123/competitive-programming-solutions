/*
~~~ UVa 11933 - Splitting Numbers ~~~

Key Concepts: Bit Manipulation

Iterate through every bit and check if it is on using Bitmask
    - If it is alternate between adding it to a(n) and b(n)
*/
#include <bits/stdc++.h>

using namespace std;

int n, a, b, mask;
bool oddInd;

int main() {
    while (true) {
        cin>>n;
        if (n==0) break;

        a = b = 0;
        oddInd = true;
        mask = 1;

        for (int i=0;i<32;i++) {
            if (n & mask) {
                if (oddInd) a ^= mask;
                else b ^= mask;

                oddInd = !oddInd;
            }

            mask<<=1;
        }

        cout<<a<<" "<<b<<endl;
    }
}