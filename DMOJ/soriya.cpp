/*

imagine a 2d grid the y-axis represents indices and x-axis represents values


[5, 2, 6, 4, 1, 3] is represented as

    0 0 0 0 1 0
    0 1 0 0 0 0
    0 0 0 0 0 1
    0 0 0 1 0 0
    1 0 0 0 0 0
    0 0 1 0 0 0

We can use a fenwick tree to represent this

So the update arr[idx][val] = 1 is done like this 

for (int i=idx;i<=n;i+=LSB(i)) {
    for (int j=val;j<=n;j+=LSB(j)) {
        bit[i][j] += 1;
    }
}

bit[i] stores the an array of integers ai that each stores # of values within a different binary range



*/



#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 5e5 + 3;

int LSB(int k) {return k & -k;}

int n, arr[MAXN], perm[MAXN];


// items[i] stores the values that are covered under a BIT range
vector<int> items[MAXN];


vector<int> bit[MAXN];


// returns # of elements between [l, r] that are higher than val
int queryHigher(int l, int r, int val) {
    for (int i=)
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    for (int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    int p;

    for (int i=1;i<=n;i++) {
        cin>>perm[i];

        int val = arr[perm[i]];
        int idx = perm[i];

        for (int k=val;k<=n;k+=LSB(k)) {
            items[k].push_back(idx);
        }
    }

    // make bit[i] be the same size as items[i]
    for (int i=1;i<=n;i++) {
        bit[i].resize(items[i].size(), 0);
    }    

    for (int i=1;i<=n;i++) {
        int idx = perm[i];
        int val = arr[perm[i]];

        // elements > val, but index < idx



    }

    // ll inversions = 0;
    // for (int i=0;i<n;i++) {
    //     cin>>p;

    //     // count # of elements > arr[p] that have smaller idx
    //     ll greater = queryGreater(p-1, arr[p]);

    //     // count # of elements < arr[p] that have greater idx
    //     ll less = queryLessRange(p+1, n, arr[p]);    

    //     update(p, arr[p]);

    //     inversions += greater + less;
    //     cout<<inversions<<"\n";
    // }

}



