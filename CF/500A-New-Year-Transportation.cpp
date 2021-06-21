// Solved!
#include <bits/stdc++.h>
using namespace std;

int n, t, portals[30001];
bool visited[30001];

bool BFS (int start, int end) {
    memset(visited,false,sizeof(visited));
    queue<int> q;
    q.push(start);

    visited[start] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v>end) return false;
        if (v==end) return true;
        int ai = portals[v];
        if (!visited[v+ai]) {
            q.push(v+ai);
            visited[v+ai]=true;
        } else return false;
    }
    return false;

}

int main(){
    cin>>n>>t;
    for(int i=1;i<n;i++) cin>>portals[i];
    // for(int i=0;i<n;i++) cout<<portals[i]<<" ";
    BFS(1,t) ? cout<<"YES" : cout<<"NO";
    cout<<endl;
}