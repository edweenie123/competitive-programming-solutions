/*
~~~ 349B - Color the Fence ~~~

Key Concepts: Greedy

Pretty ez greedy 

*/


#include<bits/stdc++.h>
using namespace std;

int v;
int cost[10];

string solve() {
    cin>>v;
    int cheap = 1e9;
    for (int i=1;i<10;i++) {
        cin>>cost[i];
        cheap = min(cost[i], cheap);
    }

    if (cheap > v) return "-1";

    int sz = v / cheap;
    string ret = "";

    // cout<<sz<<" nani \n";
    for (int i=0;i<sz-1;i++) {
        int digLeft = sz-i;
        for (int j=9;j>=1;j--) {

            int left = v - cost[j];

            if (left / cheap >= digLeft-1) {
                ret += to_string(j);
                v = left;
                break;
            }
        }
    }

    for (int i=9;i>=1;i--) {
        if (cost[i] <= v) {
            ret += to_string(i);
            break;
        }
    }

    return ret;
    

}

int main() {
    string ans = solve();
    cout<<ans<<"\n";    
}