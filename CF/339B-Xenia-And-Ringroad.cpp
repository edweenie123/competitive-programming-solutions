// Solved!
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    long long tu = 0;
    int cur = 1;
    for (int i=0;i<m;i++) {
        int t;
        cin>>t;
        if (t>=cur) tu += t-cur;
        else tu += n-(cur-t);
        cur = t;
    } 
    cout<<tu<<endl;
}