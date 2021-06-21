/*
~~~ CCC '14 S5 - Lazy Fox ~~~

Key Concepts: High IQ DP

*/

#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
const int MAXN = 2e3 + 5;

vector<ii> points;
int n;
int dp[MAXN]; // dp[i] = max candies attainable from node i

int prevDist[MAXN], prevDp[MAXN];

struct edge {
    int a, b, dist;

    friend bool operator<(const edge &a, const edge &b) { 
        return a.dist < b.dist;
    }
};

vector<edge> allEdges;

void calcDist() {
    int dx, dy, d;
    for (int i=0;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            dx = points[i].f - points[j].f;
            dy = points[i].s - points[j].s;

            d = dx*dx + dy*dy;
            allEdges.pb(edge{i, j, d});
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    points.push_back(ii{0, 0});
    
    int x, y;
    for (int i=0;i<n;i++) {
        cin>>x>>y;
        points.push_back(ii{x, y});
    }

    calcDist();

    sort(allEdges.begin(), allEdges.end());

    int a, b, d;
    for (auto p : allEdges) {
        a = p.a, b = p.b, d = p.dist;
        
        /* 
        if d is the same length as the edge used to make the optimal path:
            prevDp = the next best length that uses a shorter edge
        else
            prevDp = dp 
        */

        if (d != prevDist[b]) {
            prevDist[b] = d;
            prevDp[b] = dp[b];
        }

        if (d != prevDist[a]) {
            prevDist[a] = d;
            prevDp[a] = dp[a];
        }
        
        // start at a and then go to b
        dp[a] = max(dp[a], prevDp[b] + 1);

        if (a==0) continue; // we don't update dp[b] cause we can't go from node b to origin

        // start at b and then go to a
        dp[b] = max(dp[b], prevDp[a] + 1);

        
    }

    int ans = dp[0];
    cout<<ans<<"\n";
}