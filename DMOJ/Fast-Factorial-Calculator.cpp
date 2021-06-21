#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll; // ull is yucky
const ll MOD = 4294967296; // 2^32

ll fact[40]; // everything after 33! is divisble by 2^32
int n;

int main() {
    fact[0] = 1;
    fact[1] = 1;

    for (ll i=2;i<40;i++) 
        fact[i] = (fact[i-1] * i) % MOD;
    
    cin>>n;
    ll num;
    for (int i=0;i<n;i++) {
        cin>>num;

        if (num>33) cout<<0<<"\n";
        else cout<<fact[num]<<"\n";
    }
}