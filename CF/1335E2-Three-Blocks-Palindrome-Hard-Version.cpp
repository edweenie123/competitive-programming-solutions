/*
~~~ 1335E2 - Three Blocks Palindrome (Hard Version) ~~~

Key Concepts: Two pointer, BF

The two pointer idea + BF is pretty simple and i came up with it pretty fast

HOWEVER, im stupid cause i thought the time complexity was O(AL*n*AL)
    were AL is the maximum value of a

so i kept on thinking of alternative solutions 

but after reading the editorial and thinking a bit:

    I realize that the time complexity is actually O(n*AL)

    So it would actually pass

*/




#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 2e5;
const int MAXA = 200;
const ll MOD = 1e9 + 7;

int psa[MAXA+5][MAXN+5];
vector<int> idx[MAXA+5];
int arr[MAXN+5];

void solve() {
    int n;
    cin>>n;

    for (int i=0;i<=MAXA;i++) idx[i].clear();

    for (int i=1;i<=n;i++) {
        cin>>arr[i];

        for (int j=1;j<=MAXA;j++)
            psa[j][i] = psa[j][i-1] + (j==arr[i]);
        
        idx[arr[i]].push_back(i);
    }

    int ans = 0;

    for (int o=1;o<=MAXA;o++) { // outer 

        // edge case only take one type
        ans = max(ans, psa[o][n]);

        for (int k=1;k<=idx[o].size()/2;k++) {

            int left = idx[o][k-1] + 1;
            int right = idx[o][idx[o].size() - k] -1;

            for (int m=1;m<=MAXA;m++) { // middle

                int pot = 2*k + psa[m][right] - psa[m][left-1];

                ans = max(ans, pot);
            }

        }
    }

    cout<<ans<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        solve();
    }
}