/*
~~~ ECOO '13 R3 P4 - Tour de Force ~~~

Key Concepts: DP

Pretty good dp problem... 

DP(i, j) represents the max score you can get starting from the ith card with a card streak (# of cards answered correctly before hand) of j.

Failing card c will give you the score: 
    card[c][0] - 1 + DP(c+1, 0) 
    
Answering card c will give you the score: 
    card[c][0] + card[c][1] + DP(c+1, j+1) 
    
Thus, the optimal score is the max between these two options
*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int n;

int dp[MAXN][10];
int card[MAXN][2];

int maxScore(int c, int cStreak) {
    if (dp[c][cStreak]!=-1) return dp[c][cStreak];

    if (c==n-1) {
        if (cStreak!=4) 
            return card[c][0] + card[c][1];
        else
            return card[c][0] - 1;
    }

    int fail=0, sucess=0;
    
    if (cStreak!=4) {
        sucess = card[c][0] + card[c][1] + maxScore(c+1, cStreak+1);
    }

    fail = card[c][0] - 1 + maxScore(c+1, 0);
    

    return dp[c][cStreak] = max(fail, sucess);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int t = 10;

    while (t--) {
        cin>>n;

        for (int i=0;i<n;i++) {
            cin>>card[i][0]>>card[i][1];
        }

        for (int i=0;i<MAXN;i++) 
            for (int j=0;j<10;j++) 
                dp[i][j] = -1;
            
        
        int ans = maxScore(0, 0);

        cout<<ans<<"\n";
    }
}