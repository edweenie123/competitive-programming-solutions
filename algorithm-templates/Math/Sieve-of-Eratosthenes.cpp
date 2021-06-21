/*
~~~ Sieve of Eratosthenes ~~~

One of the most efficient algorithms to find all primes numbers up to N

- Algorithm - 

1. Create a list of integers 2 --> N (all unmarked)
2. Find the lowest unmarked number P and mark every multiple of p in the list (not including P)
3. Find the first unmarked number greater than P (the next prime) and repeat step 2

Once the algorithm terminates, all unmarked numbers in the list are prime numbers

- Optimizations -

1. You can start marking off multiples of P starting at P^2 as all multiples of P < P^2 will have already been marked
2. You only repeat step 2 until P^2 <= N because of optimization 1 

Time Complexity: O(nlog(log(n)))
*/

#include <bits/stdc++.h>
using namespace std;

int N;
bool marked[1000000000];

void sieve() {
    for (int p=2;p*p<=N;p++) { // iterate through all numbers and check if they are marked
        if (!marked[p]) {
            for (int i=p*p;i<=N;i+=p) 
                marked[i] = true; // mark all multiples of p
        }
    }

    // print all unmarked numbers (primes)
    for (int i=2;i<=N;i++) {
        if (!marked[i]) 
            cout<<i<<endl;
    }
}

int main(){
    cin>>N;
    cout<<"Print out all primes up to "<<N<<endl;
    sieve();
}