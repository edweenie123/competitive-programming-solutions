/*
~~~ COCI '06 Contest 5 #6 Dvaput ~~~

Key Concepts: Hashing, BS

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const int MAXL = 2e5 + 1;

int l;
string s;

vector<pll> allHash;
const ll PRIME1 = 52130871;
const ll MOD1 = 6483751031;
const ll PRIME2 = 308382098;
const ll MOD2 = 8688328793;
ll primePow1[MAXL];
ll primePow2[MAXL];
int code(char c) {
    return c-'a'+1;
}

bool containDuplicate(int len) {
    allHash.clear();

    // get initial hash
    ll hash1 = 0, hash2=0;
    for (int i=0;i<len;i++) {
        ll charHash1 = (code(s[i]) * primePow1[len-i-1]) % MOD1;
        hash1 = (hash1 + charHash1) % MOD1;
        //------------------------------------------------------------------------------
        ll charHash2 = (code(s[i]) * primePow2[len-i-1]) % MOD2;
        hash2 = (hash2 + charHash2) % MOD2;
    }

    allHash.push_back(pll{hash1, hash2});

    // use sliding window trick to get the rest of the hashes
    for (int i=1;i<l-len+1;i++) {
        // remove the char on the left
        ll oldChar1 = (code(s[i-1]) * primePow1[len-1]) % MOD1;
        hash1 = (hash1 - oldChar1 + MOD1) % MOD1;

        hash1 = (hash1 * PRIME1) % MOD1; // shift everything to the left

        // add char on the right
        ll newChar1 = code(s[i+len-1]);
        hash1 = (hash1 + newChar1) % MOD1;

        //-------------------------------------------------------------------
        
        // remove the char on the left
        ll oldChar2 = (code(s[i-1]) * primePow2[len-1]) % MOD2;
        hash2 = (hash2 - oldChar2 + MOD2) % MOD2;

        hash2 = (hash2 * PRIME2) % MOD2; // shift everything to the left

        // add char on the right
        ll newChar2 = code(s[i+len-1]);
        hash2 = (hash2 + newChar2) % MOD2;
        
        allHash.push_back(pll{hash1, hash2});
    }

    sort(allHash.begin(), allHash.end());

    pll prev = pll{-1, -1};
    for (auto elem: allHash) {
        if (elem==prev) return true;
        prev = elem;
    }

    return false;
}

// use binary search to get the maximum length of duplicated string
int bs() {
    int lo = 0, hi=l, mid, best=0;

    while (lo<=hi) {
        mid = (lo + hi) / 2;

        if (containDuplicate(mid)) {
            best = max(best, mid);
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return best;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    // precompute powers of prime
    primePow1[0] = 1, primePow2[0]=1;
    for (int i=1;i<MAXL;i++) {
        primePow1[i] = (primePow1[i-1] * PRIME1) % MOD1;
        primePow2[i] = (primePow2[i-1] * PRIME2) % MOD2;
    }
    
    cin>>l>>s;

    int ans = bs();

    cout<<ans<<"\n";

}