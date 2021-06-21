/*
~~~ UVa 00468 - Wetlands of Florida ~~~

Key Concepts: Flood-Fill BFS

Simple Flood-Fill to find the area of water
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int TC;
vector<string> graph;
int grid[100][100];
int rows, cols;
int BFS(int r, int c) {
    for (int i=0;i<100;i++) for (int j=0;j<100;j++) grid[i][j]=-1;
    
    int dr[] = {-1, -1, 0, 1, 1,  1,  0, -1};
    int dc[] = { 0,  1, 1, 1, 0, -1, -1, -1};
    
    queue<ii> q;
    q.push(ii(r,c));
    grid[r][c] = 1;

    int water = 1;

    while (!q.empty()) {
        ii front = q.front(); q.pop();

        int row = front.first, col = front.second;

        for (int i=0;i<8;i++) {
            int nrow = row+dr[i], ncol = col+dc[i];

            if (nrow>=rows||nrow<0||ncol>=cols||ncol<0||graph[nrow][ncol]!='W') continue;

            if (grid[nrow][ncol]==-1) {
                water++;
                grid[row+dr[i]][col+dc[i]] = 1;
                q.push(ii(row+dr[i],col+dc[i]));
            }
        }
    }
    return water;
}

int main () {
    // freopen("input.txt", "r", stdin);
    cin>>TC;
    string line;

    getline(cin, line);
    getline(cin, line);

    while (TC--) {

        graph.clear();

        int r, c;
        while (1) {
            getline(cin, line);
            if (line.empty()) break;
            if (line[0]!='L'&&line[0]!='W') {
                istringstream ss(line);
                ss>>r>>c;
                cout<<BFS(r-1, c-1)<<"\n";
            } else {
                graph.push_back(line);
                rows=graph.size();
                cols=graph[0].length();
            }
        }
        if (TC) cout<<"\n";

    }
}