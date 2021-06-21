/*
~~~ ECOO '16 R2 P1 - Palindrome Panic ~~~

Key Concepts: Hashing

Let L = the length of the longest prefix or suffix of S that is a palindrome

Key insight is to realize that answer is always:
    |S| - L

We can use hashing to compute L quickly

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 5;

const ll MOD = 100000049;
const ll PRIME = 31;
ll POWERS[MAXN];

// hash(s) = s[0]*p^0 + s[1]*p^1 + s[2]*p^2...
// returns the length of the longest prefix that is palindrome
int prefixPalindrome (string s) { 
    int sLen = s.length();

    int longest = 1;    
    ll lHash=0, rHash=0;

    lHash = s[0]-'a'+1;
    rHash = s[1]-'a'+1;

    if (lHash==rHash) longest = 2;

    for (int l=3;l<=sLen;l++) {
        int half = l/2;
        if (l%2==0) {
            // add char to the BACK of lHash
            lHash = (lHash + (s[half-1]-'a'+1) * POWERS[half-1]) % MOD; 

            // add char the FRONT of rHash
            rHash = (rHash * PRIME) % MOD; // shift to right
            rHash = (rHash + (s[l-1]-'a'+1)) % MOD;
        } else {
            // remove the middle boi
            ll middleBoi = ((s[half]-'a'+1) * POWERS[half-1]) % MOD;
            rHash = (rHash - middleBoi + MOD) % MOD;

            // add the new char to FRONT of rHash
            rHash = rHash * PRIME; // shift to right
            rHash = (rHash + s[l-1]-'a'+1) % MOD;
        } 

        if (lHash==rHash) {
            longest = l;
        }
    }

    return longest;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    // precompute powers of prime
    POWERS[0] = 1;
    for (int i=1;i<MAXN;i++) {
        POWERS[i] = (POWERS[i-1] * PRIME) % MOD;
    }

    int tc = 10;
    string s;
    while (tc--) {
        cin>>s;
        
        int prefixLen = prefixPalindrome(s);
        reverse(s.begin(), s.end());
        int suffixLen = prefixPalindrome(s);

        int ans = s.length() - max(prefixLen, suffixLen);

        cout<<ans<<"\n";
    }
}