/*
~~~ 1380C - Create the Teams ~~~

Key Concepts: DP

Once you sort the elements in the array
    -> its easy to see the greedy dp solution

Pretty good problem tho

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 5;

int n, x;
vector<int> skill;

int dp[100005];

int maxTeam(int idx) {
    if (idx==n) return 0;

    if (dp[idx] != -1) return dp[idx];

    int take = 0;

    // take boi
    int val = skill[idx];
    int lastIdx = idx + ((x / val) + (x%val!=0)) - 1;
 
    if (lastIdx < n) take = 1 + maxTeam(lastIdx+1);

    // skip boi
    int skip = maxTeam(idx+1);

    return dp[idx] = max(take, skip);
}

int solve() {
    cin>>n>>x;

    skill.clear();

    int tmp;
    for (int i=0;i<n;i++) {
        cin>>tmp;
        skill.push_back(tmp);
    }

    sort(skill.begin(), skill.end());

    for (int i=0;i<=n;i++) dp[i] = -1;

    int ans = maxTeam(0);

    return ans;
}

int main() {
    int TC; cin>>TC;

    while (TC--) {
        int ans = solve();
        cout<<ans<<"\n";
    }
}