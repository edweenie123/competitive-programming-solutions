#include <bits/stdc++.h>
using namespace std;

int n, m, visited[10001];

int BFS() {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({n, 0});

    int red, blue;
    while(!q.empty()) {
        pair<int, int> v = q.front();
        int num = v.first;
        q.pop();

        red = 2*num;
        blue = num-1;

        if (red==m||blue==m) {
            cout<<v.second+1<<endl;
            break;
        }
        if (!visited[red]&&red<=10000) {
            q.push({red, v.second+1});
            visited[red] = 1;
        }
        if (blue>0&&!visited[blue]) {
            q.push({blue, v.second+1});
            visited[blue] = 1;
        }
    }
}
int main() {
    cin>>n>>m;
    BFS();
}