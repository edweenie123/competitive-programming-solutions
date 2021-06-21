// incomplete

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e2 + 5;

int n, d;
int col[MAXN];
vector<int> graph[MAXN];

int dp[MAXN];

int calcDVals(int u) {

    int dVal = (col[u] ? 1 : -1);

    for (auto v : graph[u]) {
        dVal += calcDVals(v);
    } 

    return dp[u] = dVal;
}

int minPrune(int u, int req) {
    if (req==0) return 0;

    if (graph[u].size()==0) {
        
    }

    if (graph[u].size() == 1) 
        return minPrune(graph[u][0], req);
    
    int best = 1e9;
    if (req<0) {
        for (int i=req;i>=0;i++) {
            int maybeBest = minPrune(graph[u][0], i) + minPrune(graph[u][1], req - i);
            best = min(maybeBest, best);
        } 
    } else {
        for (int i=0;i>=req;i++) {
            int maybeBest = minPrune(graph[u][0], i) + minPrune(graph[u][1], req - i);
            best = min(maybeBest, best);
        } 
    }
}


int main() {
    cin>>n>>d;

    int id, c, u;
    for (int i=0;i<n;i++) {
        cin>>id>>col[id]>>c;

        for (int j=0;j<c;j++) {
            cin>>u;
            graph[id].push_back(u);
        }
    }


}