/*
~~~ 294B - Shaas and Bookshelf ~~~

Key Concepts: Brute Force, greedy

Let t1 = # of books of thickness 1 in the bottom
Let t2 = # of books of thicness 2 in the bottom

Insight 1:
Since we want to fit all the top books on the bottom books
    -> we always put the t1 books with the longest width at the bottom
    -> same thing with t2

Insight 2:
Since n is so small, we can brute force over all possible combinations of t1 and t2
    -> we use a PSA to determine the total width of the remaining books


*/



#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;

int n;

vector<int> w1;
vector<int> w2;

int w1PSA[MAXN];
int w2PSA[MAXN];

int rsq(int l, int r, int* psa) {
    return psa[r] - psa[l-1];
}

int main() {
    cin>>n;

    int t, w;
    for (int i=0;i<n;i++) {
        cin>>t>>w;

        if (t==1) w1.push_back(w);
        else      w2.push_back(w);
    }
    
    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());

    for (int i=1;i<=w1.size();i++) w1PSA[i] = w1PSA[i-1] + w1[i-1];
    for (int i=1;i<=w2.size();i++) w2PSA[i] = w2PSA[i-1] + w2[i-1];

    int ans = 1e9;

    for (int t1=0;t1<=w1.size();t1++) {
        for (int t2=0;t2<=w2.size();t2++) {

            int totalThicc = t1 + t2 * 2;

            int totalWidth = w1PSA[w1.size() - t1] + w2PSA[w2.size() - t2];

            if (totalWidth <= totalThicc)
                ans = min(ans, totalThicc);
        }
    }

    cout<<ans<<"\n";

}