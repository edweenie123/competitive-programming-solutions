// Key Concepts: Implementation

#include <bits/stdc++.h>
using namespace std;

int main() {
    long double n,m,a;
    cin>>n>>m>>a;
    long long int ans = ceil(n/a)*ceil(m/a);
    cout<<ans<<endl;
}