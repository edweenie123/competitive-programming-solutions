/*
~~~ ECOO '14 R3 P4 - Baby Talk ~~~

Key Concepts: Dyanamic Programming, String Hashing

DP aspect of the problem is decent, but string hashing is kinda yucky

Let dp[r] = length of the longest baby talk ending at index r

if (word[l:r] is a baby word)
    then dp[r] = (r-l+1) + dp[l-1]

*We check if word[l:r] is a baby word quickly, by spliting it into two halves and check if those halves are equal:
    Using string hashing in a PSA

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e3 + 5;
const ll PRIME = 31;
const ll MOD = 1e9 + 7;

string word;
int wordLen;
int dp[MAXN]; // dp[k] = longest baby talk ending at index k

ll hashPSA[MAXN];
ll exps[MAXN];

long long fast_exp(long long base, long long exp, long long mod, long long tot = 1) {
    for(;exp > 0; exp >>= 1, base = base * base % mod) if((exp & 1) == 1) tot = tot * base % mod;
    return tot;
}

void computeExps() {
    for (int i=0;i<MAXN;i++) {
        exps[i] = fast_exp(PRIME, i, MOD);
    }
}

ll computeHash(int l, int r) {
    ll hash = ((hashPSA[r] - hashPSA[l-1] + MOD) * exps[wordLen-1-l]) % MOD;
    return hash;
}

void initHashPSA() {
    ll pPower = 1;
    int len = word.length();

    hashPSA[0] = 0;
    for (int i=1;i<len;i++) {
        char c = word[i];
        hashPSA[i] = (hashPSA[i-1] + (c - 'A' + 1) * pPower) % MOD;
        pPower = (pPower * PRIME) % MOD;
    }
}

int longestBaby(int r) {
    if (dp[r]!=-1) return dp[r];

    int best = 0;

    for (int l=1;l<r;l++) {
        int len = (r-l) + 1;
        if (len%2!=0) continue;
        int mid = l + len/2 - 1;

        if (computeHash(l, mid) == computeHash(mid+1, r)) {
            best = max(best, longestBaby(l-1) + len);
        }
    }
    
    return dp[r] = best;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    computeExps();

    int t = 10;
    string tmp;
    
    while (t--) {
        word = " ";
        cin>>tmp;
        word += tmp;

        wordLen = word.length();
        initHashPSA();

        memset(dp, -1, sizeof(dp));
        int ans = 0;

        for (int i=1;i<=wordLen;i++) 
            ans = max(ans, longestBaby(i));
        

        cout<<ans<<"\n";
    }
}

