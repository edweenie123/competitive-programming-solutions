/*
~~~ AtCoder Stones ~~~

Key Concepts: DP

Very simple dp

willWin returns true if you can win if you go first with i # of stones

if there exists a move that makes it so willWin is false for your opponent, then your willWin is true

Time Complexity: O(N * K)
*/


#include<bits/stdc++.h>
using namespace std;

const int MAXK = 1e5 + 5;;

int n, k;
vector<int> choices;
int dp[MAXK];

bool willWin(int left) {
    if (left == 0) return false;
    if (dp[left] != -1) return dp[left];

    int canWin = false;

    for (auto c : choices) {
        if (left-c < 0) continue;
        if (!willWin(left-c)) {
            canWin = true;
            break;
        }
    }

    return dp[left] = canWin;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    int tmp;
    for (int i=0;i<n;i++) 
        cin>>tmp, choices.push_back(tmp);

    memset(dp, -1, sizeof(dp));

    cout<<(willWin(k) ? "First" : "Second")<<"\n";
}