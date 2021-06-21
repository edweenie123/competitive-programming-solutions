/*
~~~ UVa 821 - Page Hopping ~~~

Key Concepts: Floyd Warshall

Since the number of vertices is small (<100) we can use Floyd Warshall to generate distances between all pairs of vertices
*/

#include <bits/stdc++.h>

using namespace std;
const int INF = 1e7;
int dist[101][101];

int fw() { // returns sum of all dist pairs
    for (int k=0;k<101;k++) 
        for (int i=0;i<101;i++)
            for (int j=0;j<101;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    int sum = 0;
    for (int i=0;i<101;i++)
        for (int j=0;j<101;j++)
            if (dist[i][j]!=INF) sum+=dist[i][j];
    
    return sum;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int caseNum = 0;
    string line;
    while (getline(cin, line)) {
        for (int i=0;i<101;i++) for (int j=0;j<101;j++) i==j ? dist[i][j] = 0 : dist[i][j] = INF;
        stringstream ss(line);
        set<int> pages;
        
        int u, v;
        while (ss>>u>>v) {
            if (u+v==0) break;
            dist[u][v] = 1;
            pages.insert(u);
            pages.insert(v);
        }
        if (pages.size()==0) break;
        
        
        int numPairs = pages.size() * (pages.size()-1);
        float ans = (float)fw() / (float) numPairs;

        ans = round(ans * 1000) / 1000; // round to nearest 1000th
        
        printf("Case %d: average length between pages = %.3f clicks\n", ++caseNum, ans);

    }
}