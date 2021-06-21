/*
~~~ MNYC '17: Hurontario ~~~

Key Concepts: Hashing

We test all possible overlaps to check if they will create a valid string

We optimize this by maintaining a rolling hash for the suffix of a and the prefix of b
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll PRIME = 37;

string a, b;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>a>>b;

    int aLen = a.length(), bLen = b.length();
    int n = min(aLen, bLen);


    ll aHash = 0, bHash = 0;
    ll bPower = 1;

    int bestOverlap = 0;
    for (int i=1;i<=n;i++) { // test all possible overlaps
        int aChar = a[aLen-i] - 'A';
        
        aHash = (aHash * PRIME) % MOD;
        aHash = (aHash + aChar) % MOD;

        int bChar = b[i-1] - 'A';

        bHash = (bHash + (bChar * bPower) % MOD) % MOD;
        bPower = (bPower * PRIME) % MOD;

        if (aHash == bHash) 
            bestOverlap = i;
    }

    string ans = a.substr(0, aLen - bestOverlap) + b;

    cout<<ans<<"\n";
}