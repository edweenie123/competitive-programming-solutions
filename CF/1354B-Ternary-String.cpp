/*
~~~ 1354B Ternary String ~~~

Key Concepts: Binary Search, PSA

pretty simple binary search problem

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXS = 2e5 + 4;

int psa1[MAXS], psa2[MAXS], psa3[MAXS];

string s;

int rsq(int l, int r, int* psa) {
    return psa[r] - psa[l-1];
}

bool isValid(int l, int r) {
    if (rsq(l, r, psa1)>0 && rsq(l, r, psa2)>0 && rsq(l, r, psa3)>0)
        return true;
    return false;
}

// find length of shortest valid substring starting from k
int bs(int k) { 
    int lo = k, hi = s.length()-1, mid=-1, best=-1;

    while (lo<=hi) {
        mid = (lo + hi) / 2;
        if (isValid(k, mid)) {
            hi = mid - 1;
            best = mid;
        } else 
            lo = mid + 1;
    }

    if (best==-1) return 1e9;

    return best - k + 1;
}


int main() {
    int TC; cin>>TC;

    while (TC--) {
        cin>>s;

        s = " " + s;

        // compute psa for each boi
        psa1[0] = psa2[0] = psa3[0] = 0;
        for (int i=1;i<=s.length()-1;i++) {
            psa1[i] = psa1[i-1] + (s[i]=='1' ? 1 : 0);
            psa2[i] = psa2[i-1] + (s[i]=='2' ? 1 : 0);
            psa3[i] = psa3[i-1] + (s[i]=='3' ? 1 : 0);
        }

        int minLen = 1e9;

        for (int i=1;i<=s.length()-1;i++) {
            int maybeAns = bs(i);
            if (maybeAns < minLen)
                minLen = maybeAns;
        }

        cout<<(minLen!=1e9 ? minLen : 0)<<"\n";
    }

}