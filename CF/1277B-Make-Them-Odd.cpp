/*
~~~ 1277B - Make Them Odd ~~~

Key Concepts: Implementation?

We store all the numbers that we have resolved

While dividing a number by 2, if we reach a number we have already resolved
    => Stop



*/

#include<bits/stdc++.h>
using namespace std;

unordered_map<int, bool> done;
int n; vector<int> nums;

int solve() {
    int moves = 0;
    for (auto num : nums) {
        int boi = num;
        if (done[boi] || boi % 2 == 1) continue;
        
        while (true) {
            boi /= 2;
            moves++;

            if (done[boi] || boi % 2 == 1) break;
            done[boi] = true;
        }
        done[num] = true;

    }

    return moves;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;
    while (TC--) {
        done.clear();
        nums.clear();

        cin>>n;
        int tmp;
        for (int i=0;i<n;i++)
            cin>>tmp, nums.push_back(tmp);
        
        int ans = solve();
        cout<<ans<<"\n";

    }
}