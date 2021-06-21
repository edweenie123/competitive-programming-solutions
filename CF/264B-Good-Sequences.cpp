/*
~~~ 264B - Good Sequences ~~~

Key Concepts: Sieve, Number Theory, DP


Cool sieve trick to prime factorize a number quickly

Very complicated problem -> i don't understand the solution completely

Good Tutorial: https://atulac.wordpress.com/2016/12/12/kirlab-codechef-dec16/

I think this is a yucky bottom up only problem

Naive Solution: 

State:
dp[idx] = len longest subsequence ending with arr[idx]

State Transition:
    dp[i] = max(dp[j] | gdc(i, j) > 1) for j = (0..i-1)

This yields a O(n^2) solution which is too slow

Optimized solution

To improve this, you have to have to realize that adjacent elements
    have a common prime factor and each element has at most log(n) prime factors

This means that instead of iterating through all j in [0..i-1]
    we instead interate through all j in [prime factors of arr[i]] 

State: 
    dp[i] = length of longest subsequence such that the last element is divisble by i (prime #)

State Transition:
    dp[i] = max(dp[j] + 1) for j in [prime factors of arr[i]]

*/



#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int n, arr[MAXN];
int lpf[MAXN]; // lowest prime factor

void sieve() { // finds the lpf of every number
    for (int i=2;i<MAXN;i++) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            for (int j=2*i;j<MAXN;j+=i)
                if (lpf[j] == 0) lpf[j] = i;
        }
        
    }
}

vector<int> factors(int k) { // gets the prime factorization of each number using lpf
    vector<int> f;

    while (k > 1) {
        f.push_back(lpf[k]);
        k /= lpf[k];
    }

    return f;
}

int dp[MAXN]; // dp[i] = len of longest sequence such that i | last element 

int solve() {
    sieve();
    
    for (int i=0;i<n;i++) {
        int longest = 1;

        vector<int> pf = factors(arr[i]);

        for (auto f : pf) 
            longest = max(longest, dp[f] + 1);
        
        for (auto f : pf) 
            dp[f] = longest;
    }

    int ans = 1;
    for (int i=1;i<MAXN;i++)
        ans = max(ans, dp[i]);

    return ans;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=0;i<n;i++) cin>>arr[i];

    int ans = solve();
    cout<<ans<<"\n";
}