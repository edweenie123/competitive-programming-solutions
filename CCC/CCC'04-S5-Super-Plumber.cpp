#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef pair<int,int> ii;
typedef pair<ii, bool> iib;
typedef pair<int, iib> iiib;

const int INF = 1e8;
int n, m, dist[101][101];
int grid[101][101];

void dijkstra(ii src) {
    for (int i=0;i<101;i++) for (int j=0;j<101;j++) dist[i][j] = INF;
    priority_queue<iiib> pq;
    dist[src.f][src.s] = grid[src.f][src.s];

    pq.push(iiib(dist[src.first][src.second], iib(ii(src.first, src.second), false)));

    while (!pq.empty()) {
        iiib front = pq.top(); pq.pop();

        int d = front.f, r=front.s.f.f, c=front.s.f.s;
        bool
    }
}

int main() {
    cin>>m>>n;

    string line;
    for (int i=1;i<=m;i++) {
        cin>>line;
        for (int j=1;j<=n;j++) {
            char c = line[j-1];
            if (c=='.') grid[i][j] = 0;
            if (c=='*') grid[i][j] = INF;
            else grid[i][j] = (int)c;
        }
    }
}