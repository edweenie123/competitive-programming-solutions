/*
~~~ DMOPC '14 Exam Time P4 - Exam Delay ~~~

Key Concepts: Dijkstra

Pretty simple dijkstra implementation


*/

#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define F first
#define S second
typedef pair<float, int> fi;
const int INF = 1e8;
const int MAXV = 1e3+1;

int v, e, distUnit[MAXV]; 
float dist[MAXV];
vector<fi> graph[MAXV];

void dijkstra() {
    for (int i=0;i<MAXV;i++) dist[i] = INF;

    priority_queue<fi, vector<fi>, greater<fi>> pq;

    pq.push(fi(0, 1));
    dist[1] = 0;
    distUnit[1] = 0;

    while(!pq.empty()) {
        fi front = pq.top(); pq.pop();
        float time = front.F;
        int u = front.S;

        if (time>dist[u]) continue;
        for (auto adj : graph[u]) {
            float d = adj.F;
            int v = adj.S;
            if (dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                distUnit[v] = distUnit[u] + 1;
                pq.push(fi(dist[v], v));
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>v>>e;

    int m, n;
    float d, s;

    for (int i=0;i<e;i++) {
        cin>>m>>n>>d>>s;
        graph[n].push_back(fi(d/s*60, m));
        graph[m].push_back(fi(d/s*60, n));
    }

    dijkstra();

    cout<<distUnit[v]<<"\n";
    cout<<round(dist[v]/3)<<"\n";
}