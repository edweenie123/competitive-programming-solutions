/*
~~~ Facebook Hacker Cup 2015 Round 1 - Homework ~~~

Key Concepts: Sieve of Eratosthenes

Use sieve to precompute the primacity of every number in the range 0-1e7
*/
#include <bits/stdc++.h>

using namespace std;

const int m = 10000005;
int primacity[m], tests, a, b, k;

void sieve() {
    memset(primacity, 0, sizeof(primacity));

    for (int i=2;i<m;i++) {
        if (!primacity[i]) {
            for (int p=i;p<=m;p+=i) {
                primacity[p]++;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    sieve();

    cin>>tests;

    for (int t=1;t<=tests;t++) {
        cin>>a>>b>>k;
        int cnt = 0;
        for (int i=a;i<=b;i++) 
            if (primacity[i]==k) cnt++;
        
        cout<<"Case #"<<t<<": "<<cnt<<endl;
    }
}