#include<bits/stdc++.h>
using namespace std;


const int MAXN = 2e5 + 5;
int n, q;
int bit1[MAXN], bit2[MAXN], arr[MAXN];

map<int, vector<int>> indices;

struct aQuery {
    int r, l, k, idx;

    friend bool operator<(const aQuery &a, const aQuery &b) {
        return a.k < b.k;
    }
};

vector<aQuery> queries;

void update(int* bit, int k, int val) {
    while(k<=n) {
        bit[k] += val;
        k += (k & -k);
    }
}

int query(int* bit, int k) {
    int tot = 0;
    while (k>0) {
        tot += bit[k];
        k -= (k & -k);
    }
}

int queryRange(int* bit, int l, int r) {
    return query(bit, r) - query(bit, l-1);
}

int main() {
    cin>>n>>q;
    
    int tmp;
    for (int i=1;i<=n;i++) {
        cin>>tmp;
        arr[i] = tmp;

        update(bit1, i, tmp);
        indices[tmp].push_back(i);
    }

    int l, r, k;
    for (int i=0;i<q;i++) {
        cin>>l>>r>>k;
        queries.push_back(aQuery{l, r, k, i});
    }

    sort(queries.begin(), queries.end());

    int lastQueryIdx = queries.size() - 1;

    map<int, int>::reverse_iterator it;
    for (it = indices.rbegin(); it!=indices.rend(); it++) {
        int val = it->first;
        for (auto idx : indices[val]) {
            update(bit2, idx, val);
        }
    }
}