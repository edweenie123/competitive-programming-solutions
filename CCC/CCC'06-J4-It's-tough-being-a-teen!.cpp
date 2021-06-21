/*
~~~ CCC '06 J4 - It's tough being a teen! ~~~

Key Concepts: Toposort

Simply use Kahn's Algorithm to toposort the tasks

Use a priority queue to break ties!

*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector<int> vi;
int in[8];
vi dag[8], ans;
void kahn() {
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i=1;i<=7;i++) if (in[i]==0) pq.push(i);

    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        ans.push_back(u);

        for (auto v : dag[u]) {
            in[v]--;
            if (in[v]==0) pq.push(v);
        }
    }

    if (ans.size()<7) cout<<"Cannot complete these tasks. Going to bed."<<endl;
    else for (auto a : ans) cout<<a<<" ";

}
int main() {
    dag[1] = vi({4,7});
    dag[2] = vi({1});
    dag[3] = vi({4,5});
    in[4] = 2; in[7] = 1; in[1] = 1; in[5] = 1;

    int x, y;
    while (true) {
        cin>>x>>y;
        if (x==0&&y==0) break;
        dag[x].pb(y);
        in[y]++;
    }

    kahn();
}