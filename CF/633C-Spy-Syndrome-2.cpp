/*
~~~ 633C - Spy Syndrome 2 ~~~

Key Concepts: DP, hashing

Pretty good DP + hashing problem

The DP recurence is pretty simple and intuitive

    dp(idx) returns true if t[idx..] -> can be decyphered
            returns false otherwise
    
    for every idx we have to find i such that 
        t[idx..i] is a string in our dictionary (using hashing for speedup)

        and dp(i+1) is valid


*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXW = 1e3;
const int MAXN = 1e4 + 5;
const ll MOD = 30609722573;
const ll base = 31;

int n, m;
string t;

unordered_map<ll, string> htos; // hash to string

int dp[MAXN];

bool isValid(int idx) { // returns whether t(idx->n-1) a valid cipher
    if (idx == t.length()) return true;
    if (dp[idx] != -1) return dp[idx];

    ll hash = 0;
    ll pow = 1;

    bool isPos = false;

    for (int i=idx;i<idx+MAXW, i<t.length();i++) {
        char c = t[i];

        hash = (hash + pow * (c-'a'+1)) % MOD;
        pow = (pow * base) % MOD;

        if (htos.count(hash)) {
            if (isValid(i+1)) { 
                isPos = true;
                break;
            }
        }
    }

    return dp[idx] = isPos;
}

vector<string> ans; // words of the decoded cipher

void recur(int idx) { 
    ll hash = 0;
    ll pow = 1;

    for (int i=idx;i<idx+MAXW, i<t.length();i++) {
        char c = t[i];

        hash = (hash + pow * (c-'a'+1)) % MOD;
        pow = (pow * base) % MOD;

        if (htos.count(hash)) {
            if (isValid(i+1)) { 
                ans.push_back(htos[hash]);
                recur(i+1);
                break;
            }
        }
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>t>>m;

    string w;
    for (int i=0;i<m;i++) {
        cin>>w;

        string w_ = w;

        transform(w_.begin(), w_.end(), w_.begin(), ::tolower); // lowercase        
        reverse(w_.begin(), w_.end()); // reverse

        ll hash = 0;
        ll pow = 1;

        for (char c : w_) {
            hash = (hash + pow * (c-'a'+1)) % MOD;
            pow = (pow * base) % MOD;
        }
        htos[hash] = w;
    }


    memset(dp, -1, sizeof(dp));

    recur(0);

    for (auto a : ans) {
        cout<<a<<" ";
    } cout<<"\n";
}