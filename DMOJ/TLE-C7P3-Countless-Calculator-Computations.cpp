// Key Concepts: Binary Search

#include <iostream>
#include <math.h>
using namespace std;

int q, y;
long z;

double ans;
bool powers(double x) {
    ans = x;
    for (int i=1;i<y;i++) {
        ans = pow(x, ans);
        if (ans>=z) return true;
    }
    return false;
}

double low, high, mid;
void bs() {
    low = 0, high = 10e6;
    while (low<high) {
        mid = (low+high)/2;
        if (powers(mid/1e6)) high = mid;
        else low = mid+5;
    }
    cout<<mid/1e6<<"\n";
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>q;
    while (q--) {
        cin>>y>>z;
        bs();    
    }
}