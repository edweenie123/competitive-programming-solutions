/*
~~~ CCC '13 S5 - Factor Solitaire ~~~

Key Concepts: Greedy Algorithms

We work backwards from N to get the answer:

Let Q = the number before N, let A and B be the factors of Q

Q + A = N
Q = N - A
Q % A = 0
(N - A) % A = 0

Therefore => N % A = 0

For some reason, if we continuously subtract the highest factor of N, it will always give the optimal answer
    - We always want to maximize the value of A
    - Kinda makes sense because maximizing A, will minimize the cost B

*/


#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin>>N;

    int cost = 0;
    while (N != 1) {
        
        int A, B;
        for (A=N-1;A>=1;A--) // maximize the value of A
            if (N%A==0) break;

        N -= A;
        B = N/A;
        cost += B/A;
    }

    cout<<cost<<"\n";
}