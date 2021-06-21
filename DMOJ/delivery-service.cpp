#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
const int MAXD = 1e5+1;

int d, n, p; // length, init fuel, #planets w/ fuel
int fuels[MAXD], ssa[MAXD]; // suffix sum array (ssa[i] = sum(i->end))
void x1() {
    cin>>d>>n>>p;

    int qi, ri;
    for (int i=0;i<p;i++) {
        cin>>qi>>ri;
        fuels[qi] = ri;
    }

    ssa[d] = 1;

    for (int i=d-1;i>0;i--) {
        int lastPlanet = min(i+fuels[i], d);
        int paths = ((ssa[i+1]%MOD)-(ssa[lastPlanet+1])%MOD)%MOD;
        ssa[i] = ((ssa[i+1]%MOD)+(paths)%MOD)%MOD;
    }

    int ans = ssa[1] - ssa[n+1];
    cout<<ans;
}

void x2() {

}

int main() {
    int x; cin>>x;
    if (x==1) x1();
    else x2();
}