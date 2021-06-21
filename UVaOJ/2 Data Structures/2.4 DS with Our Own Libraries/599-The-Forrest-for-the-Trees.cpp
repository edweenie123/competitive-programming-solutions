/*
~~~ UVa 599 - The Forrest for the Trees ~~~

Key Concepts: Graph Data Structure

Count # of connected components + acorns in forest (collection of trees)

Method 1: BFS
    Perform BFS starting from every possible node

Method 2: Count # of edges
    Connected components = vertices - edges
    Use a bitset to determine if a node contains a path --> finds acorns
*/

#include <bits/stdc++.h>
using namespace std;

int t, treeCnt=0, acornCnt=0;
map<string, vector<string>> graph;
vector<string> allNodes;
set<string> visited;

void initialize() {

    treeCnt = 0; acornCnt = 0;

    graph.clear();
    string path;
    cin>>path;
    
    while (path[0]!='*') {
        graph[path.substr(1, 1)].push_back(path.substr(3, 1));
        graph[path.substr(3,1)].push_back(path.substr(1,1));
        cin>>path;
    }

    allNodes.clear();
    string temp;
    cin>>temp;

    for (int i=0;i<temp.length();i++) {
        string c = temp.substr(i, 1);
        if (c==",") continue;
        allNodes.push_back(c);
    }

    visited.clear();
}

void BFS(string src) {
    
    if (graph.find(src)==graph.end()) {
        acornCnt++;
        return;
    }
    
    if (visited.find(src)==visited.end()) 
        treeCnt++;
    else return;

    visited.insert(src);

    queue<string> q;
    q.push(src);


    while (!q.empty()) {
        string node = q.front();
        q.pop();

        for (auto adj : graph[node]) {
            if (visited.find(adj)==visited.end()) {
                q.push(adj);
                visited.insert(adj);
            }
        }
    }
}

int main() {
    cin>>t;

    while(t--) {
        initialize();

        for (auto n : allNodes) {
            BFS(n);
        }

        cout<<"There are "<<treeCnt<<" tree(s) and "<<acornCnt<<" acorn(s)."<<endl;
    }
}