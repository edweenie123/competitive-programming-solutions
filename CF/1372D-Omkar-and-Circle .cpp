/*
~~~ 1372D - Omkar and Circle ~~~

Key Concepts: Games?, PSA

Pretty weird problem

The main idea realize that if you want to keep a group (you don't delete it)
    then you have to combine it with elements that are two away from the group

    ie you can't combine adjacent groups

I think this is best explained using an example...

Lets say you have 9 elements; so the indices of the elements look like this:

1, 2, 3, 4, 5, 6, 7, 8, 9

Lets combine the 1 and the 3 at the beginning so it becomes

1+3, 4, 5, 6, 7, 8, 9

Notice that if we want to continue adding the the 1+3 group, it has to be 5, so it becomes

1+3+5, 6, 7, 8, 9

Eventually it becomes:

1+3+5+7+9

What happens if we start at 3 instead? We get the group:

3+5+7+9+2

Start at 5?:

5+7+9+2+4

Essentially, in the sequence:

1, 3, 5, 6, 8, 9, 2, 4, 6, 8

We choose a subarray of size (n+1)/2:
    Thus we want to maxmize the sum of this subarray, which we can do quickly with psa

*/



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const int MAXN = 2e5 + 5;

set<ii> vals;
set<ii> idxs;

int arr[MAXN];

int pat[MAXN * 2];
ll psa[MAXN * 2];

ll solve() {
    int n;
    cin>>n;

    for (int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    // create this sequence 1, 3, 5, 7, 9,..., n, 2, 4, 6, 8,...,n-1

    for (int i=1, idx=1;i<=(n+1)/2;i++, idx+=2) {
        pat[i] = pat[i+n] = arr[idx];
    }

    for (int i=(n+1)/2+1, idx = 2;i<=n;i++, idx+=2) {
        pat[i] = pat[i+n] + arr[idx];
    }

    // find largest subarray of size (n+1)/2 in the sequence

    for (int i=1;i<=2*n;i++) {
        psa[i] = psa[i-1] + pat[i];
    }

    ll ans = 0;
    for (int i=1;i<=2*n;i++) {
        if (i+(n+1)/2-1 > 2*n) break;
        ll rsq = psa[i+(n+1)/2-1] - psa[i-1];
        ans = max(ans, rsq);
    }

    return ans;
    
}

int main() {
    
    ll ans = solve();
    cout<<ans<<"\n";
    
}