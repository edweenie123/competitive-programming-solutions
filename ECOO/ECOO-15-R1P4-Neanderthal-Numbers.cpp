/*
~~~ ECOO '15 R1 P4 - Neanderthal Numbers ~~~

Key Concepts: Dynamic Programming

DP[l][r] returns the number of unique words contained within word[l:r]

There are dp[k+1][r] unique words that can be made starting with word[l:k]

Simply interate through all valid word[l:k] and sum up the # of unique words starting with word[l:k]
    to find the number of unque words between l and r

*/


#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 5;

vector<string> bois = 
{
    "ook",
    "ookook",
    "oog",
    "ooga",
    "ug",
    "mook",
    "mookmook",
    "oogam",
    "oogum",
    "ugug"
};


int dp[MAXN][MAXN];
string word;


int numWays(int l, int r) {
    if (dp[l][r]!=-1)
        return dp[l][r];


    if (l>r) return 1; // entire word can be parsed
    

    int ans = 0;
    
    for (auto boi : bois) {
        if (r-l+1 >= boi.length()) { // check if boi can exist within the interval l..r
            
            string couldBeBoi = word.substr(l, boi.length());

            if (couldBeBoi == boi) {
                ans += numWays(l+boi.length(), r);
            }

        }
    }

    return dp[l][r] = ans;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int t = 10;

    while (t--) {
        cin>>word;

        for (int i=0;i<MAXN;i++) 
            for (int j=0;j<MAXN;j++)
                dp[i][j] = -1;

        int ans = numWays(0, word.length()-1);

        cout<<ans<<"\n";
    }
}