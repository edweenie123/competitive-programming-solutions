/*
i have depression

this problem is aids

*/
#include <bits/stdc++.h>

using namespace std;

int n, m;

map<string, int> nameToInd;
map<int, string> indToName;
vector<int> graph[30];

vector<vector<int>> sccAll;

int dfs_num[30], dfs_low[30], dfsNumCnt;
int visited[30];
stack<int> s;

void tarjan(int u) {
    dfs_num[u] = dfs_low[u] = dfsNumCnt++;

    s.push(u);
    visited[u] = 1;

    // printf("looking at %s\n", indToName[u].c_str());
    for (auto v : graph[u]) {
        if (dfs_num[v]==-1) {
            tarjan(v);
        }
        if (visited[v]) 
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u]==dfs_num[u]) {
        vector<int> scc;
        // printf("SCC: ");
        while (1) {
            int v = s.top(); s.pop();
            visited[v] = 0;
            // printf("%d ", v);
            scc.push_back(v);
            if (v==u) break;
        } 
        sccAll.push_back(scc);
    }
}

void getInput() {
    string n1, n2;
    int personNum = 0;

    for (int i=0;i<m;i++) {
        cin>>n1>>n2;
        int u, v;

        if (nameToInd.find(n1)==nameToInd.end()) {
            nameToInd[n1] = personNum;
            indToName[personNum] = n1;
            personNum++;
        } 

        if (nameToInd.find(n2)==nameToInd.end()) {
            nameToInd[n2] = personNum;
            indToName[personNum] = n2;
            personNum++;
        }

        u = nameToInd[n1];
        v = nameToInd[n2];

        graph[u].push_back(v);

    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int ds = 1;
    while (cin>>n>>m) {
        if (n==0&&m==0) break;
        nameToInd.clear(); indToName.clear();

        for (int i=0;i<30;i++) {
            graph[i].clear();
            dfs_num[i] = -1;
            visited[i] = 0;
        }

        dfsNumCnt = 0;
        sccAll.clear();

        getInput();
        
        // for (int i=0;i<n;i++) {
        //     printf("%d-> ", i);
        //     for (auto v : graph[i]) {
        //         printf("%d, ", v);
        //     }cout<<endl;
        // }

        for (int i=0;i<n;i++) 
            if (dfs_num[i]==-1)
                tarjan(i);
        

        printf("Calling circles for data set %d:\n", ds);
        ds++;
        
        // printf("there are %d sccs\n", sccAll.size());

        for (auto i : sccAll) {
            for (int v=0;v<i.size();v++) {
                cout<<indToName[i[v]];
                if (v!=i.size()-1) printf(", ");
            }
            if (i.size()>0) printf("\n");
        }
        printf("\n");
    }
}