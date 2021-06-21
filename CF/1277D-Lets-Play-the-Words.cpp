/*
~~~ 1277D - Let's Play the Words? ~~~

Key Concepts: Hashing, Insight

Pretty decent problem; i overcomplicated it at first
    but its actually quite simple

Insight 1:
The strings can be in the form of 4 types

    0..1    type 1
    1..0    type 2
    1..1    type 3
    0..0    type 4

Let delta = abs(cnt(type 1) - cnt(type 2))

Through observation, it is possible to include all word if delta <= 1

    Notice that the # of type 3's and type 4's don't matter

If delta > 1, then we need to perform some operations to reduce delta

Insight 2:
There is no point in reversing a type 3 or a type 4 obviously

If cnt(type1) > cnt(type2), then performing an operation on type 1
    reduces delta by 2

otherwise, performing an operation on type 2
    reduces delta by 2

In either case, we always have a way of reducing delta by 2
    therefore, the mimimum # of operations needed is delta/2

Insight 3:
In order to make sure all the reversed words don't already appear in the set of words
    we use a pretty simple rabin-karp + set combo


*/



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 2187328993;
const ll base = 10211;

int n;
vector<int> ans;
vector<string> words;
set<ll> hashes;

ll hasher(string s) {
    ll pow = 1;
    ll hash = 0;

    for (int i=0;i<s.length();i++) {
        hash = (hash + (s[i]-'0'+1) * pow) % MOD;
        pow = (pow * base) % MOD;
    }

    return hash;
}

int solve() {
    ans.clear();
    words.clear();
    hashes.clear();
    cin>>n;

    int t01=0, t10=0, t00=0, t11=0;

    string s;
    for (int i=0;i<n;i++) {
        cin>>s;

        if (s.front()!=s.back()) {
            if (s.front()=='0') t01++;
            else t10++;
        } else {
            if (s.front()=='0') t00++;
            else t11++;
        }

        words.push_back(s);
        ll hash = hasher(s);
        hashes.insert(hash);
    }

    // edge case
    if (!t01 && !t10 && t11 && t00) return -1;

    int delta = t10 - t01;
    int steps = abs(delta/2);

    char lookStr;
    char lookEnd;
    // types you want to change
    if (delta>=0) {
        lookStr = '1';
        lookEnd = '0';
    } else {
        lookStr = '0';
        lookEnd = '1';
    }

    int cnt = 0; // count how many operations we've done

    for (int i=0;i<n;i++) {
        string w = words[i];
        if (cnt==steps) break;

        if (w.front()==lookStr && w.back()==lookEnd) {
            string copy = w;
            reverse(copy.begin(), copy.end());

            ll hash = hasher(copy);

            if (!hashes.count(hash)) {
                cnt++;
                ans.push_back(i+1); // get index of word you want to reverse
            }
        }
    }

    if (cnt!=steps) return -1;
    return cnt;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        int oper = solve();
        cout<<oper<<"\n";
        if (oper==-1) continue;
        for (auto a : ans) 
            cout<<a<<" ";
        cout<<"\n";
    }
}