#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MAXI = 1e6 + 5;

// A1 = jeffrey's g sequence, A2 = leo's g sequence 

int n1, n2;            // #'s of g strings  
int a1[MAXN];          // jeffrey's g sequence
int idxA2[MAXI];       // a2Idx[i] stores index of i within A2
int idxA1inA2[MAXN];   // idxA1inA2[i] stores the index of A1[i] within A2 
int L[MAXN];           // used in LIS n log n alg

int LIS(int A[], int lenA) {
    int lenLIS = 0, pos;

    for (int i=0;i<lenA;i++) {
        pos = lower_bound(L, L + lenLIS, idxA1inA2[i]) - L;
        L[pos] = idxA1inA2[i];

        if (pos+1>lenLIS)
            lenLIS++;
    }
    return lenLIS;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>n1;
    for (int i=0;i<n1;i++) cin>>a1[i];

    cin>>n2;
    memset(idxA2, -1, sizeof(idxA2));
    for (int i=0;i<n2;i++) {
        int elem; cin>>elem; 
        idxA2[elem] = i;
    }

    int idx = 0;
    for (int i=0;i<n1;i++) {
        if (idxA2[a1[i]]==-1) continue;

        idxA1inA2[idx] = idxA2[a1[i]];
        ++idx;
    }

    int ans = LIS(idxA1inA2, idx);
    cout<<ans<<"\n";
}