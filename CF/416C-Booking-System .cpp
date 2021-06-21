/*
~~~ 416C - Booking System ~~~

Key Concepts: Greedy

Key Concepts (if yucky): DP, binary search

I initially implemented the yuckyest dp + recursive backtracking + bs to solve the problem
    -> i mean it works, but the code is really messy (look on CF to see the code)

Insight 1:
    Realize that if we always try to take the group that gives us the most money -> we get optimal answer
        -> IE give the group with largest money the smallest possible table and repeat

That's it lmao (very simple)

*/


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
const int MAXN = 1e3 + 5;

int n, k;

struct group {
    int id, ppl, mny;
};

struct table {
    int id, sz;
    bool empty;
};

bool cmp(group &a, group &b) {
    return a.mny > b.mny;
}

bool cmp2(table &a, table &b) {
    return a.sz < b.sz;
}

vector<group> groups;
vector<table> tables;
vector<ii> orders;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    int c, p;
    for (int i=1;i<=n;i++) {
        cin>>c>>p;
        groups.push_back(group{i, c, p});
    }

    cin>>k;

    int t;
    for (int i=1;i<=k;i++) 
        cin>>t, tables.push_back(table{i, t, true});
    

    sort(groups.begin(), groups.end(), cmp);
    sort(tables.begin(), tables.end(), cmp2);

    int ans = 0;

    for (int i=0;i<n;i++) {
        
        for (int j=0;j<k;j++) {
            if (tables[j].empty && tables[j].sz >= groups[i].ppl) {
                tables[j].empty = false;
                ans += groups[i].mny;
                orders.push_back({groups[i].id, tables[j].id});
                break;
            }
        }
    }

    cout<<orders.size()<<" "<<ans<<"\n";

    for (auto o : orders) {
        cout<<o.first<<" "<<o.second<<"\n";
    }

}