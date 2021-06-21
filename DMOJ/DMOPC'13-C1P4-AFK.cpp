// Key Concepts: Graph Theory

#include <bits/stdc++.h>
using namespace std;

string room[51];
int t, l, w, dist[51][51];

vector<array<int,2>> getPos(array<int,2> c) {
    array<array<int,2>,4> pos = {{
        {c[0]-1, c[1]},
        {c[0]+1, c[1]},
        {c[0], c[1]-1},
        {c[0], c[1]+1}
    }};
    vector<array<int,2>> valid;
    for (auto p : pos) {
        if (p[0]>=0&&p[0]<w&&p[1]>=0&&p[1]<l) {
            if (room[p[0]][p[1]]!='X')
                valid.push_back(p);
        }
    }
    return valid;
}

bool BFS (array<int, 2> s) {
    memset(dist, -1, sizeof(dist));
    dist[s[0]][s[1]] = 0;

    queue<array<int, 2>> q;
    q.push(s);

    while(!q.empty()) {
        array<int, 2> v = q.front();
        q.pop();

        int d = dist[v[0]][v[1]];
        for (auto pos : getPos(v)) {
            if (room[pos[0]][pos[1]]=='W') {
                if (d+1<60) {
                    cout<<d+1<<endl;
                    return true;
                }
            } else if (dist[pos[0]][pos[1]]==-1) {
                dist[pos[0]][pos[1]] = d+1;
                q.push(pos);
            } else {
                dist[pos[0]][pos[1]] = min(d+1, dist[pos[0]][pos[1]]);
            }
        }
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while (t--) {
        cin>>l>>w;
        array<int, 2> start = {-1, -1};
        for (int i=0;i<w;i++) {
            string row;
            cin>>row;
            if (row.find("C")!=string::npos) {
                start[0]=i;
                start[1]=row.find("C");
            }
            room[i] = row;
        }
        if (!BFS(start)) cout<<"#notworth"<<endl;
    }
}