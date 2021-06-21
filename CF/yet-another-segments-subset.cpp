#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 3e3 + 1;
const ll MOD = 1e9 + 7;

int n;
int cordl[MAXN];
int cordr[MAXN];

vector<int> rights[MAXN*2];

void solve() {
    cin>>n;

    int l, r;
    vector<int> cords;
    for (int i=0;i<n;i++) {
        cin>>l>>r;
        cordl[i] = l;
        cordr[i] = r;

        cords.push_back(l);
        cords.push_back(r);
    }

    sort(cords.begin(), cords.end());
    // removes duplicate elements somehow
    cords.erase(unique(cords.begin(), cords.end()), cords.end()); 

    for (int i=0;i<n;i++) {
        
        // get the compressed coordinates
        int compL = lower_bound(cords.begin(), cords.end(), cordl[i]) - cords.begin();
        int compR = lower_bound(cords.begin(), cords.end(), cordl[i]) - cords.begin();

        rights[compL].push_back(compR);
    }

}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        solve();
    }
}