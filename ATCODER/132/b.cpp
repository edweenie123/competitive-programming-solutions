#include <bits/stdc++.h>
using namespace std;

int n;
int arr[30];
int main() {
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int cnt = 0;
    for (int i=1;i<n-1;i++) {
        int l = arr[i-1], r = arr[i+1], c = arr[i];
        if (c>l&&c>r||c<l&&c<r) continue;
        cnt++;
    }
    cout<<cnt;
}