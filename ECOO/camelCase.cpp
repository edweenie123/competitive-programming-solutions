#include<bits/stdc++.h>
using namespace std;

vector<string> dict[26];

string word;

int dp[2005];

int minCap(int k) {
    if (dp[k]!=-1)
        return dp[k];


    if (k>=word.length()) return 0;
    
    int let = word[k] - 'a';

    int best = 1e9;


    for (auto w : dict[let]) {
        if (word.length() - k >= w.length()) {
            string couldBeWord = word.substr(k, w.length());
            if (couldBeWord == w) {
                best = min(best, 1 + minCap(k+w.length()));
            }
        }
    }

    return dp[k] = best;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n;

    cin>>n;

    char firstLet;
    for (int i=0;i<n;i++) {
        cin>>word;
        firstLet = word[0];
        dict[firstLet - 'a'].push_back(word);
    }

    int t = 10;

    while(t--) {
        cin>>word;
        for (int i=0;i<2005;i++)
            dp[i] = -1;

        int ans = minCap(0) - 1;

        cout<<ans<<endl;
    }
}