/*
~~~ 778A - String Game ~~~

Key Concepts: BS, Greedy

Once you realize, you can BS over the # of operations nastya can perform
    -> the problem becomes pretty ez

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

string t;
string p;

int perm[MAXN];

bool isPossible(int k) {
    set<int> ind;

    for (int i=0;i<k;i++)
        ind.insert(perm[i]-1);

    string newT = "";

    for (int i=0;i<t.length();i++) {
        if (ind.count(i)) continue;
        newT += t[i];
    }

    int tIdx = 0;

    for (int i=0;i<p.length();i++) {

        while (true) {
            if (tIdx >= newT.size()) return false;
            if (p[i] == newT[tIdx]) break;
            tIdx++;
        }

        tIdx++;
    }

    return true;
}

int bs() {
    int lo = 0, hi = t.length() - 1, mid, best;

    while (lo<=hi) {
        int mid = (lo + hi) / 2;
        if (isPossible(mid)) {
            lo = mid + 1;
            best = mid;
        } else {
            hi = mid - 1;
        }
    }
    return best;
}

int main() {
    cin>>t>>p;

    for (int i=0;i<t.length();i++) 
        cin>>perm[i];

    int ans = bs();
    cout<<ans<<"\n";
}