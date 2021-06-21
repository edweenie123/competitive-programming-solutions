/*
~~~ 1334C - Circle of Monsters ~~~

Key Concepts: PSA, Brute force

Insight 1:
We can kill all the monsters from a left to right fashion
    -> if we shoot the ith monster dead and lets say the chain reaction kills K monsters
        this means that the next monster will must shoot is the i + kth monster
            this is because there is no way an explosion can kill it 

Insight 2:
If we fix our which monster will kill first -> we can find the optimal # of bullets to kill the rest
    because of insight 1

Implemented naively this leads to an O(n^2) solution
    -> We need to iterate through n possible starting points
        and each iteration takes O(n) 

At this point i had to look at the editorial cause im too dumb

Insight 3:
We can compute each iteration in O(1) using a PSA!

    Let c[i] = max(0, a[i] - b[i-1])

        c[i] stores the # of bullets we need to kill monster i assuming the last one exploded
    
            -> Because we go through the monsters left to right, this assumption is always right
    
    Therefore we can simply make a psa for c and do a rsq to find the min number of bullets 
        for each iteration

*/




#include<bits/stdc++.h>
using namespace std;

#define print(x) cout<<(#x)<<" = "<<(x)<<"\n";
typedef long long ll;
const int MAXN = 3e5 * 2 + 5;

int n;
ll a[MAXN], b[MAXN];
ll c[MAXN], psaC[MAXN];


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        cin>>n;

        for (int i=1;i<=n;i++) cin>>a[i]>>b[i];

        for (int i=n+1;i<=2*n;i++)
            a[i] = a[i-n], b[i] = b[i-n];

        for (int i=1;i<=2*n;i++)
            c[i] = max(0ll, a[i] - b[i-1]);

        for (int i=1;i<=2*n;i++) 
            psaC[i] = psaC[i-1] + c[i];

        ll ans = 1e18;
        for (int i=1;i<=n;i++) {
            ll pot = a[i] + psaC[i+n-1] - psaC[i];
            ans = min(ans, pot);
        }

        cout<<ans<<"\n";
    }
}