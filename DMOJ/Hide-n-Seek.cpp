/*
~~~ Hide n Seek ~~~ 

Key Concepts: BFS, Brute Force 

Similar to TSP

Try visiting all targets in all possible orders
*/

#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
typedef pair<int,int> ii;
const int INF = 1e8;

int n, m, t;
ii start;
vector<ii> tar; 
char grid[21][21];
map<ii, array<array<int, 21>, 21>> dist;

int rD[] = {-1, 1, 0, 0};
int cD[] = { 0, 0,-1, 1};

void bfs(ii src) {
    queue<ii> q;
    dist[src][src.f][src.s] = 0;
    q.push(src);

    while(!q.empty()) {
        ii v = q.front(); q.pop();
        int r = v.first, c = v.second;

        for (int i=0;i<4;i++) {
            int newR = r + rD[i], newC = c + cD[i];
            if (dist[src][newR][newC]!=0) continue;
            if (ii(newR, newC)==src) continue;
            if (grid[newR][newC]=='X') continue;
            if (newR<0||newR>=n) continue;
            if (newC<0||newC>=m) continue;

            dist[src][newR][newC] = dist[src][r][c] + 1;
            q.push(ii(newR, newC));
        }
    }
}

int findMinDist() {
    int ans = INF, d;
    do {
        d = dist[start][tar[0].f][tar[0].s];
        for (int i=1;i<t;i++) {
            d += dist[tar[i-1]][tar[i].f][tar[i].s];
        }
        ans = min(ans, d);
    } while (next_permutation(tar.begin(), tar.end()));
    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>t;
    char elem;
    
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>elem;
            if (elem=='G') {
                start = ii(i, j);
            }
            if (elem=='H') {
                tar.push_back(ii(i, j));
            }
            grid[i][j] = elem;
        }
    }

    bfs(start);
    for (auto t : tar) bfs(t);

    cout<<findMinDist()<<"\n";
}