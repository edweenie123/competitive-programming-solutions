/*
~~~ DMOPC '14 Contest 2 P6 - Selective Cutting ~~~

Key Concepts: BIT, Offline Solution

We first parse all queries by sorting them in increasing q order

We add trees to a fenwick tree in order of decreasing mass
    Once we have added all tress with mass i:
        We can now answer all queries that have q = i since all the masses in the BIT have a mass >= q

*/

#include<bits/stdc++.h>
using namespace std;

#define PB push_back

const int MAXN = 1e5 + 1;
const int MAXM = 2e4 + 1;
const int MAXQ = 1e5 + 1;

int n, Q, BIT[MAXN];
vector<int> trees[MAXM];
int answers[MAXQ];

struct query {
    int a, b, q, idx;
    bool operator<(const query &query1) const {
        return q < query1.q;
    }
};
vector<query> queries;

void update(int k, int val) {
    while (k<=n) {
        BIT[k] += val;
        k += k & -k;
    }
}

int getSum(int k) {
    int tot = 0;
    while (k>0) {
        tot += BIT[k];
        k -= k & -k;
    }
    return tot;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    int tmp;
    for (int i=1;i<=n;i++) {
        cin>>tmp;
        trees[tmp].PB(i);
    }

    cin>>Q;

    int a, b, q;
    for (int i=0;i<Q;i++) {
        cin>>a>>b>>q;
        queries.PB(query{a+1, b+1, q, i});
    }

    sort(queries.begin(), queries.end());

    int queriesIdx = Q-1;
    for (int m=MAXM;m>0;m--) {
        for (auto t : trees[m]) 
            update(t, m);
        
        while (queries[queriesIdx].q==m) {
            int a = queries[queriesIdx].a, b = queries[queriesIdx].b;
            int idx = queries[queriesIdx].idx;

            int ans = getSum(b) - getSum(a-1);
            answers[idx] = ans;

            queriesIdx--;
        }
    }

    for (int i=0;i<Q;i++) 
        cout<<answers[i]<<"\n";
}