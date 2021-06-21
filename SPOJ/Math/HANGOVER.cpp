// Key Concepts: Math

#include <bits/stdc++.h>
using namespace std;

int cards(double dist) {
    double count = 1;
    double curDist = 0;
    while (true) {
        curDist += 1/(count+1);
        if (curDist>=dist) break;
        count++;
    }
    return count;
}
int main() {
    while (true) {
        double k;
        cin>>k;
        if (k==0.00) break;
        cout<<cards(k)<<" card(s)"<<endl;

    }
}