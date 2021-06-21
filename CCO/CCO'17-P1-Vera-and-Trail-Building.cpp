/*
~~~ CCO '17 P1 - Vera and Trail Building ~~~

Key Concepts: Simple Math, Graph Theory (kinda)
*/

#include<bits/stdc++.h>
using namespace std;

double k;
string edges = "";
int v=0, e=0;

int curNode = 1;
bool circles(int node) {
    double nDub = ( -1.0 + sqrt(1.0 + 8.0 * k) ) / 2.0;
    int n = floor(nDub);
    
    int left = k - (n + n*n)/2;
    k = left;
    
    for (int i=node;i<=n+node-1;i++) {
        edges += to_string(i) + " " + to_string(i+1) + "\n";
    } edges += to_string(n+1+node-1) + " " + to_string(node) + "\n";

    
    e += n+1;
    v += n+1;
    curNode += n;
    if (k==0) return false;

    return true;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>k;
    
    while (true) {
        if (!circles(curNode)) break;
        edges += to_string(curNode) + " " + to_string(curNode + 1) + "\n";
        e += 1;
        curNode+=1;
    }
    
    cout<<v<<" "<<e<<"\n";
    cout<<edges;    
}