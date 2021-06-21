/*
~~~ 466C - Number of Ways ~~~

Key Concepts: Implementation?, Ad-Hoc, PSA

The trick to to identify all the right borders and left borders

Both the right and left borders must encompass an area with a sum of total / 3

For every right border, we look at all the corresponding left borders
    and at 1 to the answer for each pair

We can do this quickly using a PSA

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5e5 + 5;

int n;
int arr[MAXN];
vector<int> rights; // stores all the possible right borders

int isLeft[MAXN];
int leftPSA[MAXN]; // psa for isLeftBorder

ll total;

void buildPSA() {
    leftPSA[0] = 0;

    for (int i=1;i<=n;i++) 
        leftPSA[i] = leftPSA[i-1] + isLeft[i];
}

ll solve() {
    // find all right borders
    ll cumSum = 0;
    for (int i=n;i>=1;i--) {
        cumSum += arr[i];

        if (cumSum == total/3)
            rights.push_back(i);
    }

    // find all left borders
    cumSum = 0;
    for (int i=1;i<=n;i++) {
        cumSum += arr[i];

        if (cumSum == total/3)
            isLeft[i] = 1;
    }

    buildPSA();

    ll cnt = 0;

    for (auto r : rights) {
        if (r-2 < 1) continue;
        cnt += leftPSA[r-2];
    } 

    return cnt;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    total = 0;
    for (int i=1;i<=n;i++) {
        cin>>arr[i];
        total += arr[i];
    }

    // the sum total must be divisible by 3
    if (total % 3 != 0) {
        cout<<"0\n";
        return 0;
    }

    ll ans = solve();

    cout<<ans<<"\n";
}