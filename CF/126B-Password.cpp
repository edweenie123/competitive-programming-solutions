/*
~~~ 126B - Password ~~~

Key Concepts: Hashing, BS

Insight 1:
We can find the lengths of all prefixes that are also suffixes
    quickly using hashing -> O(n) 

Out of all these prefixes, we need to find the longest one that 
    also appears in the middle of the string 

Insight 2:
If prefix[i] appears in the middle of ths string...
    -> prefix[j] for all j < i  also appears in the string

This means we can perform binary search to find the optimal length
    -> we binary search over the lengths of all prefixes that are also suffixes

Note: i initially came up with a similar, but incorrect hashing alg
    -> cause im dumb

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 5;

const ll BASE = 37;
const ll MOD = 1e9 + 7;

ll pwr[MAXN];
vector<int> potLengths;
string s; int sLen;


ll f(char c) {
    return (c - 'a') + 1;
}

// finds all lengths of all prefixes that are also suffixes
void findLengths() {
    ll preHash = 0, sufHash = 0;
    int pow = 0;
    int sufIdx = sLen-1;
    for (int i=0;i<sLen-1;i++) {
        preHash = (preHash * BASE) % MOD;
        preHash = (preHash + f(s[i])) % MOD;
        
        sufHash = (sufHash + f(s[sufIdx]) * pwr[pow]) % MOD;
        sufIdx--; pow++;

        if (preHash == sufHash)
            potLengths.push_back(i+1);
    }

}

// finds substring of length len that is in the middle of the string
bool findSubstring(int len) {
    ll initHash = 0;
    int pow = len -1;

    for (int i=0;i<len;i++) {
        initHash = (initHash + f(s[i]) * pwr[pow]) % MOD;
        pow--;
    }

    ll midHash = initHash;
    // sliding window to find the substring in the middle
    for (int i=1;i+len<sLen;i++) {
        ll lastChar = (f(s[i-1]) * pwr[len-1]) % MOD;
        midHash = (midHash - lastChar + MOD) % MOD;
        midHash = (midHash * BASE) % MOD;
        midHash = (midHash + f(s[i+len-1])) % MOD;

        if (midHash == initHash)
            return true;
    }

    return false;
}

// bs through all the possible lengths of the answer string
string bs() {
    int lo = 0, hi = potLengths.size() - 1, mid, best=0;

    while (lo<=hi) {
        mid = (lo + hi) / 2;
        if (findSubstring(potLengths[mid])) {
            lo = mid + 1;
            best = potLengths[mid];
        } else 
            hi = mid - 1;
        
    }

    if (best == 0) return "Just a legend";
    else return s.substr(0, best);
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    pwr[0] = 1;
    for (int i=1;i<MAXN;i++) pwr[i] = (pwr[i-1] * BASE) % MOD;

    cin>>s; sLen = s.length();
    
    findLengths();
    string ans = bs();
    
    cout<<ans<<"\n";
}