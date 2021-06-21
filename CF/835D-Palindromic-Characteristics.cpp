/*
~~~ 835D - Palindromic Characteristics ~~~

Key Concepts: DP

The hashing tag is a trap,
    it works, but you will MLE if you compute the hashes for all the substrings

The dp recurrence is kinda weird to check if a substring is a palindrome
    -> review this problem for this reason

Insight 1: 
If a string is a k-palindrome, it is also a k-1 palindrome, k-2 palindrome..etc
    -> this is makes sense if you think about it

Insight 2: 
If a string is a k-palindrome and k != 0, then the string is a palindrome itself
    and its left half is a palindrome and its right half is also a palindrome

We will compute the max k value for every substring using a pretty simple DP
    -> and the rest should be ez

also edge case when the length of the string is 2

*/



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define first f
#define second s

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 5e3 + 5;

int n;
string s;

int dp[MAXN][MAXN];

int maxPalindrome(int l, int r) {
    if (l==r) return 1;

    if (r-l==1) return (s[l] == s[r] ? 2 : 0); // gey edge case

    if (dp[l][r] != -1) return dp[l][r];

    if (s[l] != s[r] || maxPalindrome(l+1, r-1) == 0) // the ss is not palindrome
        return dp[l][r] = 0; 

    int mid = (l + r) / 2;

    int left = maxPalindrome(l, mid - ((r-l+1)%2==1));
    int right = maxPalindrome(mid+1, r);

    int minMax = min(left, right);

    return dp[l][r] = minMax + 1;
}

int mpFreq[MAXN]; // frequency of maxPalindrome
int ans[MAXN];

void solve() {
    cin>>s;
    n = s.length();
    s = ' ' + s;

    memset(dp, -1, sizeof(dp));

    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            int k = maxPalindrome(i, j);
            mpFreq[k]++;
        }
    }

    ll lastSum = 0;

    for (int i=n;i>=0;i--) {
        ll val = mpFreq[i] + lastSum;
        ans[i] = val;
        lastSum += mpFreq[i];
    }

    for (int i=1;i<=n;i++) 
        cout<<ans[i]<<" ";
    cout<<"\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();    
}