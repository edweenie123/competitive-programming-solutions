/*
~~~ DMOPC '14 C1P5 - Surprise Teleport ~~~

Key Concepts: BFS

Use BFS to find shortest path to target (d1)
Do BFS again, except to shortest path to portals (d2)

Time saved = d1 - d2
*/
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef pair<int, int> pii;

int r, c, t;
pii src, tar;

set<pii> allTar;

int dist[1000][1000];
string board[1000];

vector<pii> positions(pii aPos) {
    vector<pii> all = {
        make_pair(aPos.f+1, aPos.s),
        make_pair(aPos.f-1, aPos.s),
        make_pair(aPos.f, aPos.s+1),
        make_pair(aPos.f, aPos.s-1), 
    };

    vector<pii> possible;
    for (auto p : all) {
        if (p.f>=0&&p.f<r&&p.s>=0&&p.s<=c) {
            if (board[p.f][p.s]!='X') {
                possible.push_back(p);
            }
        }
    }
    return possible;
}

int BFS() {
    memset(dist, -1, sizeof(dist));
    queue<pii> q;
    q.push(src);

    dist[src.f][src.s] = 0;
    while(!q.empty()) {
        pii pos = q.front();
        q.pop();

        if (allTar.find(pos)!=allTar.end()) {
            return dist[pos.f][pos.s]+1;
        }

        for (auto p : positions(pos)) {
            if (dist[p.f][p.s]==-1) {
                dist[p.f][p.s] = dist[pos.f][pos.s]+1;
                q.push(p);
            } else {
                dist[p.f][p.s] = max(dist[p.f][p.s], dist[pos.f][pos.s]+1);
            }
        } 
    }
}

int main() {
    cin>>r>>c;
    cin>>src.f>>src.s;
    cin>>tar.f>>tar.s;
    allTar.insert(tar);

    for (int i=0;i<r;i++) {
        cin>>board[i];
    }
    int d1 = BFS();
    cin>>t;
    for (int i=0;i<t;i++) {
        cin>>tar.f>>tar.s;
        allTar.insert(tar);
    }
    int d2 = BFS();

    cout<<d1-d2;
}