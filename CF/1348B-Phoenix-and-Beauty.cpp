/*
~~~ 1348B - Phoenix and Beauty ~~~

Key Concepts: Constructive algorithms

The key observation is that a beautiful array is just the same subarray of length k 
    repeated over and over again

Therefore, if the array contains more than k distict elements -> it is impossible

Otherwise, we just pick an arbitary pattern of length k that contains all the distinct elements in the array
    and repeat it over and over again



*/

#include<bits/stdc++.h>
using namespace std;

#define PB push_back

int n, k;
set<int> seen;

vector<int> ans;
vector<int> pattern;

void spam() {

    for (auto s : seen) 
        pattern.PB(s);
    
    while (pattern.size() != k)
        pattern.PB(*seen.begin());

    int patternLen = pattern.size();

    while (true) {
        if (ans.size() + patternLen > 1e4) break;

        // add the pattern to the answer
        ans.insert(ans.end(), pattern.begin(), pattern.end());    
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int TC; cin>>TC;

    while (TC--) {
        seen.clear();
        ans.clear();
        pattern.clear();

        cin>>n>>k;

        int tmp;
        for (int i=0;i<n;i++) {
            cin>>tmp;
            seen.insert(tmp);
        }

        if (seen.size() > k) {
            cout<<"-1\n";
            continue;
        }

        spam();

        cout<<ans.size()<<"\n";

        for (auto a : ans) 
            cout<<a<<" ";
        
        cout<<"\n";
    }
}