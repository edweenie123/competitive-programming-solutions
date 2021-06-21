/*
~~~ UVa 1203 - Argus ~~~

Key Concepts: Priority Queue

Use a priority queue to sort queries based on its time
Use a map to store the period of each Q_num

Since we want the priority queue to sort the time in decending order:
    We store the negative time and id instead
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

priority_queue<pii> pq;
map<int, int> memo;

int main() {
    string type;
    
    int qNum, period;
    while (cin>>type, type!="#") {
        cin>>qNum>>period;
        pq.push(make_pair(-period, -qNum));
        memo[qNum] = period; 
    }
    int k; cin>>k;
    pii data;
    
    while (k--) {
        data = pq.top();
        pq.pop();

        int code = -data.second, seconds = -data.first;
        cout<<code<<endl;
        pq.push(make_pair(-seconds-memo[code], -code));
    }
}