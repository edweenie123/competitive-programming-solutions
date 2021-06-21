/*
~~~ Prime Factorization ~~~ Prime

Key Concepts: Math


*/

#include <bits/stdc++.h>
using namespace std;

// const int MAXN = 1e7 + 1;
int n;

int main() {
    cin>>n;
    int m;
    for (int i=0;i<n;i++) {
        cin>>m;

        for (int i=2;i*i<=m;i++) {
            while (m%i==0) {
                cout<<i<<" ";
                m/=i;
            }
        }

        if (m>1) cout<<m;

        cout<<"\n";
    }
}