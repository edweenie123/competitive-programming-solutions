/*
~~~ COCI '08 Contest 2 #3 Perket ~~~

Key Concepts: Brute Force

Use bitmask to iterate through all possible combinations of ingredients

*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int n, s[10], b[10];

ii FSB(int k) {
    int idx = log2(k & -k);
    int fsb = k & -k;

    return ii(idx, fsb); 
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>s[i]>>b[i];
    }

    int sourTot, bitTot;

    int ans = 1e9;
    for (int comb=1;comb<pow(2, n); comb++) {
        int bm = comb;
        ii fsb = FSB(bm); 
        
        sourTot = 1;
        bitTot = 0;

        while (bm) {
            fsb = FSB(bm);
            sourTot *= s[fsb.first];;
            bitTot += b[fsb.first];
            bm -= fsb.second;
        } 
        
        ans = min(ans, abs(sourTot - bitTot));
    }

    cout<<ans<<"\n";

}