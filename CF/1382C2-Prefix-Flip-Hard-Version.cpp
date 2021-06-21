/*
~~~ 1382C2 - Prefix Flip (Hard Version) ~~~

Key Concepts: Meet in the middle? Constructive Algorithms

I will describe allen's solution because it is more educational
    -> my solution was kinda yucky    
        I found a pattern for the element in the first index

Insight 1:
We can turn string A into 000000000....0 in at most N operations
    -> pretty obvious constructive algorithm to do this, figure it out

    Our goal now is to turn 00000000...0 into B

Insight 2:
Instead of turning 000000.0 into B, what if we tried turning B into 00000.00
    -> this again can be done in at most N operations

    KEY: if we reverse the operations we used to turn B into 0000000..0
        we can turn 000000...0 into B

        This works because each operation is "reflective":
            performing the same operation 2 times will leave you with the original string

*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define first f
#define second s

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;

int arra[MAXN];
int arrb[MAXN];

// int extra[MAXN];
vector<int> ans;


void solve() {
    int n;
    cin>>n;
    ans.clear();
    // fill(extra, extra + n + 5, 0);

    string a, b;
    cin>>a>>b;

    a = ' ' + a;
    b = ' ' + b;

    for (int i=1;i<=n;i++) {
        if (a[i]=='1') arra[i]=1;
        else arra[i] = 0;

        if (b[i]=='1') arrb[i]=1;
        else arrb[i] = 0;
    }

    int oper=0;
    
    for (int i=n;i>=1;i--) {
        int idx;
        if (oper%2==0) {
            idx = oper/2 + 1;
        } else {
            idx = n - oper/2;
        }

        int elem = arra[idx];

        if (oper%2==1) {
            elem = !elem;
        }

        if (elem == arrb[i]) {
            ans.push_back(1);
        }

        ans.push_back(i);
        oper++;
    }

    cout<<ans.size()<<" ";

    for (auto an : ans) {
        cout<<an<<" ";
    } cout<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        solve();
    }
}