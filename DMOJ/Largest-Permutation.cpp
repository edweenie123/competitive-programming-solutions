/*
~~~ Largest Permutation ~~~ 

Key Concepts: Greedy Algorithms

Find the largest permutation you make with k swaps
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;
int n, k, arr[MAXN], ind[MAXN];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;

    for (int i=0;i<n;i++) {
        cin>>arr[i];
        ind[arr[i]] = i;
    }

    int next = n, tmp;
    for (int i=0;i<n;i++) {
        if (!k) break;
        if (arr[i]!=next) {
            tmp = arr[i];
            arr[i] = next;
            arr[ind[next]] = tmp;
            ind[tmp] = ind[next];
            ind[next] = i;
            k--;
        }
        next--;
    }

    for (int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }cout<<"\n";
}