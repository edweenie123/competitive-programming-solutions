/*
~~~ Back To School '19: Chemistry ~~~

Key Concepts: yucky, Long double
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

long double n, m;
int main() {
    cin>>n>>m;
    long double q = ceil(log2(n));
    ll ans = ceil(q / m);
    cout<<ans<<"\n";
}