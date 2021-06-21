// Key Concepts: BFS

#include <bits/stdc++.h>
using namespace std;

int n, h, temp, visited[1501][1501];
vector<vector<int>> field;

vector<pair<int, int>> pos(pair<int, int> cord) {
    array<pair<int, int>, 4> positions = {{{cord.first-1, cord.second}, 
                                        {cord.first+1, cord.second}, 
                                        {cord.first, cord.second-1}, 
                                        {cord.first, cord.second+1}}};
    vector<pair<int ,int>> posFilter;
    for (auto i : positions) {
        if (i.first>=0&&i.first<=n-1&&i.second>=0&&i.second<=n-1) {
            posFilter.push_back(i);
        }
    }
    return posFilter;
}


bool BFS() {
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({0,0});
    pair<int, int> ans = {n-1, n-1};
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();

        if (v == ans) {
            return true;
        }

        int alt = field[v.first][v.second];

        for (auto adj : pos(v)) {
            if (abs(field[adj.first][adj.second]-alt)<=h&&!visited[adj.first][adj.second]) {
                q.push(adj);
                visited[adj.first][adj.second] = 1;
            }
        }
    }
    return false;
    
}

int main() {
    cin>>n>>h;
    vector<int> row;
    for (int i=0;i<n;i++) {
        row.clear();
        for (int j=0;j<n;j++) {
            cin>>temp;
            row.push_back(temp);
        }
        field.push_back(row);
    }
    BFS() ? cout<<"yes" : cout<<"no";
}