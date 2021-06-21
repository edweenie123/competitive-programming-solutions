/*
~~~ 1153D - Serval and Rooted Tree ~~~

Key Concepts: DP, DFS

Weird DP problem that made be confused and feel stupid

Insight 1:
If we want to maximize the value in node i
    its value is going to be a value in one of its leaves of subtree i

We don't know the leaves exact value will be, but we can know the order of the leaf:
    (ie we can know m where the optimal leaf is the m'th largest within the subtree i)

Let dp[i] l - m where l is the number of leaves in the subtree i
    (this basically returns the "distance" from the back / largest leaf)

Insight 2:
If the parent node uses the max operation:
    the child that gets passed to the parent is the child that has the smallest dp[c] value
        since if we put the largest values in the leaves of this child it will give the biggest value for node i
            this is pretty intuitive if you draw it

The min operation is a bit more tricky:
    we need to sum up all the dp[c] of all the children 
        the sum represents the total number of values that are larger than the node that gets put into node i

        This is really hard to explain in words -> just draw it to see for the intuition

*/



#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

/*
strat:

dp[i] returns m
    where m is the value is the m'th largest leaf in the subtree i
    if we want to maximize i

for max operation:

    find child with smallest
        l - dp[c] value
            l is leaves in subtree for child

    dp[i] is totL - (l - dp[c]) 

for min operation:

    totalBack = l - dp[c] + 1 for all c

    dp[i] = totL - totalBack + 1;


*/


int n;
vector<int> graph[MAXN];
int type[MAXN];
int dp[MAXN];

int k = 0; // number of leaves

int dfs(int u, int par) { // returns # of leaves in subtree

    if (graph[u].empty()) { // base case leaf
        k++;
        // dp[u] = 0;
        return 1;
    }

    int totL = 0; // stores total number of leaves

    int bestBack = 1e9;
    int totalBack = 0;

    for (auto v : graph[u]) {
        if (v==par) continue;

        int leaves = dfs(v, u);

        if (type[u]) 
           bestBack = min(bestBack, dp[v]);
        else 
            totalBack += dp[v] + 1;

        totL += leaves;
    }


    if (type[u]) dp[u] = bestBack;
    else dp[u] = totalBack - 1;

    return totL;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=1;i<=n;i++) cin>>type[i];

    int par;
    for (int i=2;i<=n;i++) {
        cin>>par;
        graph[par].push_back(i);
    }

    dfs(1, -1);

    // for (int i=1;i<=n;i++) {
    //     cout<<i<<" : "<<dp[i]<<"\n";
    // }

    int ans = k - dp[1];
    cout<<ans<<"\n";
}