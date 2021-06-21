/*
~~~ 276C - Little Girl and Maximum Sum ~~~

Key Concepts: Difference array, Intuition

Insight #1:
If we want to maximize the sum of the queries...
    the index that is included in the most ranges should have the largest element

Insight #2: 
We can use a difference array to find out how many times each index is included in a range quickly
    - since each query basically adds 1 to a range

With these two insights, we just simply sort the array and greaters value to the most frequent index

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;

int n, q;

ll freq[MAXN];
ll dif[MAXN];
vector<ll> allFreq;
vector<ll> arr;

void rangeUpdate(int l, int r, int amt) {
    dif[l] += amt;
    dif[r+1] -= amt;
} 

void reconstruct() {
    
    for (int i=1;i<=n;i++) 
        freq[i] = freq[i-1] + dif[i];
    
    for (int i=1;i<=n;i++)
        allFreq.push_back(freq[i]);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;

    ll tmp;
    for (int i=0;i<n;i++) 
        cin>>tmp, arr.push_back(tmp);   
    
    int l, r;
    for (int i=0;i<q;i++) {
        cin>>l>>r;
        rangeUpdate(l, r, 1);
    }

    reconstruct();

    sort(allFreq.begin(), allFreq.end(), greater<ll>());
    sort(arr.begin(), arr.end(), greater<ll>());

    ll ans = 0;

    for (int i=0;i<n;i++) 
        ans += arr[i] * allFreq[i];
    

    cout<<ans<<"\n";
}