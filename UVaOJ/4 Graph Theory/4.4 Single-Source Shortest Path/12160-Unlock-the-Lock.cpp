/*
~~~ UVa 12160 - Unlock the Lock ~~~

Key Concepts: BFS

Vertices = Lock Numbers 
Link 2 vertices with an edge if you can transform one into another with a button

if the sum of a button and a vertex > 9999, only consider the last 4 digits
*/

#include <bits/stdc++.h>

using namespace std;

int l, u, r, dist[10000];
vector<int> button;

int BFS(int s, int d) {
    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        if (u==d) return dist[u];

        for (auto b : button) {
            int newCode = u+b;
            if (u+b>9999) newCode %= 10000; // only consider the last 4 digits
            if (dist[newCode]==-1) {
                dist[newCode] = dist[u] + 1;
                q.push(newCode);
            }
        }
    }

    return -1;
}   
int main() {
    // freopen("input.txt", "r", stdin);
    int caseNum = 0;
    while (cin>>l>>u>>r) {
        if (l+u+r==0) break;

        button.clear();
        int b;
        for (int i=0;i<r;i++) {
            cin>>b;
            button.push_back(b);
        }

        int ans = BFS(l, u);
        printf("Case %d: %s\n", ++caseNum, ans==-1 ? "Permanently Locked" : to_string(ans).c_str());
    }
}