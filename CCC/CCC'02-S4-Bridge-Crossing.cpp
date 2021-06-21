/*
~~~ CCC '02 S4 - Bridge Crossing ~~~

Key Concepts: Dynamic Programming, Output Optimal Answer

Fairly simple DP problem, use a memoization to generate optimal answer
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int m, q, times[101], memo[101];
string names[101];

int minTime(int idx) {
    if (idx==q) return 0;
    if (memo[idx]!=-1) return memo[idx];

    int slowest = 0;
    int ans = INF;

    for (int i=idx;i<min(idx+m, q);i++) {
        slowest = max(slowest, times[i]);
        ans = min(ans, slowest + minTime(i+1));
    }

    return memo[idx] = ans;
}

void printPeople(int idx) {
    if (idx==q) return;

    int slowest = 0;

    for (int i=idx;i<min(idx+m, q);i++) {
        slowest = max(slowest, times[i]);
        if (slowest+minTime(i+1)==memo[idx]) {
            for (int j=idx;j<=i;j++) cout<<names[j]<<" ";
            cout<<"\n";
            printPeople(i+1);
            break;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>m>>q;

    for (int i=0;i<q;i++) {
        cin>>names[i]>>times[i];
    }

    for (int i=0;i<101;i++) memo[i] = -1;

    cout<<"Total Time: "<<minTime(0)<<"\n";
    printPeople(0);
}