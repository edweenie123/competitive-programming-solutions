/*
~~~ DMOPC '15 Contest 5 P5 - World Line Convergence ~~~

Key Concepts: Fenwick tree

Kinda similar to the classic problem of counting inversions in an array

However...
    Each index in the array (that the bit represents) correlates to the order a node is visited in

Therefore, if we want to find all nodes that were visited before u:
    we call query(order[u])

Now...
    through observation, we realize that the answer for node u is sum of all node i such that
        node i is in the subtree of node u 
                    AND
        node i is visited before node u

We can find the answer of each node using DFS
    This is because at the end of a DFS loop for node u, the entire subtree of u will have already been traversed

Thus we can use query(order[u]) to find the answer for node u after the dfs loop

BE CAREFUL, query(order[u]) will count the answers from other subtrees

Therefore, you have to take the difference before and after the dfs loop to get the answer
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e6 + 5; 
const ll MOD = 1e9 + 7;

int n;
vector<int> graph[MAXN]; // graph[u] = vector of all children of u
int order[MAXN]; // order[i] = order that node i was visited in
int bit[MAXN]; // bit[i] stores the answer for node x such that order[x] = i
int answers[MAXN]; // answer[i] stores the answer for node i (its divergence factor when it was visited)

int LSB(int k) {return k & -k;}

void update(int k, int val) {
    while (k<MAXN) {
        bit[k] = (bit[k] + val) % MOD;  
        k += LSB(k);
    }
}

// sums up the answers of all the nodes that were visited first before order k 
ll query(int k) {
    ll total = 0;

    while (k > 0) {
        total = (total + bit[k]) % MOD;
        k -= LSB(k);
    }

    return total;
}

// query(u) might count answers from other subtrees!!!!
void dfs(int u) {
    // doesn't contain answers from current subtree, but might contain answers from other subtrees
    ll before = query(order[u]); 

    for (auto v : graph[u]) 
        dfs(v);

    // after = before + answers from current subtree
    ll after = query(order[u]);
    // add one bc each POC starts with a divergence factor of 1
    ll ans = (after - before + 1 + MOD) % MOD; // might be negative so you gotta mod 
    answers[u] = ans;

    update(order[u], answers[u]);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); 
    cin>>n;

    int root = -1; int par;
    for (int i=1;i<=n;i++) {
        cin>>par;
        if (par==0) root = i;
        graph[par].push_back(i);
    }

    int o;
    for (int i=1;i<=n;i++) {
        cin>>o;
        order[o] = i;
    }

    dfs(root);

    for (int i=1;i<=n;i++) 
        cout<<answers[i]<<" ";
    cout<<"\n";
}