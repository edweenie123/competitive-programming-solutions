/*
~~~ 385C - Bear and Prime Numbers ~~~

Key Concepts: Sieve, PSA

Very ez in retrospect, im just a dumb boi

Prime factorize every number using spf sieve
    -> O(n log(log n))

Calculate f(p) for every p using the prime factorization

Create PSA for f to cacluate rsq(l, r)


*/


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
const int MAXX = 1e7 + 2;
const int MAXN = 1e6 + 5;

int n, m;
int spf[MAXX];
int arr[MAXN];
unordered_set<int> pf[MAXN];

ll freq[MAXX]; // freq[i] = how many array elements have i as factor | i is prime
ll psa[MAXX]; // psa for freq

void sieve() {
    for (int i=1;i<MAXX;i++) spf[i] = i;

    for (int i=2;i<MAXX;i+=2) spf[i] = 2;

    for (int i=3;i*i<MAXX;i++) {
        if (spf[i] == i) {
            for (int j=i*i;j<MAXX;j+=i) {
                if (spf[j]==j) spf[j] = i;
            } 
        }
    }
}

void primeFactorize() {

    for (int i=1;i<=n;i++) {
        int val = arr[i];
        while (true) {
            
            int factor = spf[val];
            if (factor==1) break;
            pf[i].insert(factor);
            val /= factor;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    sieve();

    cin>>n;

    for (int i=1;i<=n;i++) cin>>arr[i];

    primeFactorize();

    for (int i=1;i<=n;i++) 
        for (auto f : pf[i]) 
            freq[f]++;

    for (int i=1;i<MAXX;i++) psa[i] = psa[i-1] + freq[i];

    cin>>m;
    int l, r;
    while (m--) {
        cin>>l>>r;
        if (l >= 1e7) {
            cout<<0<<endl;
            continue;
        }

        r = min((int)1e7, r);
        
        ll ans = psa[r] - psa[l-1];
        cout<<ans<<endl;
    }
}