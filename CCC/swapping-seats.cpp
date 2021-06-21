/*
~~~ CCC '20 S4 - Swapping Seats ~~~

Key Concepts: Greedy PSA




*/




#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl;
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;


int n;
string str;
int psa[3][MAXN];
int freq[3];

int rsq(int l, int r, int t) {
    return psa[t][r] - psa[t][l-1];
}

int allCycle(ii r[]) {

    int minSwap = 1e9;

    for (int i=0;i<n;i++) {
        int wrongA, bina;
        int wrongB, ainb;

        if (r[0].f > r[0].s) {
            wrongA = freq[0] - rsq(r[0].f, n, 0) - rsq(1, r[0].s, 0);
            bina = rsq(r[0].f, n, 1) + rsq(1, r[0].s, 1);
        } else {
            wrongA = freq[0] - rsq(r[0].f, r[0].s, 0);
            bina = rsq(r[0].f, r[0].s, 1);
        }

        if (r[1].f > r[1].s) {
            wrongB = freq[1] - rsq(r[1].f, n, 1) - rsq(1, r[1].s, 1);
            ainb = rsq(r[1].f, n, 0) + rsq(1, r[1].s, 0);
        } else {
            wrongB = freq[1] - rsq(r[1].f, r[1].s, 1);
            ainb = rsq(r[1].f, r[1].s, 0);
        }

        int swaps = wrongA + wrongB - min(ainb, bina);
        minSwap = min(swaps, minSwap);
       
        // rotate
        for (int j=0;j<3;j++) {
            r[j] = {r[j].f+1, r[j].s+1};
            if (r[j].f>n) r[j].f = r[j].f % n;
            if (r[j].s>n) r[j].s = r[j].s % n;
        }

    }

    return minSwap;
}


void solve() {
    cin>>str;
    n = str.length();

    str = " " + str; // dummy val


    for (int i=1;i<=n;i++) {
        freq[str[i]-'A']++;
        
        for (int j=0;j<=2;j++) {
            psa[j][i] = psa[j][i-1] + ((str[i]-'A')==j);
        }
    }

    ii tar1[3] = {{1, freq[0]}, {freq[0]+1, freq[0]+freq[1]}, {freq[0]+freq[1]+1, n}};
    ii tar2[3] = {{freq[2]+freq[1]+1, n}, {freq[2]+1, freq[2]+freq[1]}, {1, freq[2]}};

    int ans = min(allCycle(tar1), allCycle(tar2));

    cout<<ans<<endl;    
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}