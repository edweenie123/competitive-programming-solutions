/*
~~~ CCC '05 S4 - Pyramid Message Scheme ~~~

Key Concepts: Graph Theory

Old Strat Time: # of edges * 20
New Strat Time: Depth of tree * 20

Use DFS to find depth (old strat time is already give -> n*10)

*/

#include <bits/stdc++.h>
using namespace std;

map<string, int> nameToInd;
vector<int> graph[101];

int getDepth(int u, int par) {
    int depth = 0;
    for (auto v : graph[u]) {
        if (v==par) continue;
        depth = max(depth, 1 + getDepth(v, u));
    }
    return depth;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int TC, n, ind, last;
    
    cin>>TC;
    while (TC--) {
        nameToInd.clear();
        for (int i=0;i<101;i++) graph[i].clear();

        vector<string> order;
        string temp;

        cin>>n;
        for (int i=0;i<n;i++) {
            cin>>temp;
            order.push_back(temp);
        }
        nameToInd[order.back()] = 0;
        
        ind = 0;
        last = 0;
        for (auto recp : order) {
            if (nameToInd.find(recp)==nameToInd.end()) {
                nameToInd[recp] = ++ind;
            } 
            graph[last].push_back(nameToInd[recp]);
            last = nameToInd[recp];
        }

        int oldStrat = n * 10;        
        int newStrat = getDepth(0, 0) * 20;

        cout<<oldStrat - newStrat<<"\n";
    }
}