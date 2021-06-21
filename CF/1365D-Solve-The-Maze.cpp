/*
~~~ 1365D - Solve The Maze ~~~

Key Concepts: Greedy, BFS

This is a yucky problem, you just have to make one yucky insight and it becomes easy

I wasn't too sure if this was the correct sol during the contest
    cause i didn't have enough time to prove it, but it worked thankfully

Insight 1:
Placing a wall on all the adjacent points to the bad guys is always optimal
    -> you kinda put a bubble of walls around all the bad guys

Obviously all the bad guys will be unable to get to the end if you do this
    -> unless they are adjacent to or exactly on the ending point

The only reason why its possible that this strat doesn't work is if:
    the bubble of walls around the bad guy stops a good guy from reaching the end

However in this case, if you leave the path open for the good guy
    the bad guy can take the same path to the end!!!
        -> therefore, the path must be closed (leaving both the good and bad guys out)

This means that all you have to do is place a bubble around all the bad guys
    and perform a bfs from the ending point to check if all the good guys can access the end
        (and that no bad guys can)

*/

#include<bits/stdc++.h>
using namespace std;


typedef pair<int, int> ii;
int n, m;
// vector<int> arr;
char grid[51][51];
int vis[51][51];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int totalG = 0;
int totalB = 0;

bool bfs() {
    queue<ii> q;

    q.push({n, m});
    for (int i=0;i<51;i++)
        for (int j=0;j<51;j++)
            vis[i][j] = 0;

    vis[n][m] = true;
    int badBoi = 0;
    int goodBoi = 0;

    while (!q.empty()) {
        ii u = q.front(); q.pop();
        if (grid[u.first][u.second] == '#') break;

        if (grid[u.first][u.second] == 'B')
            badBoi++;
        
        if (grid[u.first][u.second] == 'G')
            goodBoi++;
         
        for (int i=0;i<4;i++) {
            int newY = u.first + dy[i];
            int newX = u.second + dx[i];

            if (newY == 0 || newY > n) continue;
            if (newX ==0 || newX > m) continue;

            if (vis[newY][newX]) continue;

            if (grid[newY][newX] == '#') continue;

            q.push({newY, newX});
            vis[newY][newX] = true;
        }
    }

    if (goodBoi == totalG && badBoi == 0)
        return true;
    return false;
}


int main() {
    int TC; cin>>TC;

    while (TC--) {
        cin>>n>>m;


        totalG = 0;
        totalB = 0;

        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                cin>>grid[i][j];

                if (grid[i][j] == 'G')
                    totalG++;
                if (grid[i][j] == 'B')
                    totalB++;
            }
        }
        // cout<<"hello\n";


        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {

                if (grid[i][j] == 'B') {
                    
                    // cout<<"start "<<i<<" "<<j<<"\n";
                    for (int k=0;k<4;k++) {

                        int newI = i + dy[k];
                        int newJ = j + dx[k];
                        
                        // cout<<"yes "<<newI<<" "<<newJ<<"\n";

                        if (newI == 0 || newI > n) continue;
                        if (newJ == 0 || newJ > m) continue;

                        if (grid[newI][newJ] == 'B' || grid[newI][newJ] == 'G') continue;

                        grid[newI][newJ] = '#';
                    }
                }
            }
        }

        // cout<<"wtf\n";

        if (bfs()) {
            cout<<"Yes\n";
        } else {
            cout<<"No\n";
        }
    }
        
}
