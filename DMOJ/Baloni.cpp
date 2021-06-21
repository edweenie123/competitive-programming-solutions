/*
~~~ COCI '15 Contest 1 #3 Baloni ~~~

Key Concepts: Greedy Algorithms

Iterate through the list of balloons:
    if there isn't an arrow at that height -> shoot one
    else                                   -> reduce the height of that arrow by 1
    
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int n, heights[MAXN], arrows[MAXN];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=0;i<n;i++) cin>>heights[i];

    int cnt = 0;
    for (int i=0;i<n;i++) {
        int h = heights[i];

        if (arrows[h]==0) {
            arrows[h-1]++;
            cnt++;
        } else {
            arrows[h]--;
            arrows[h-1]++;
        }
    }

    cout<<cnt<<"\n";
}