/*
~~~ 242C - King's Path ~~~

Key Concepts: BFS, Map

The important part of the question is that the sum of all the segments <= 1e5

Therefore, we can just run a simple bfs across the entire board

Since th board is so large, we either have to coordinate compress or use a map to represent the board to not MLE

*/


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int n;
map<int, set<int>> board; 
map<int, set<ii>> dist;

int r1, c1, r2, c2;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int bfs(ii src, ii tar) {
    queue<ii> q;
    q.push(src);
    dist[src.first].insert({src.second, 0});

    while (!q.empty()) {
        ii u = q.front(); q.pop(); 

        int curDist = (*dist[u.first].lower_bound({u.second, 0})).second;


        if (u == tar) {
            return curDist;
        }

        for (int i=0;i<8;i++) {
            int newX = u.first + dx[i];
            int newY = u.second + dy[i];

            if (board[newX].count(newY)) {
                auto iter = dist[newX].lower_bound({newY, 0});

                int val = (*iter).first;

                if (val!=newY) {
                    q.push(ii{newX, newY});
                    dist[newX].insert({newY, curDist + 1});
                }
            }
        }
    }

    return -1;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>r1>>c1>>r2>>c2;

    cin>>n;
    int r, a, b;
    for (int i=0;i<n;i++) {
        cin>>r>>a>>b;
        for (int j=a;j<=b;j++) {
            board[r].insert(j);
        }
    }

    int ans = bfs({r1, c1}, {r2, c2});
    cout<<ans<<"\n";
}