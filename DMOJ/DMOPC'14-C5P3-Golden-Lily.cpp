/*
~~~ DMOPC '14 Contest 5 P3 - Golden Lily ~~~

Key Concepts: Dijkstra

Simple Dijkstra implementation

Can also use DP
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
const int INF = 1e8;
int l, d, den[1001][1001], dist[1001][1001], rTar, cTar;
int rDir[] = {1, 0, 0};
int cDir[] = {0, -1, 1};
int dijkstra() {

    for (int i=0;i<1001;i++) for (int j=0;j<1001;j++) dist[i][j] = INF;
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push(iii(den[0][0],ii(0, 0)));
    dist[0][0] = den[0][0];

    while (!pq.empty()) {
        iii front = pq.top(); pq.pop(); 
        int du = front.first, r = front.second.first, c = front.second.second;
        // printf("looking at (%d, %d)\n", r, c);
        if (du>dist[r][c]) continue;

        for (int i=0;i<3;i++) {
            int newR = r+rDir[i];
            int newC = c+cDir[i];
            if (newR>=d||newR<0) continue;
            if (newC>=l||newC<0) continue;
            if (dist[r][c]+den[newR][newC]<dist[newR][newC]) {
                dist[newR][newC] = dist[r][c] + den[newR][newC];
                pq.push(iii(dist[newR][newC], ii(newR, newC)));
            }
        }
    }

    return dist[rTar][cTar];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>l>>d;

    for (int i=0;i<d;i++) 
        for (int j=0;j<l;j++) 
            cin>>den[i][j];

    cin>>cTar>>rTar;

    cout<<dijkstra()<<"\n";
}