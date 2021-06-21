/*
~~~ DMOPC '14 Contest 2 P4 - Deforestation ~~~

Key Concepts: PSA

Use PSA array to compute queries in O(1)

*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+1;
int psa[MAXN];
int n, q;

int query(int a, int b) {
    return psa[b] - psa[a-1];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    int tmp;

    cin>>tmp;
    psa[0] = tmp;

    for (int i=1;i<n;i++) {
        cin>>tmp;
        psa[i] = psa[i-1] + tmp;
    } 

    cin>>q;
    int a, b;
    for (int i=0;i<q;i++) {
        cin>>a>>b;
        cout<<query(a, b)<<"\n";
    }       
}