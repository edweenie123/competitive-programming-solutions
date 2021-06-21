/*
~~~ 1367C - Social Distance ~~~

Key Concepts: Greedy

ez problem, but took me way too long cause im stupid

Insight 1: 
If we find the length of each block of 0, we can greedily find the answer
    by replacing a 0 in a block AS OFTEN AS POSSIBLE

Note that we have to becareful of 3 cases:
    a block with no 1 on the left               -> the first k 0's in this block can't be used
    a block with no 1 on the right              -> the last k 0's in the block can't be used
    a block with no 1 on the left and right     -> the first k and last k 0's can't be used

We iterate through each block of 0's and use a math formula to find the answer

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, k;
string s;

struct block {
    int sz; 
    bool hasLeft;
    bool hasRight;
};

vector<block> sizes;

int solve() {
    sizes.clear();

    cin>>n>>k>>s;

    bool noOne = true;
    int curSz = 0;

    for (int i=0;i<n;i++) {
        if (s[i]=='0') {
            curSz++;
        } else {
            sizes.push_back(block{curSz, !noOne, true});
            noOne = false;
            curSz = 0;
        }
    } 

    if (curSz!=0) {
        sizes.push_back(block{curSz, !noOne, false});
    }

    int cnt = 0;
    for (auto s : sizes) {
        
        int sz = s.sz;
        if (s.hasLeft) sz -= k;
        if (s.hasRight) sz -= k;
        if (sz < 1) continue;
        int ppl = (sz-1) / (k + 1) + 1;
        if (ppl > 0) cnt += ppl;
    }   

    return cnt;
    
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        int ans = solve();
        cout<<ans<<"\n";
    }
}