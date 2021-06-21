/*
~~~ 1095E - Almost Regular Bracket Sequence ~~~

Key Concepts: Bracket Sequences

Good problem to test how good you are at bracket sequences

The key is the realize how each operation affects the cumulative sum array

let bb mean beginning bracket and eb mean ending bracket

Insight 1:
If you change bb to eb => the cs decreases by 2
If you change eb to bb => the cs increases by 2

Therefore the cs must be either 2 or -2 at the beginning for there to be a valid move

Insight 2:
Let cs[i] denote the cs from 1-i

At index i:
    If you change bb to eb, then the cs from i+1->n decreases by 2
        therefore the min element in the range i+1->n must be greater than or equal to 2
            since the cs can never be <0
    
    if you change eb to bb, then the cs from i+1-> increases by 2
        therefore the min element in the range i+1->n must be greater or equal to -2
            since the cs can never be <0
    
Do a linear scan to check where the conditions are furfilled using a suffix min array


*/


#include<bits/stdc++.h>
using namespace std;

#define endl "\n";
const int MAXN = 1e6 + 5;

int n;
string s;

int sufMin[MAXN];
int cs[MAXN]; // cummuative sum

int solve() {
    cin>>n>>s;
    s = ' ' + s; // dummy value

    for (int i=1;i<=n;i++) {
        if (s[i]=='(') cs[i] = cs[i-1] + 1;
        else cs[i] = cs[i-1] -1;
    }

    if (cs[n] != 2 && cs[n] != -2) return 0;

    sufMin[n+1] = 1e9;

    for (int i=n;i>=1;i--)
        sufMin[i] = min(sufMin[i+1], cs[i]);

    int minSoFar = 1e9;
    int ans = 0;

    if (cs[n]==2) {
        for (int i=1;i<=n;i++) {
            if (s[i] == '(' && sufMin[i]>=2 && minSoFar>=0) ans++;
            minSoFar = min(minSoFar, cs[i]);
        }
    } else {
        for (int i=1;i<=n;i++) {
            if (s[i] == ')' && sufMin[i]>=-2 && minSoFar>=0) ans++;
            minSoFar = min(minSoFar, cs[i]);
        }
    }

    return ans;
}


int main() {
    int ans = solve();
    cout<<ans<<endl;
}