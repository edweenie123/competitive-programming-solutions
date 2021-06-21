#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("ECOO2018/Round 1/DATA/DATA12.txt", "r", stdin);
    
    for (int test=0;test<10;test++) {
        int t, n;
        cin>>t>>n;

        int daysLeft = 0;
        for (int d=0;d<n;d++) {
            string l;
            cin>>l;
            if (l=="E") daysLeft=max(daysLeft-1, 0);
            else daysLeft+=t-1;
        }
        cout<<daysLeft<<endl;
    }
}