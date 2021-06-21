/*
~~~ DMPG '18 S2 - Mimi and K-uteness ~~~

Key Concepts: Prefix Sum

Notice the relationship between the sum of k-arrays and k+1-arrays
*/

#include <bits/stdc++.h>
using namespace std;

long long ps[200001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>ps[i];
        ps[i] += ps[i-1];
    }
   
    long long sum=0;
    for (int k=1;k<=n;k++) {
        sum += ps[n-k+1] - ps[k-1];
        cout<<sum<<endl; 
    }
}
