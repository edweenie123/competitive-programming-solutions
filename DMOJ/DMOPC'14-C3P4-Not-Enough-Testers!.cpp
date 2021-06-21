/*
~~~ DMOPC '14 Contest 3 P4 - Not Enough Testers! ~~~ 

Key Concepts: Sieve of Eratosthenes, Binary Search

Use a sieve-like algorithm to find the # of factors each number has 

posK[k] stores all numbers with a exactly k factors

For each query: Use binary search on posK[K] to find the # of numbers between range(a, b)
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;
int TC, f[MAXN];
vector<int> posK[MAXN];

void sieve() {
    for (int i=1;i<MAXN;i++) {
        for (int p=i;p<MAXN;p+=i) {
            f[p]++;
        } 
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); 

    cin>>TC;
    int k, a, b;
    sieve();

    for (int i=1;i<MAXN;i++) {
        posK[f[i]].push_back(i);
    }

    while (TC--) {
        int cnt = 0;
        cin>>k>>a>>b;
        auto left = lower_bound(posK[k].begin(), posK[k].end(), a);
        auto right = upper_bound(posK[k].begin(), posK[k].end(), b);
        cout<<right-left<<"\n";
    }

}