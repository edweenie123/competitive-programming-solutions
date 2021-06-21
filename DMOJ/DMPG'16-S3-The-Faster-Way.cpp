/*
~~~ DMPG '16 S3 - The Faster Way ~~~ 

Key Concepts: Math, Implementation

Very simple Math problem (make #of passengers on rocket and normal trains as close as possible)
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+1;
int n, r, m, rocketAccess[MAXN];
ll ans = 0;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>r>>m;

    int stop;
    for (int i=0;i<r;i++) {
        cin>>stop;
        rocketAccess[stop] = 1;
    }

    ll rocketPassengers = 0;
    for (int i=0;i<m;i++) {
        cin>>stop;
        if (rocketAccess[stop]) rocketPassengers++;
    }
    
    if (rocketPassengers>m/2) rocketPassengers = m/2;

    ans += ((rocketPassengers+1)*rocketPassengers)/2;

    ll normalPassengers = m - rocketPassengers;
    ans += ((normalPassengers+1)*normalPassengers)/2;

    cout<<ans<<"\n";
}