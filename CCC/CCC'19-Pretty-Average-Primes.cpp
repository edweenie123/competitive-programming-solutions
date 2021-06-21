/*
~~~ CCC '19 Pretty Average Primes ~~~

Key Concepts: Simple Math

Find two primes such that their average is N

- Idea -
let a = i, b = 2*N-i

Iterate through all possible values of i until a AND b are primes 
*/

#include <bits/stdc++.h>

using namespace std;

bool isPrime (int a) {
    for (int i=2;i*i<=a;i++) {
        if (a%i==0) return false;
    }
    return true;
}

int main() {
    int tests;
    cin>>tests;

    int n;
    while (tests--) {
        cin>>n;
        for (int i=2;i<n*2;i++) {
            if (isPrime(i)&&isPrime(2*n-i)) {
                cout<<i<<" "<<2*n-i<<endl;
                break;
            }
        }
    }
}