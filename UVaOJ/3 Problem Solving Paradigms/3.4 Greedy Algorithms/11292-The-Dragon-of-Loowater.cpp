/*
~~~ UVa 11292 - The Dragon of Loowater ~~~

Key Concepts: Greedy

Simple intuitive Greedy Algorithm to minimize cost using sorting
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, heads[20005], heights[20005];

int main() {
    // freopen("input.txt", "r", stdin);
    while(cin>>n>>m) {
        if (n==0&&m==0) return 0;
        for (int i=0;i<n;i++) cin>>heads[i];
        for (int i=0;i<m;i++) cin>>heights[i];
        sort(heads, heads+n);
        sort(heights, heights+m);

        int cost = 0, headNum = 0;
        for (int i=0;i<m;i++) {
            if (heights[i]>=heads[headNum]) {
                cost += heights[i];
                headNum++;
                if (headNum==n) break;
            }
        }

        headNum==n ? cout<<cost : cout<<"Loowater is doomed!";
        cout<<endl;
    }
}