/*
~~~ CCC '01 S5 - Post's Correspondence Problem ~~~

Key Concepts: Recursion

Simply try all possible sequences of integers until the condition is satified
*/

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int m, n;
string A[41], B[41];
vector<int> solve(string aCur, string bCur, int ind) {
    int sameIdx = min(aCur.size(), bCur.size());
    if (aCur.substr(0, sameIdx)!=bCur.substr(0, sameIdx)) {
        return vi({-1});
    }
    
    if (aCur==bCur&&!aCur.empty()) return vi({});
    if (ind==m) {
        return vi({-1});
    }
    
    vector<int> seq;
    for (int i=1;i<=n;i++) {
        seq = solve(aCur+A[i], bCur+B[i], ind+1);
        if (seq!=vi({-1})) {
            seq.push_back(i);
            break;   
        } 
    }
    return seq;
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin>>m>>n;
    for (int i=1;i<=n;i++) cin>>A[i];
    for (int i=1;i<=n;i++) cin>>B[i];

    vector<int> ans = solve("", "", 1);
    if (ans==vi{-1}) {
        cout<<"No solution."<<"\n";
    } else {
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<"\n";
        for (auto a : ans ) cout<<a<<"\n";
    }
}