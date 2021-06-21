/*
~~~ 1362B - Johnny and His Hobbies ~~~

Key Concepts: Brute Force, Bitmasks

Very easy BF problem, just try all possible values of K

*/


#include<bits/stdc++.h>
using namespace std;

#define print(x) cout<<(#x)<<" = "<<x<<"\n";
typedef long long ll;
int n;

vector<int> arr;
set<int> bois;

ll solve() {
    bois.clear();
    for (int j=0;j<n;j++) {
        bois.insert(arr[j]);
    }

    for (int i=1;i<1024;i++) {

        for (int j=0;j<n;j++) {
            int change = arr[j] ^ i;

            if (bois.count(change)) {
                bois.erase(change);

                if (j == n-1)
                    return i;
            } else {
                break;
            }

        }

        bois.clear();
        for (int j=0;j<n;j++) {
            bois.insert(arr[j]);
        }
    }

    return -1;

}

int main() {
    int TC; cin>>TC;

    while (TC--) {
        arr.clear();
        cin>>n;

        int tmp;
        for (int i=0;i<n;i++) {
            cin>>tmp;
            arr.push_back(tmp);
        }

        ll ans = solve();
        cout<<ans<<"\n";
    }
}