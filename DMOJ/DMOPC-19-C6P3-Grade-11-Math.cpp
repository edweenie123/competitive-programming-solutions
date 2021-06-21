/*
~~~ DMOPC '19 Contest 6 P3 - Grade 11 Math ~~~

Key Concepts: Sets

Store all the unset indices and use a set to iterate through them
*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXS = 5e5 + 5;
const int MOD = 1e9 + 7;

string s;

int sLen, m;
set<int> unset;

ll power[MAXS];
void preprocess() {
    power[0] = 1;
    for (int i=1;i<MAXS;i++) {
        power[i] = (power[i-1] * 2) % MOD; 
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>sLen>>m;
    cin>>s;

    preprocess(); // precomputes powers of 2

    ll curAns = 0;
    for (int i=0;i<sLen;i++) {
        int idx = sLen - 1 - i;
        // this bit is on
        if ((s[idx] - '0')) curAns = (curAns + power[i]) % MOD;
        // this bit is off
        else unset.insert(idx + 1);
    }

    int l, r;

    for (int i=0;i<m;i++) {
        cin>>l>>r;

        while (true) {
            if (unset.empty()) break;
            // find 1st element in set >= l
            set<int>::iterator iter = unset.lower_bound(l);
            int idx = *iter;

            if (idx > r || iter == unset.end()) break;

            curAns = (curAns + power[sLen - idx]) % MOD;
            unset.erase(idx);
        }

        cout<<curAns<<"\n";
    }
}