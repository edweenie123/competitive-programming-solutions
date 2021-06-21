/*
~~~ 777D - Cloud of Hashtag ~~~

Key Concepts: Greedy, BS

Very ez problem imo

Its very easy to see the greedy solution
    for every hashtag, we delete the least # of letters to make it lexicographically less than the next one

    Use binary search to speed up the process

*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define first f
#define second s

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 5e5 + 5;
const ll MOD = 1e9 + 7;

int n;
string arr[MAXN];

int bs(string s, string last) {

    int lo = 1, hi = s.length(), mid, best;

    while (lo<=hi) {
        mid = (lo + hi) / 2;

        string res = s.substr(0, mid);

        if (res <= last) {
            best = mid;
            lo = mid + 1;
        } else 
            hi = mid - 1;
    }

    return best;
}

void solve() {
    cin>>n;

    for (int i=1;i<=n;i++) {
        cin>>arr[i];
    }

    string last = arr[n]; 
    for (int i=n-1;i>=0;i--) {
        if (arr[i] > last) {
            int newLen = bs(arr[i], last);
            arr[i] = arr[i].substr(0, newLen);
        }
        last = arr[i];
    }

    for (int i=1;i<=n;i++) 
        cout<<arr[i]<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}