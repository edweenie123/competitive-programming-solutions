/*
~~~ DMOPC '14 Exam Time P5 - Happy Teachers ~~~

Key Concepts: DP

Fairly simple DP problem 
    - Realize that the order in which the teachers dance doesn't matter
    - Very similar to 1/0 Knapsack
    
*/

#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef pair<int,int> ii;

const int MAXS = 1e3 + 5;
const int MAXN = 55;

int n;

struct teacher {
    int hap, exus, prep;
};

vector<teacher> teachers;
pair<int, int> dp[MAXS][MAXN];

ii maxHappiness(int timeLeft, int idx) { // returns {max happiness, min time}
    
    if (dp[timeLeft][idx] != ii{-1, -1})
        return dp[timeLeft][idx];

    if (idx >= n) return {0, 0};
    
    teacher t = teachers[idx];

    int maxSeconds = min(timeLeft / t.prep, t.hap / t.exus + (t.hap%t.exus!=0));

    int maxHap = -1, minTime = 1e9;
    int hapGain = 0, addHap = t.hap;
    
    // printf("(%d, %d, %d)\n", timeLeft, idx, maxSeconds);
    
    for (int i=0;i<=maxSeconds;i++) {

        ii nextHappiness = maxHappiness(timeLeft - i * t.prep, idx+1);
        int potential = nextHappiness.f + hapGain;

        if (potential > maxHap) {
            maxHap = potential;
            minTime = nextHappiness.s + i;
        } else if (potential == maxHap) {
            minTime = min(minTime, nextHappiness.s + i);
        }
        
        hapGain += addHap;
        addHap -= t.exus;
    }

    return dp[timeLeft][idx] = ii{maxHap, minTime};
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    cin>>n;

    int h, e, p;

    for (int i=0;i<n;i++) {
        cin>>h>>e>>p;
        teachers.push_back(teacher{h, e, p});
    }

    int s; cin>>s;

    for (int i=0;i<MAXS;i++)
        for (int j=0;j<MAXN;j++)
            dp[i][j] = ii{-1, -1};

    ii ans = maxHappiness(s, 0);

    cout<<ans.f<<"\n";
    cout<<ans.s<<"\n";
}