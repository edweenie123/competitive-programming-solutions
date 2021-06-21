/*
~~~ COCI '06 Contest 1 #5 Bond ~~~

Key Concepts: Bitmask DP

dp[00111000] = best probility given that:
    all people marked as 1 HAVEN'T completed a mission yet
    all people marked as 0 HAVE completed a mission
    Missions have been completed in order (job 1 => job 2 => job 3...)

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20 + 5;
const int MAXCONFIG = (1 << 20) + 5; // 2^20 

int n;
double probability[MAXN][MAXN];
double dp[MAXCONFIG];

double maxProb(int bois, int idx) {
    if (dp[bois]!=-1) return dp[bois];
    if (idx > n) return 1;

    int copy = bois;
    double bestProb = 0;
    while (true) {
        int lastSet = log2(copy & -copy) + 1; // index of RSB
        
        copy -= 1 << (lastSet - 1);
        int newBois = bois - (1 << (lastSet - 1));
        double prob = probability[lastSet][idx];
        bestProb = max(bestProb, prob * maxProb(newBois , idx+1));

        if (copy == 0) break;
    }

    return dp[bois] = bestProb;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>probability[i][j]; 
            probability[i][j] /= 100.0;
        }
    }

    for (int i=0;i<MAXCONFIG;i++) 
        dp[i] = -1;
        
    
    int config = (1 << n) - 1; // start with all people available

    double ans = maxProb(config, 1) * 100.0;

    cout<<fixed<<setprecision(6);
    cout<<ans<<"\n";
}