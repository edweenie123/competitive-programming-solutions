/*
~~~ DMOPC '19 Contest 7 P3 - Tree Pruning ~~~

Key Concepts: Graph Theory, Don't over think

The solution is actually quite simple, but its ez to over think and try a yucky dp approach


1. We remove all nodes with weight more than 2K (they can't be in solution anyways)
2. if there are any nodes with weight in the range [k, 2k], we can use them as the answer
3. if not we go through all connected components to see if they can have a total weight of more than k
    - since a weight less than k + another weight less than k < 2k, we will never overshoot 
        - therefore it doesn't matter what order we traverse the connected components in


*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 5;
int n; ll k; ll weight[MAXN];

vector<int> graph[MAXN]; bool vis[MAXN];
bool good[MAXN];

void printAnswer(vector<int> ans) {
    cout<<ans.size()<<"\n";
    for (auto u : ans) 
        cout<<u<<" ";
    cout<<"\n";

    exit(0);
}


void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;

    ll totalWeight = 0;
    vector<int> nodes; 
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        totalWeight += weight[u];
        nodes.push_back(u);

        if (totalWeight>=k)
            printAnswer(nodes);

        for (auto v : graph[u]) {
            if (!vis[v] && good[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>n>>k;

    for (int i=1;i<=n;i++) {
        cin>>weight[i];

        // only keep nodes less than k
        if (weight[i] < k) good[i] = true;
    
        else if (weight[i] <= 2*k) {
            // valid subtree (just one node)
            cout<<"1\n"<<i<<"\n"; 
            return 0;
        }
        
    }

    int u, v;
    for (int i=0;i<n-1;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1;i<=n;i++) 
        if (!vis[i]&&good[i]) bfs(i);
    
    cout<<"-1\n"; // answer not found

}