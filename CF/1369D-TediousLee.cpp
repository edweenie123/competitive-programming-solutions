/*
~~~ 1369D - TediousLee ~~

Key Concepts: DP 

i couldn't solve this in contest :(((((
    I knew it was dp tho, i just couldn't figure out the recurrence cause im dumb

Insight 1: 
You have to notice that a RDB of level n consists of a 
    RBD of level n-1 and 2 RBD's of level n-2 connected to a single node

Insight 2:
The DP recurrence arises naturally from insight 1

DP[n] = # of claws in a RBD of level n

It should be intuitive that DP[n] = DP[n-1] + 2 * DP[n-2]

HOWEVER, you have realize that if n is divisble by 3
    You can make one extra claw!

Draw the bois out to see why:
    -> if the all the children don't use the top node
            you can make an extra claw at the top


*Top-Down DP will stackoverflow for this boi fsr

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const ll MOD = 1e9 + 7;

ll dp[2000005];

int main() {
    int TC; cin>>TC;

    dp[1] = 0;
    dp[2] = 0;

    for (int i=3;i<=2000000;i++) {
        dp[i] = (dp[i-1] + 2*dp[i-2]) % MOD;
        if (i % 3 == 0) dp[i] = (dp[i] + 1) % MOD;
    }

    while (TC--) {
        int n;
        cin>>n;

        cout<<(dp[n]*4) % MOD<<"\n";
    }
}