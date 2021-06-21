/*
~~~ Dog Girls ~~~

Key Concepts: Hashing, big iq

Pretty good problem.

Insight 1:
Realize that a magic word is just the same string concatinated together any number of times

Insight 2: 
We can detect magic words quickly using hashing + PSA

Insight 3: 
We separate the string into blocks of a certain length to detect magic words
    - There are only l ways of doing this (where l is size of the block)
    - Therefore, we only have to loop l times

Final Time Complexity O(n^2) i think

*/

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int MAXN = 5e3 + 5;
string s; int sLen;

int num(char c) {
    return c-'a'+1;
}

const ll BASE = 1e4+7;
const ll MOD = 1e9+7;

ll POWERS[MAXN];
ll hashPSA[MAXN];
ll hashRange(int l, int r) {
    if (l==0) return hashPSA[r];
    return (hashPSA[r] - (hashPSA[l-1] * POWERS[r-l+1]) % MOD + MOD) % MOD;
}

unordered_set<ll> magicHashes;
void findMagicWords(int len) {
    
    ll coreHash, otherHash;
    int coreHashStr;

    // no point in seperating the strings in the same way again => wasting time
    // there are only len ways of seperating the string
    
    for (int i=0;i<len;i++) { // start separtion from i
        coreHash = hashRange(i, i+len-1);
        coreHashStr = i;
        for (int l=i+len;l<sLen-len+1;l+=len) {
            otherHash = hashRange(l, l+len-1);

            if (coreHash==otherHash) {
                magicHashes.insert(hashRange(coreHashStr, l+len-1));
            } else {
                coreHash = otherHash; // if they don't match => otherHash becomes the new coreHash
                coreHashStr = l;
            }
        }
    }
}

int tryAllLengths() {
    for (int i=1;i<=sLen/2;i++) 
        findMagicWords(i);

    return magicHashes.size();   
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    // precompute the powers of BASE
    POWERS[0] = 1;
    for (int i=1;i<MAXN;i++)
        POWERS[i] = (POWERS[i-1] * BASE) % MOD;

    cin>>s;
    sLen = s.length();

    // generate a psa for the hash
    hashPSA[0] = num(s[0]);
    for (int i=1;i<sLen;i++) 
        hashPSA[i] = ((hashPSA[i-1] * BASE) % MOD + num(s[i])) % MOD; 

    int ans = tryAllLengths();

    cout<<ans<<"\n";
}