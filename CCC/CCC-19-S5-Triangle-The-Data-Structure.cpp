/*
~~~ CCC'19 S5 - Triangle: The Data Structure ~~~

Key Concepts: DP

DP[sz][i][j] stores the max value within the subtriangle of size sz rooted at (i, j) 

You can construct DP[sz * 3/2] using DP[sz] => draw it out to see why
    - We use this strategy to generate up until DP[k]

The sum of all the values in DP[k] gives the answer

Time Complexity: O(n^2 log k)
*/



#include<bits/stdc++.h>
using namespace std;

#define PB push_back
typedef unsigned long long ll;
const int MAXN = 5000;

int n, k;
int dp1[MAXN][MAXN];
int dp2[MAXN][MAXN];

ll maximum(ll a, ll b, ll c) {
    return max(a, max(b, c));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;

    int val;
    
    for (int i=0;i<n;i++) {
        for (int j=0;j<i+1;j++) {
            cin>>val;
            dp1[i][j] = val;
        }
    }

    int top, right, left; 

    float prevSize = 1;
    float size;
    
    for (size=2;size<=k; size = ceil(size * (3.0/2.0))) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<i+1;j++) {
                int layer = i+size-prevSize;
                
                top = dp1[i][j];
                left = dp1[layer][j];
                right = dp1[layer][j + layer - i];    

                dp2[i][j] = maximum(top, left, right);
            }
        }
        
        prevSize = size;

        for (int i=0; i<n; i++) 
            for (int j=0;j<i+1;j++) 
                dp1[i][j] = dp2[i][j];
        
    }
    
    if (prevSize!=k) {
        size = k;

        for (int i=0;i<n;i++) {
            for (int j=0;j<=i+1;j++) {
                int layer = i+size-prevSize;
                
                top = dp1[i][j];
                left = dp1[layer][j];
                right = dp1[layer][j + layer - i];    

                dp2[i][j] = maximum(top, left, right);
            }
        }
    }

    // get sum
    ll ans = 0;

    if (k!=1)
        for (int i=0;i<n-k+1;i++) 
            for (int j=0;j<i+1;j++) 
                ans += dp2[i][j];
    else 
        for (int i=0;i<n;i++)
            for (int j=0;j<i+1;j++) 
                ans += dp1[i][j];
                

    cout<<ans<<"\n";
}
