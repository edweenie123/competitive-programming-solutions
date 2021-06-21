/*
~~~ Prime Generator ~~~

Key Concepts: Sieve of Eratosthenes

Upper Bound N = 10^9
We can check the primality of a number by checking if it is divisible by any primes < sqrt(N) ~= 32000

1. We can precompute primes below 32000 using sieve 
2. Then check if any number m-->n is divisible by these primes
3. If the number isn't divisble by any of these primes, it is also a prime
*/

#include <bits/stdc++.h>
using namespace std;

const int maxDivisor = 32000;
int t, m, n;
bool marked[maxDivisor];
vector<int> primes;
void sieve() {
    for (int p=2;p*p<=maxDivisor;p++) {
        if (!marked[p]) {
            for (int i=p*p;i<=maxDivisor;i+=p) {
                marked[i] = true;
            }
        }
    }
}

bool checkIfPrime(int num) {
    if (num==1) return false;
    for (int i=2;i<maxDivisor;i++) {
        if (!marked[i]) {
            if (num%i==0&&num!=i) return false;
        }
    }
    return true;
}

int main() {
    sieve();
    cin>>t;
    while (t--) {
        cin>>m>>n;
        for (int i=m;i<=n;i++) {
            if (checkIfPrime(i)) cout<<i<<endl;
        }
        if (t>0)cout<<endl;
    }
}