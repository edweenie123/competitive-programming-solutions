/*
~~~ UVa 11953 - Battleships ~~~

Key Concepts: Flood Fill (BFS/DFS)

Use BFS to find entire ship and mark all ship cords as visited
*/
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int,int> ii;

int TC, n, bsCnt;

vector<string> grid;
bool visited[105][105];

bool BFS(ii src) {
    char srcElem = grid[src.f][src.s];
    if (srcElem!='x'&&srcElem!='@') return false;
    visited[src.f][src.s] = true;

    // up, right, down left
    int dr[] = {-1, 0, 1, 0}; 
    int dc[] = {0, 1, 0, -1};

    int dir = -1;
    for (int i=0;i<4;i++) {
        ii l = ii(src.f+dr[i],src.s+dc[i]);

        if (l.f<0||l.f>=n||l.s<0||l.s>=n) continue;
        char elem = grid[src.f+dr[i]][src.s+dc[i]];
        if (elem=='x'||elem=='@') {
            dir = i;
            break;
        }
    }

    if (dir==-1) {
        if (srcElem=='x') return true;
        else return false;
    }

    bool isAlive = false;

    queue<ii> q;
    q.push(src);

    while (!q.empty()) {
        ii u = q.front(); q.pop();
        // printf("looking at (%d, %d)\n", u.f, u.s);

        if (grid[u.f][u.s]=='x') isAlive = true;
        visited[u.f][u.s] = true;

        ii v = ii(u.f+dr[dir],u.s+dc[dir]);

        if (v.f<0||v.f>=n||v.s<0||v.s>=n) break;
        if (grid[v.f][v.s]!='x'&&grid[v.f][v.s]!='@') break;

        if (!visited[v.f][v.s]) q.push(v);
    }

    if (isAlive) {return true;}
    else return false;
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin>>TC;
    for (int t=1;t<=TC;t++) {
        grid.clear();
        for (int i=0;i<105;i++) for (int j=0;j<105;j++) visited[i][j] = false;
        bsCnt = 0;

        cin>>n;

        string line;
        for (int i=0;i<n;i++) {
            cin>>line;
            grid.push_back(line);
        }

        for (int i=0;i<n;i++) 
            for (int j=0;j<n;j++) 
                if (!visited[i][j] && BFS(ii(i, j))) bsCnt++;

        printf("Case %d: %d\n", t, bsCnt);   
    }   
}