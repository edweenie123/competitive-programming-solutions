/*
~~~ CCC '96 S5 - Maximum Distance ~~~

Key Concepts: Brute Force

Simply look through all combinations of i and j and find the largest distance
*/

#include <bits/stdc++.h>
using namespace std;

int t, x[100000], y[100000], l;

int calcDist(int i, int j) {
    if (j>=i&&y[j]>=x[i]) return j-i;
    else return 0;
}

int maxDist() {
    int dist = 0;

    for (int i=0;i<l;i++) {
        for (int j=i+1;j<l;j++) {
            dist = max(dist, calcDist(i, j));
        }
    }

    return dist;
}

int main() {
    cin>>t;
    while(t--) {
        cin>>l;
        for (int i=0;i<l;i++) cin>>x[i];
        for (int i=0;i<l;i++) cin>>y[i];
        cout<<"The maximum distance is "<<maxDist()<<endl;
    }
}