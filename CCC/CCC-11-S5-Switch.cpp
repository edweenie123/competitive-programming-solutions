/*
~~~ CCC '11 S5 - Switch ~~~

Key Concepts: Graph Theory

The idea is to just brute force over all possible moves you can make using BFS
-> use bitmask to save memory


*/



#include<bits/stdc++.h>
using namespace std;

const int MAXK = 25;

typedef pair<int, int> ii;

int k;
queue<ii> q;
bool vis[33554432];

int turnOffBlock(int l, int r, int u) {
    // turn off all bits between l and r
    for (int i=l;i<=r;i++) {
        u ^= (1<<i);
    }
    return u;
}

int fix(int &u) {
    // turns off blocks of >= 4

    int idx=-1, len=0;

    for (int i=0;i<k;i++) {
        if ((u & (1<<i))) {
            if (len==0) {
                idx = i;
                len = 1;
            } else {
                len++;
            }
        } else {
            if (len >= 4) 
                return turnOffBlock(idx, idx+len-1, u);
            len = 0;
        }
    }

    if (len >= 4) 
        return turnOffBlock(idx, idx+len-1, u);
    
    // no blocks >= 4 
    return u;
}


int bfs(int str, int tar) {

    q.push({str, 0});

    while (!q.empty()) {

        ii fr = q.front(); q.pop();
        int u = fr.first, d = fr.second;

        if(u == tar) return d;

        // go through each bit and consider turning it on
        for (int i=0;i<k;i++) {
            // check if bit is off
            if ((u & (1<<i)) == 0) {

                int v = u | (1<<i);

                v = fix(v);

                if (!vis[v]) {
                    q.push({v, d+1});
                    vis[v] = true;
                }
            }
        }
    }

    return -1;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>k;

    bool on;

    int init = 0;
    for (int i=0;i<k;i++) {
        cin>>on;
        if (on) init |= (1<<i);
    }

    int ans = bfs(init, 0);
    cout<<ans<<endl;
}