/*
~~~ 1367E - Necklace Assembly ~~~

Key Concepts: Brute Force, Greedy

The solution is actual so simple, but i couldn't see it fsr

Insight 1:
The answer string must be x-periodic where x is a factor of k
    -> this is pretty intuitive and i got this insight

Cool tip: Apparently k^(1/3) is a good approximation for the number of factors a number has!

Insight 2:
We can iterate through the # of times a period occur and check if its possible to create that string
    -> IE, check if its possible to create a string with period x that appears t times

We use a greedy strategy to do this:    
    len = sum(freq[c] / t) for every character

    if len >= x, then it is possible to create the string (w/ period x that appears t times)

    This alg makes sense if you think about it

Therefore we can BF over all possible x and t to find the longest string
    -> maximze x * t

*/


#include<bits/stdc++.h>
using namespace std;

#define print(x) cout<<(#x)<<" = "<<(x)<<"\n";
int n, k;
string s;

int solve() {
    cin>>n>>k;
    cin>>s;

    vector<int> freq(26);

    for (auto c : s) freq[c-'a']++;

    int ans = 0;

    // iterate through all factors of k
    for (int i=1;i<=k;i++) {
        if (k % i != 0) continue;

        int maxTimes = 0;
        // iterate through the # of times the period can appear
        for (int j=1;j<=n/i;j++) {
            int periodLen = 0;
            for (int c=0;c<26;c++)
                periodLen += freq[c] / j;
            
            if (periodLen >= i) maxTimes = j;
        }

        ans = max(ans, i * maxTimes); // update ans
    }

    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        int ans = solve();
        cout<<ans<<"\n";
    }
}