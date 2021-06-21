/*
~~~ 137D - Palindromes ~~~

Key Concepts: DP, recursive backtrack

Very good problem imo, but the implementation is kinda ugly


Insight 1: 
The first insight you should make is the n^3 dp recurrence:

dp(i, j) returns the minimum number of operations needed 
    to turn s[0..i] with j palindromes created so far

Let change(str) denote the minimum number of operations to turn str into a palindrome

The recurrence is very simple, you just try all possible ending values end
    for a given i

    the cost for each ending is change(s[i..end]) + dp(end+1, j+1)

    We simply find the ending value that gives the lowest cost and return it

Insight 2:
The issue is now defining the change() function
    we can do this very simply in n^3 by precomputing the min operations for any given s[i..j]

The rest is pretty simple stuff 
    -> do recursive backtracking to separate the string 
    -> convert the substrings into palindromes

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e2 + 5; 

string s;
int k;

int change[MAXN][MAXN]; // min operations needed to turn substring i->j into palindrome

string convPalin(string str) { // converts str into palindrome in min number of moves
    string half = str.substr(0, str.length()/2);

    string ret = half;
    if (str.length()%2==1) ret += str[str.length()/2];

    reverse(half.begin(), half.end());
    ret += half;

    return ret;
}   

void calcChange() {
    for (int i=0;i<s.length();i++) {
        for (int j=i;j<s.length();j++) {
            int cnt = 0;

            for (int l=0;l<(j-i+1)/2;l++) {
                int cur = i + l;
                int mir = j - l;

                if (s[cur] != s[mir]) 
                    cnt++;
            }
            
            change[i][j] = cnt;
        }
    }
}

int dp[MAXN][MAXN];

int minCost(int idx, int pMade) {
    if (pMade > k) return 1e9;
    if (idx == s.length()) return 0;

    if (dp[idx][pMade] != -1) return dp[idx][pMade];    

    int bestCost = 1e9;

    for (int i=idx;i<s.length();i++) {
        int cost = change[idx][i] + minCost(i+1, pMade+1);
        bestCost = min(cost, bestCost);
    }

    return dp[idx][pMade] = bestCost;
}

vector<string> palins;

void recur(int idx, int pMade) {
    for (int i=idx;i<s.length();i++) {
        int cost = change[idx][i] + minCost(i+1, pMade+1);
        
        if (cost == minCost(idx, pMade)) {
            string str = s.substr(idx, i-idx+1);
            palins.push_back(convPalin(str));           
            recur(i+1, pMade+1);
            break;
        }

    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>s>>k;

    calcChange();

    memset(dp, -1, sizeof(dp));

    int ans = minCost(0, 0);
    recur(0, 0);

    cout<<ans<<"\n";
    cout<<palins[0];
    for (int i=1;i<palins.size();i++) {
        cout<<"+"<<palins[i];
    }
    cout<<"\n";

}