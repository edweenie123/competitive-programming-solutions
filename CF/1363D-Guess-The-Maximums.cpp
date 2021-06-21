/*
~~~ 1363D - Guess The Maximums ~~~

Key Concepts: BS, Interactive

Insight 1: 
Let mx = max(A)

If no subsets contain an index with the max element 
    -> all elements in the password is mx

Insight 2:
If there is a subset containing the index w/ the max element => kth subset
    -> all elements in the password is mx EXCEPT for the kth one
    -> we can perform a query to determine what the kth element should be

Insight 3:
We can use binary search to determine which subset has the index with the max element
    -> this results in the least possible amount of queries

Query Count:
    - 1 to determine max element in A
    - <= 10 to determine which subset has the max value (log2(1000))
    - 1 to determine the element in the password for the max element subset

Note: it doesn't matter if the mv appears more than once in the array
    -> everything still works

*/


#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int MAXN = 1e3 + 5;

int n, k;
vi subsets[MAXN];
int maxVal;

int query(vi q) {
    cout<<"? "<<q.size()<<" ";
    for (auto e : q) cout<<e<<" ";
    cout<<"\n"; cout.flush();

    int ret; cin>>ret;
    return ret;
}

// bs for the index of the subset which contains the max element
int bs() {
    int lo = 0, hi = n-1, mid, ans = 0;

    int val;

    while (lo<=hi) {
        mid = (lo + hi) / 2;
        vi left;
        
        for (int i=0;i<=mid;i++)
            for (auto idx : subsets[i])
                left.push_back(idx);
        
        val = query(left);

        if (val==maxVal) { // maxVal is in the left
            hi = mid - 1;
            ans = mid;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

void solve() {
    // find max element in the array
    vi allIdx; for (int i=1;i<=n;i++) allIdx.push_back(i);
    maxVal = query(allIdx);

    // find a subset w/ the max element
    int maxSubset = bs();

    // query for the max element not in the maxSubset
    set<int> included; for (auto v : subsets[maxSubset]) included.insert(v);
    vi notInMax;
    for (int i=1;i<=n;i++) {
        if (included.count(i)) continue;
        notInMax.push_back(i);
    }

    // get the password for the max subset
    int maxValAlt; maxValAlt = query(notInMax);
    
    // output the answer
    cout<<"! ";
    for (int i=0;i<k;i++) {
        if (i == maxSubset) cout<<maxValAlt<<" ";
        else cout<<maxVal<<" ";
    }
    cout<<"\n"; cout.flush();
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        for (int i=0;i<MAXN;i++) subsets[i].clear();
        cin>>n>>k;

        int c, idx;
        for (int i=0;i<k;i++) {
            cin>>c;

            for (int j=0;j<c;j++) 
                cin>>idx, subsets[i].push_back(idx);
        }

        solve();
        
        string res;
        cin>>res;
        if (res=="Incorrect")
            return 0;
    }    
}