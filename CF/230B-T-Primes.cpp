// Key Concepts: Sieve of Eratosthenes 
// A number is a t-prime if it is a square of a prime
// Use sieve to precompute all squares of primes below 10^12  

#include <bits/stdc++.h>
using namespace std;

bool isPrime[1000001];
set<long long int> primeSquares;

void sieve() {
    int s = 1000000;
    memset(isPrime, 1, sizeof(isPrime));

    for (int p=2;p*p<=s;p++) {
        if (isPrime[p]) {
            for (int i=p*p;i<=s;i+=p) 
                isPrime[i] = 0;
        }
    }
    for (long long int p=2; p<s; p++) 
        if (isPrime[p])  
            primeSquares.insert(p*p); 
}

int main() {
    int n;
    long long num;
    cin>>n;
    
    sieve();
    while(n--) {
        cin>>num;
        primeSquares.count(num)?cout<<"YES":cout<<"NO";
        cout<<'\n';
    }
}