/*
~~~ 1154E - Two Teams ~~~

Key Concepts: Sets, Implementation

You can simulate the process of every operation naively 
    quickly if you use two sets

The idea is pretty easy to come out will, but implementation is kinda yucky

*Important Lesson: if you delete an iterator before your current iterator,
    it changes the value of the current itertor -> it needs to be updated


*/



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

int sktoid[MAXN]; // skill to idx
int idtosk[MAXN]; // idx to skill

set<int> idxs;
set<int> skills;

int ans[MAXN];

void solve() {
    int n, k;
    cin>>n>>k;

    int sk;
    for (int i=1;i<=n;i++) {
        cin>>sk;
        sktoid[sk] = i;
        idtosk[i] = sk;

        idxs.insert(i);
        skills.insert(sk);
    }

    int turn = 0; // keep track of whose turn it is

    while (true) {
        if (skills.empty()) break;

        auto skill = (--skills.end());
        auto idx = idxs.find(sktoid[*skill]);

        vector<ii> take;
        take.push_back({*idx, *skill});

        auto curIdx = idx;
        for (int i=0;i<k;i++) {
            auto nxt = next(curIdx);
            if (nxt == idxs.end()) break;
            
            auto nxtSkill = skills.find(idtosk[*nxt]);
            take.push_back({*nxt, *nxtSkill});
            curIdx = nxt;
        }

        curIdx = idx;

        for (int i=0;i<k;i++) {
            if (curIdx == idxs.begin()) break;
            auto prv = prev(curIdx);
            
            auto prvSkill = skills.find(idtosk[*prv]);
            take.push_back({*prv, *prvSkill});
            curIdx = prv;
        }

        for (auto t : take) {
            ans[t.f] = (turn ? 2 : 1);
            idxs.erase(idxs.find(t.f));
            skills.erase(skills.find(t.s));
        }

        turn = !turn;
    }

    for (int i=1;i<=n;i++) cout<<ans[i];
    cout<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}