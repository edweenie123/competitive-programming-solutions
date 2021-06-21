/*
~~~ Simon and Marcy ~~~

Key Concepts: 0-1 Knapsack

Exact same thing as 0-1 Knapsack
*/

#include <bits/stdc++.h>
using namespace std;

int c, m, cage[1005], req[1005], memo[1005][1005];

int numSatisfy(int ind, int time) {
    if (time==0||ind==c) return 0;

    if (memo[ind][time]!=-1) return memo[ind][time];

    if (time<req[ind]) return memo[ind][time] = numSatisfy(ind+1, time);
    
    int sing = cage[ind] + numSatisfy(ind+1, time-req[ind]);
    int notSing = numSatisfy(ind+1, time);

    return memo[ind][time] = max(sing, notSing);
}

int main() {
    // 0-1 knapsack basically
    cin>>c>>m;

    for (int i=0;i<c;i++) 
        cin>>cage[i]>>req[i];

    for (int i=0;i<1005;i++) for (int j=0;j<1005;j++) memo[i][j] = -1;
    cout<<numSatisfy(0, m);    
}