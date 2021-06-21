/*
~~~ 11991 - Easy Problem from Rujia Liu? ~~~

Key Concepts: Adjacency List

Given an array of size N, answer M queries which ask: 
    What is the index of the Kth occurance of V

Use the idea of Adjacencies lists:
    map[v] --> [indices of all occurances of v]

Queries can be answered in O(log n)
*/

#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> occurances;
int main() {
    int n, m;
    while (cin>>n) {
        cin>>m;
        occurances.clear();

        int temp;
        for (int i=0;i<n;i++) {
            cin>>temp;
            occurances[temp].push_back(i+1);
        }

        int k, v;
        for (int i=0;i<m;i++) {
            cin>>k>>v;
            if (occurances[v].size()<k) cout<<0<<endl;
            else cout<<occurances[v][k-1]<<endl;
        }
    }
}