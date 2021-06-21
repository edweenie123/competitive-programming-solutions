/*
~~~ 1332C - K-Complete Word ~~~

Key Concepts: Implementation, periodic?

Notice that all of these characters must be the same
(i, k-1) , (i+k, 2k-i-1), (i+2k, 3k-i-1)...

To minimize the # of changes we make all of these characters be equal to the most frequent one

Be careful in the case that k is odd -> it uses a different formula (the center of each block is the same)

*/

#include<bits/stdc++.h>
using namespace std;

int n, k;
string s;

int solve() {

    int changes = 0;

    for (int i=0;i<k/2;i++) {
        map<char, int> charFreq;

        // periodic property + palindrome property
        for (int j=0;j<n/k;j++) {
            charFreq[s[j*k + i]]++;
            charFreq[s[(j+1)*k - i - 1]]++;
        }
        
        int mostFreq = 0;
        for (auto x : charFreq) 
            mostFreq = max(mostFreq, x.second);
        
        int totalChar = (n / k) * 2;
        int delta = totalChar - mostFreq;

        changes += delta;
    }

    if (k % 2 == 1) {
        map<char, int> charFreq;

        for (int i=0;i<n/k;i++) 
            charFreq[s[i*k + k/2]]++;
        
        int mostFreq = 0;
        for (auto x : charFreq) 
            mostFreq = max(mostFreq, x.second);
        
        changes += n/k - mostFreq;
    }

    return changes;

}

int main() {
    int TC; cin>>TC;

    while (TC--) {
        cin>>n>>k>>s;

        int ans = solve();

        cout<<ans<<"\n";
    }
}