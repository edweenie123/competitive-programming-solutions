/*
~~~ Tree of Life ~~~

Key Concepts: Hashing

Lets say the length of the LCS is k (binary search this value)

We do dfs on the tree and at each node we compare all the hashes from the subtree rooted at each child
    - We do this quicky using a set

We always insert the smaller set into the bigger set fsr
    - This makes it a lot faster??

PS, you have to use two hashes cause yucky collisions

*/

#include<bits/stdc++.h>
using namespace std;

#define MP make_pair
typedef long long ll;
typedef set<pair<ll, ll>> yucky;

const int MAXN = 2e4 + 5;
const int MAXS = 1e5 + 5;

int n;
vector<int> tree[MAXN];
string dna[MAXN];
yucky boi; // empty set

const ll PRIME1 = 71211961;
const ll MOD1 = 2165170219;
const ll PRIME2 = 37;
const ll MOD2 = 1e9 + 7;

ll power1[MAXS], power2[MAXS];
// returns all hashes of s will a certain length
yucky computeHash(string s, int len) { 
    int sLen = s.length();
    if (len > sLen) return boi;
    yucky hashes; 
    
    ll curHash1 = 0, curHash2 = 0;
    for (int i=0;i<len;i++) {
        curHash1 = (curHash1 + ((s[i] - 'A' + 1) * power1[len-1-i]) % MOD1) % MOD1;
        curHash2 = (curHash2 + ((s[i] - 'A' + 1) * power2[len-1-i]) % MOD2) % MOD2;
    }

    hashes.insert(MP(curHash1, curHash2));

    int last, nxt;
    for (int i=len;i<sLen;i++) { // use a rolling hash to compute the hashes of the rest 
        last = s[i-len] - 'A' + 1, nxt = s[i] - 'A' + 1;

        curHash1 = (curHash1 - (last * power1[len-1])%MOD1 + MOD1) % MOD1;
        curHash1 = (curHash1 * PRIME1) % MOD1;
        curHash1 = (curHash1 + nxt) % MOD1;

        curHash2 = (curHash2 - (last * power2[len-1])%MOD2 + MOD2) % MOD2;
        curHash2 = (curHash2 * PRIME2) % MOD2;
        curHash2 = (curHash2 + nxt) % MOD2;

        hashes.insert(MP(curHash1, curHash2));
    }

    return hashes;
}

bool foundMatch = false;
yucky dfs(int u, int len) { // returns a set of all hashes of the subtree rooted at u
    if (foundMatch) 
        return boi;

    yucky mHash; // all hashes of subtree rooted at u
    yucky cHash; // all hashes of a subtree rooted at a child of u
    yucky uHash; // the hashes of the node u

    for (auto v : tree[u]) {
        cHash = dfs(v, len);

        if (mHash.size() < cHash.size()) swap(mHash, cHash);
        // add the hashes of v
        for (auto h : cHash) {
            if (mHash.count(h)) 
                foundMatch = true;
            
            mHash.insert(h);
        }
    }
    // add the hashes of node u
    uHash = computeHash(dna[u], len);
    for (auto h : uHash) {
        mHash.insert(h);
    }

    return mHash;
}

int bs() { // binary search the length of the LCS
    int lo = 0, hi = MAXS, mid, best=-1;

    while (lo<=hi) {
        mid = (lo+hi)/2;

        foundMatch = false;
        dfs(1, mid);

        if (foundMatch) {
            lo = mid + 1;
            best = max(best, mid);
        } else {
            hi = mid - 1;
        }
    }

    return best;
}

void getInput() {
    cin>>n;

    int par;
    for (int i=2;i<=n;i++) {
        cin>>par; tree[par].push_back(i);
    }

    string code;
    for (int i=1;i<=n;i++) {
        cin>>dna[i]; 
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    getInput();

    // precompute the powers of PRIME
    power1[0] = 1, power2[0] = 1;
    for (int i=1;i<MAXS;i++) {
        power1[i] = (power1[i-1] * PRIME1) % MOD1;
        power2[i] = (power2[i-1] * PRIME2) % MOD2;
    }

    int ans = bs();

    cout<<ans<<"\n";
}