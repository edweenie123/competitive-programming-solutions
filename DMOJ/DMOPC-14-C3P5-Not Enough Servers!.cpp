/*
~~~ DMOPC '14 Contest 3 P5 - Not Enough Servers! ~~~

Key Concepts: Bitmask DP

In this case the dp state is the subset of people what are currently dead
    - which can be represented using a bitmask

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20 + 1;
const int MAXM = 50 + 1;
const int MAXC = (1 << 20) + 1; // max # of configurations

int n, m;
int tc[MAXM]; // tc -> bitmask (01100010) 1 = kills person i, 0 = doesn't kill a person i 
int dp[MAXC];

// minCase(cfg) returns the min amt of cases to kill everyone who is still alive
int minCase(int cfg) { // cfc -> bitmask (1 = dead person, 0 = alive person)
    if (dp[cfg]!=-1) return dp[cfg];

    if (__builtin_popcount(cfg) == n) // check if everyone is dead
        return 0;

    int best = 1e9;
    int newCfg;
    for (int i=0;i<m;i++) { // try all test cases
        newCfg = cfg | tc[i]; // kill all the people tc[i] would kill using bitwise OR
        if (newCfg != cfg) // the newCfg is different -> tc[i] killed someone -> try it
            best = min(best, 1+ minCase(newCfg));
    }

    return dp[cfg] = best;
}

vector<int> bestTC;
void getBestTC(int cfg) { 

    int newCfg;
    for (int i=0;i<m;i++) {
        newCfg = cfg | tc[i];
        // check if using this TC will yield the optimal answer
        if (minCase(newCfg) + 1 == minCase(cfg)) { 
            bestTC.push_back(i+1);
            getBestTC(newCfg);
            break;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>n>>m;

    char sign;
    vector<int> perfectBois; bool isPerfect = true;
    for (int i=0;i<n;i++) {
        isPerfect = true;
        for (int j=0;j<m;j++) {
            cin>>sign;
            if (sign=='X') {
                tc[j] += (1<<i); // case j kills person i
                isPerfect = false;
            }
        }
        if (isPerfect) perfectBois.push_back(i);
    }

    int start = 0;

    // start with all the perfect bois dead cause they don't matter
    for (auto p : perfectBois) 
        start += (1<<p);

    memset(dp, -1, sizeof(dp));
    int ans = minCase(start);

    if (ans==0) { // special case if ans = 0
        cout<<"1\n1\n";
        return 0;
    }

    cout<<ans<<"\n";

    getBestTC(start);
    for (auto t : bestTC) { // print the best test cases
        cout<<t<<" ";
    } cout<<"\n";
    
}