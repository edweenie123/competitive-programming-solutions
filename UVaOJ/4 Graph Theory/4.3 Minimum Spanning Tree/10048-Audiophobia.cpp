/*
~~~ UVa 10048 - Audiophobia ~~~

Key Concepts: Minimax

Generate a MST of the graph, then use BFS to find the max edge weight between i and j

For some reason, the judge gives a runtime error
*/

#include <bits/stdc++.h>

using namespace std;


typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int maxC = 105;

int c, s, q, par[maxC], ranks[maxC];
iii edges[1005];

vector<ii> MST[maxC];

int root (int i) {
    while (i!=par[i]) i = par[i];
    return i;
}

int merge(int a, int b, int w) {
    // add edge to MST
    MST[a].push_back(ii(w, b));
    MST[b].push_back(ii(w, a)); 

    int rootA = root(a), rootB = root(b);

    if (ranks[rootA]>ranks[rootB]) {
        par[rootB] = rootA;
        ranks[rootA] += ranks[rootB];
    } else {
        par[rootA] = rootB;
        ranks[rootB] += ranks[rootA];
    }
}

void initialize() {
    for (int i=0;i<maxC;i++) {
        par[i] = i;
        ranks[i] = 1;
    }
}

void kruskals() {
    initialize();
    sort(edges, edges+s);

    for (int i=0;i<s;i++) {
        iii e = edges[i];
        int u = e.second.first, v = e.second.second;

        if (root(u)!=root(v))
            merge(u, v, e.first);
    }
}

bool visited[maxC];

int bfs(int src, int dest) {
    for (int i=0;i<maxC;i++) visited[i] = false;
    visited[src] = true;

    queue<ii> q; // (maxEdge, u)
    q.push(ii(0, src));

    int maxEdge = -1;
    while (!q.empty()) {
        ii f = q.front(); q.pop();

        if (f.second==dest) {
            maxEdge = f.first;
            break;
        }
        for (auto v : MST[f.second]) {
            if (!visited[v.second]) {
                visited[v.second] = true;
                q.push(ii(max(f.first, v.first), v.second));
            }
        }
    }

    return maxEdge;

}

int main () {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int TC = 0;
    while (cin>>c>>s>>q) {
        if (c==0&&s==0&&q==0) break;
        for (int i=0;i<maxC;i++) MST[i].clear();

        int c1, c2, d;
        for (int i=0;i<s;i++) {
            cin>>c1>>c2>>d;
            edges[i] = iii(d, ii(c1,c2));
        }

        kruskals();

        cout<<"Case #"<<++TC<<endl;
        for (int i=0;i<q;i++) {
            cin>>c1>>c2;

            int maxEdge = bfs(c1, c2);
            
            cout<<(maxEdge==-1 ? "no path" : to_string(maxEdge))<<endl;
        }

        cout<<endl;
    }
}