/*
~~~ CCC '15 J5 - Pi-Day ~~~

Key Concepts: Dynamic Programming
*/

#include <bits/stdc++.h>
using namespace std;

int n, k, memo[251][251][251];

int ways(int pieLeft, int last, int per) {
    // printf("pl:%d, last:%d, per:%d\n", pieLeft, last, per);
    if (per==k&&pieLeft<last) return 0;
    if (per==k&&pieLeft>=last) {
        // cout<<"yee"<<endl;
        return 1;
    }

    if (memo[pieLeft][last][per]!=-1) return memo[pieLeft][last][per];
    
    int ans = 0;
    
    for (int i=last;i<=pieLeft;i++) 
        ans += ways(pieLeft-i, i, per+1);
    
    return memo[pieLeft][last][per] = ans;
}

int main() {
    cin>>n>>k;
    for (int i=0;i<251;i++) for (int j=0;j<251;j++) for (int k=0;k<251;k++) memo[i][j][k] = -1;
    int ans = ways(n, 1, 1);
    cout<<ans;
}