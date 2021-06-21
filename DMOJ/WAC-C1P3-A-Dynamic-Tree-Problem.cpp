/*
~~~ Wesley's Anger Contest 1 P3 - A Dynamic Tree Problem ~~~

Key Concepts: High iq, BFS/DFS


*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
int n, m, k;

int parent[100005];
vector<int> tree[100005];
vector<ii> leafDist; // (dist, node)
vector<ii> leafApples; // (apples, node)

int numLeafs, visited[100005];

void findLeafDepth() { // BFS to find leaf depths
    queue<ii> q;
    q.push(ii(0, 1));

    while(!q.empty()) {
        ii front = q.front(); q.pop();
        int d = front.first, u = front.second;
        if (tree[u].size()==0) leafDist.push_back(ii(d, u));
        for (auto adj : tree[u]) 
            q.push(ii(d+1, adj));
        
    }
    numLeafs = leafDist.size();
}

void findLeafApples(int u) { // find the # apples you can get if you climb to leaf u
    int appleCnt = 0, leaf = u;
    while (1) {
        if (visited[u]==-1) {
            appleCnt++;
            visited[u]=1;
        }
        if (parent[u]==0) break;
        u = parent[u];
    }

    leafApples.push_back(ii(appleCnt, leaf));
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m>>k;

    int u, p = 2;
    for (int i=1;i<=n-1;i++) {
        cin>>u;
        tree[u].push_back(p);
        parent[p] = u;
        p++;
    }
    parent[1] = 0;

    findLeafDepth();
    sort(leafDist.begin(), leafDist.end(), greater<ii>());
    
    // for (auto l : leafDist) {
    //     printf("node %d has %d dist\n", l.second, l.first);
    // }

    for (int i=0;i<100005;i++) visited[i] = -1;

    for (int i=0;i<k;i++) {
        if (i<numLeafs) {
            findLeafApples(leafDist[i].second);
        } else {
            leafApples.push_back(ii(0, 0));
        }
    }

    sort(leafApples.begin(), leafApples.end(), greater<ii>());

    // for (auto l : leafApples) {
    //     printf("node %d yields %d apples\n", l.second, l.first);
    // }

    for (int i=0;i<m;i++) {
        cout<<leafApples[i%k].first;
        if (i<m-1) cout<<" ";
    } cout<<"\n";
}