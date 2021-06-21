/*
~~~ UVa 10801 - Lift Hopping ~~~

Key Concepts: Dijkstra's SSSP Algorithm, High IQ

It is a bit difficult to convert the input into a graph so we can run Dijkstra on it

Keep 100*n vertices, 0-99 for the 1st elevator, 100-299 for the 2nd and so on

Put an edge between two vertices that are accessable by the same elevator 
    - weight = (u - v) * speed of elevator

Put an edge between two vertices if they are on the same floor (u%100=v%100)
    - weight = 60 (specified in the problem statement)

Once all the preprocessing is done, we simply run Dijkstra on it and return the minutmum over all vertices on the kth floor
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int INF = 1e7;

int n, k, speed[10];
vector<int> floorAcc[100]; // used to check if you can switch elevators at a given floor

vector<ii> graph[500];
vector<ii> startLevels; // stores which elevators you can start at
int dist[500];

int dijkstra() {
    for (int i=0;i<500;i++) dist[i] = INF;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (auto s : startLevels) {
        dist[s.second] = 0;
        pq.push(s);
    }

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();

        int d = front.first, u = front.second;

        if (d>dist[u]) continue;

        for (auto v: floorAcc[u%100]) { // try switching elevators
            if (dist[u]+60<dist[v]) {
                dist[v] = dist[u] + 60;
                pq.push(ii(dist[v], v));
            }
        }

        for (auto adj : graph[u]) { // try going up on the same elevator
            int w = adj.first, v = adj.second;
            if (dist[u] + w<dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(ii(dist[v], v));
            }
        }
    }

    int time = INF;
    for (int i=k;i<500;i+=100) 
        time = min(time, dist[i]);
    
    return time;
}

int main() {
    // freopen("input.txt", "r", stdin);

    while (cin>>n>>k) {
        startLevels.clear();
        for (int i=0;i<100;i++) floorAcc[i].clear();
        for (int i=0;i<500;i++) graph[i].clear();

        for (int i=0;i<n;i++) cin>>speed[i];
        int f;
        string line;
        cin.ignore();

        for (int elev=0;elev<n;elev++) {
            getline(cin, line);
            stringstream ss(line);
            
            vector<int> floors;
            while (ss>>f) floors.push_back(f + elev*100);
            
            for (int j=0;j<floors.size()-1;j++) {
                int u = floors[j], v = floors[j+1];

                if (u%100==0) startLevels.push_back(ii(0, u));

                graph[u].push_back(ii(abs(v-u) * speed[elev], v));
                graph[v].push_back(ii(abs(v-u) * speed[elev], u));

                floorAcc[u%100].push_back(u);
            }

            floorAcc[floors.back()%100].push_back(floors.back());
        }

        int ans = dijkstra();
        if (ans==INF) cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl; 
    }
}