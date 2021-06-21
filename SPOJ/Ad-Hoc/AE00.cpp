// Solved!
#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin>>n;

    int count=0;
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            if (i*j > n) break;
            count += 1;
        }
    }
    cout<<count<<endl;
}