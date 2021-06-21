// Solved!
#include <bits/stdc++.h>
using namespace std;

int main () {
    while (true) {
        int n;
        cin>>n;
        if (n==0) break;
        int sum = 0;
        for (int i=n; i>0; i--) {
            sum += i*i;
        }
        cout<<sum<<endl;
    }
}