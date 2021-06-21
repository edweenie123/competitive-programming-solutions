/*
~~~ 1382D - Unmerge ~~~

Key Concepts: Insight, DP

The entire problem revolves under 1 insight 
    which leads to the dp classic subset sum problem

Insight 1:
Consider the sequence,
    6 3 5 2 1 9 7 8 4 10

    If we put the 6 in group A, our groups look like:

        A: 6, _, _, _, _, _
        B: >6, _, _, _, _, _

    Notice that the first element of B must be greater than 6 for us to pick 6 first

    Since the first element of B is greater than 6, 
        the subarray [3, 5, 2, 1] must be in the same group as 6

        IE: whatever group t he 6 is in, [3, 5, 2, 1] has to be right after it

        Thus we can treat [6, 3, 5, 2, 1] as a single unit
    
    We can use very similar logic to find that:
        whatever group 9 is in, [7, 8, 4] must also be in the same group

    Thus, we separate our list into groups each w/ its own size:
        [6, 3, 5, 2, 1], [9, 7, 8, 4], [10]

Insight 2:
Since we need to make 2 lists of size n:
    We simply need to check if we can select groups in a way
        such that the total # of elements in the list is n
    
    This is identical to the classic subset sub dp problem
        which can be solved in O(n*sum)

*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define first f
#define second s

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 4e3 + 5;
const ll MOD = 1e9 + 7;

int arr[MAXN];
vector<int> groupSz;
int dp[MAXN][MAXN];

bool isPos(int idx, int sz) {
    if (idx==groupSz.size()) 
        return sz==0;
    
    if (dp[idx][sz] != -1) return dp[idx][sz];

    bool skip = isPos(idx+1, sz);
    bool take = isPos(idx+1, sz-groupSz[idx]);

    return dp[idx][sz] = skip | take;
}


void solve() {
    int n;
    cin>>n;
    groupSz.clear();
    for (int i=0;i<=2*n;i++) 
        for (int j=0;j<=2*n;j++)
            dp[i][j] = -1;
    
    for (int i=1;i<=2*n;i++) {
        cin>>arr[i];
    }

    int sz = 1;
    int large = arr[1];

    for (int i=2;i<=2*n;i++) {
        if (arr[i] < large) {
            sz++;
        } else {
            groupSz.push_back(sz);
            sz = 1;
            large = arr[i];
        }
    }

    if (isPos(0, n)) 
        cout<<"YES\n"; 
    else 
        cout<<"NO\n";
    
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        solve();
    }
}