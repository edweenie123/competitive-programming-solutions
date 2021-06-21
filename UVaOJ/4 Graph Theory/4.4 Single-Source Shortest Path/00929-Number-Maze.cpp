/*
~~~ UVa 929 - Number Maze ~~~

Key Concepts: Dijkstra's SSSP Algorithm

Use Dijkstra's algorithm to find the distance from (1, 1) to (n, m)
*/

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int,int> ii;
typedef pair<int, ii> iii;

const int INF = 1e8;

int TC, n, m, maze[1001][1001], dist[1001][1001];

int dijkstra() {
    for (int i=0;i<1001;i++) for (int j=0;j<1001;j++) dist[i][j] = INF;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    dist[1][1] = maze[1][1];
    pq.push(iii(dist[1][1], ii(1,1)));

    while (!pq.empty()) {
        iii front = pq.top(); pq.pop();

        int d = front.f, ur = front.s.f, uc = front.s.s;

        if (d>dist[ur][uc]) continue;

        for (int i=0;i<4;i++) {
            int vr = ur+dr[i], vc = uc+dc[i];
            if (vr<1||vr>n||vc<1||vc>m) continue;

            int dv = dist[ur][uc]+maze[vr][vc];
            if (dv<dist[vr][vc]) {
                dist[vr][vc] = dv;
                pq.push(iii(dv, ii(vr, vc)));
            } 
        }
    }

    return dist[n][m];
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin>>TC;
    while (TC--) {
        cin>>n>>m;
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>maze[i][j];

        int ans = dijkstra();

        cout<<ans<<endl;
    }
}