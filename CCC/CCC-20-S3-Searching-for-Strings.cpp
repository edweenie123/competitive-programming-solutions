/*
~~~ CCC '20 S3 - Searching for Strings ~~~

Key Concepts: Hashing

To check if a substring is a permutation of the needle in CONSTANT TIME:
    we check if the frequency of each character is the same

Thus, we can use a SLIDING WINDOW to across the haystack to find all permutations

To count unique permutations, we have to use a set to ensure we don't double count a permutation
    - However, directly storing strings in the set is too slow / MLE (idrk)

Therefore, we have to do hashing (yay)
    - We have to do ROLLING HASHING to not increase the time complexity
        - shifting the window to the left -> all character shift to the right -> multiply the hash by p

I had maintained two seperate hashes because problem is yucky and a single hash had collisions

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> llll;

string n, h;
int nLen, hLen;
int nFreq[26], hFreq[26];

ll MOD1 = 314231741;
ll PRIME1 = 53;

ll MOD2 = 193254049;
ll PRIME2 = 31;

ll curHash1 = 0;
ll curHash2 = 0;

set<llll> seen;

long long fast_exp(long long base, long long exp, long long mod, long long tot = 1) {
    for(;exp > 0; exp >>= 1, base = base * base % mod) if((exp & 1) == 1) tot = tot * base % mod;
    return tot;
}

bool sameFreq() {
    for (int i=0;i<26;i++) {
        if (nFreq[i] != hFreq[i])
            return false;
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>h;
    nLen = n.length();
    hLen = h.length();

    if (nLen > hLen) {
        cout<<"0\n";
        return 0;
    }

    for (int i=0;i<nLen;i++) {
        int c = n[i] - 'a';
        nFreq[c]++;
    }

    ll POWER1 = 1;
    ll POWER2 = 1;
    for (int i=hLen - nLen;i<hLen;i++) {
        int c = h[i] - 'a';
        hFreq[c]++;
        // cout<<h[i]<<"\n";
        curHash1 = (curHash1 + (c+1) * POWER1) % MOD1;
        POWER1 = (POWER1 * PRIME1) % MOD1;

        curHash2 = (curHash2 + (c+1) * POWER2) % MOD2;
        POWER2 = (POWER2 * PRIME2) % MOD2;
    }

    if (sameFreq()) {
        seen.insert(llll{curHash1, curHash2});
    }

    int oldChar = h[hLen-1] - 'a', newChar;

    ll maxPower1 = fast_exp(PRIME1, nLen-1, MOD1);
    ll maxPower2 = fast_exp(PRIME2, nLen-1, MOD2);

    for (int i=hLen-nLen-1; i>=0; i--) {
        oldChar = h[i+nLen] - 'a'; 
        newChar = h[i] - 'a';

        hFreq[oldChar]--;
        hFreq[newChar]++;

        curHash1 = (curHash1 - (((oldChar+1) * maxPower1)%MOD1) + MOD1) % MOD1;
        curHash1 = (curHash1 * PRIME1) % MOD1;
        curHash1 = (curHash1 + (newChar+1))%MOD1;

        curHash2 = (curHash2 - (((oldChar+1) * maxPower2)%MOD2) + MOD2) % MOD2;
        curHash2 = (curHash2 * PRIME2) % MOD2;
        curHash2 = (curHash2 + (newChar+1))%MOD2;

        if (sameFreq() && !seen.count(llll{curHash1, curHash2})) {
            seen.insert(llll{curHash1, curHash2});
        }
    }

    cout<<seen.size()<<"\n";
}