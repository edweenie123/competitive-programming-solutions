/*
~~~ COCI '13 Contest 1 #5 Organizator ~~~

Key Concepts: Number Theory

Insight #1: 
Let K be the teamsize
    M be the # of clubs that are divisble by K

The max number of people in the finals is K * M

Insight #2:
We can compute the # of #'s that are divible by K using a sieve like algorithm
    - because of harmonic series it doesn't TLE

The solution is the just try every single K and find the one that leads to the max K * M

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5;

int freq[2000005]; // store the freq of each elem
int factorFreq[2000005]; // stores the freq of each factor

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;

    int tmp;
    for (int i=0;i<n;i++) {
        cin>>tmp;
        freq[tmp]++;
    }

    // another way of finding the freq of all factors
    // because of yucky harmonic series it doesn't TLE
    for (int i=1;i<=2000000;i++) {
        int cnt = 0;

        for (int j=i;j<=2000000;j+=i) 
            cnt += freq[j];
        
        factorFreq[i] = cnt;

    }

    ll ans = 0;
    // find the optimal team size
    for (ll i=1;i<=2000000;i++) {
        if (factorFreq[i]>=2) ans = max(ans, factorFreq[i] * i);
    }
    
    cout<<ans<<"\n";
}