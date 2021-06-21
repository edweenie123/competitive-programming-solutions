#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int MAXW = 1e3 + 5;

int tc;
int n, k, w;
int psa[MAXN+MAXW];

int rangeSum(int l, int r) {
    return psa[r] - psa[l-1];
}

// returns the max score obtainable from pin idx->end w/ b balls 
int score(int idx, int b) {
    int best = 0;

    // assume all pins before idx are dead
    int str = idx - w;
    

}

int main() {
    cin>>tc;

    while(tc--) {
        cin>>n>>k>>w;
        // generate PSA for the pin points
        int point;
        psa[0] = 0;
        for (int i=1;i<=n;i++) {
            cin>>point;
            psa[i] = psa[i-1] + point;
        }
    }
}