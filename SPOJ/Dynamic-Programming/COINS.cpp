// Main idea is to use recursion to generate all choices (exchange or not exchange)
// Use memoization to speed this process  

#include <bits/stdc++.h>
using namespace std;

map<long long, long long> dp;

long long maxCoin(long long n) {
    if (dp.count(n) == 1) {
        return dp[n];
    }if (n < 12) {
        dp[n] = n;
        return n;
    } else {
        dp[n] = maxCoin(n/2)+maxCoin(n/3)+maxCoin(n/4);
        return dp[n];
    }
}

int main() {
    string x;
    while (true) {
        getline(cin, x);
        if (x.empty()) break;
        long long c = stoll(x);
        cout<<maxCoin(c)<<endl;
    }
}