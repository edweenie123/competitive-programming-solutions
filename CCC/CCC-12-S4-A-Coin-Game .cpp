/*
~~~ CCC '12 S4 - A Coin Game ~~~

Key Concepts: BF, BFS

Its a lot easier than it seems

Notice that the upper bound for n is very very small

With some math, you can realize that the totol number of positions is pretty small
    -> therefore we can brute force through all possible moves using BFS

You have to use a map to store previous states to not TLE tho

*/



#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> state;

int n;
unordered_map<state, int> dist;

int bfs(state src) {
    // aliases??
    dist.clear();
    dist[src] = 0;

    queue<state> q;
    q.push(src);

    while (!q.empty()) {
        state u = q.front(); q.pop();
        int d = dist[u];

        bool isGood = true;

        for (int i=0;i<u.size();i++) {
            if (u[i].size() != 1) {
                isGood = false;
                break;
            }
            if (u[i][0] != i+1) {
                isGood = false;
                break;
            }
        }
        // cout<<"bruh\n";
        if (isGood) 
            return d;
        

        // find valid moves

        for (int i=0;i<u.size();i++) {
            vector<int> pos = u[i];

            if (!pos.empty()) {
                // try move left
                if (i!=0)
                    if (u[i-1].empty() || u[i-1].back() > u[i].back()) {
                        state copy = u;
                        int val = copy[i].back();
                        copy[i-1].push_back(val);
                        copy[i].pop_back();

                        if (!dist.count(copy)) {
                            q.push(copy);
                            dist[copy] = d+1;
                        }

                    }

                // try move right
                if (i!=n-1)
                    if (u[i+1].empty() || u[i+1].back() > u[i].back()) {
                        state copy = u;

                        int val = copy[i].back();
                        copy[i+1].push_back(val);
                        copy[i].pop_back();

                        if (!dist.count(copy)) {
                            q.push(copy);
                            dist[copy] = d+1;
                        }

                    }

            }
        }
    }

    return -1;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    while (true) {
        cin>>n;

        if (n==0) break;

        state init;
        int tmp;
        for (int i=0;i<n;i++) {
            vector<int> pos;
            cin>>tmp;
            pos.push_back(tmp);
            init.push_back(pos);
        }

        int ans = bfs(init);

        if (ans == -1) 
            cout<<"IMPOSSIBLE\n";
        else {
            cout<<ans<<"\n";
        }
    }
}