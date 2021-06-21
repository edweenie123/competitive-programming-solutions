#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];

bool checkSame(int k) {
    int lo = 0, hi = n, mid;
    int best = -1;
    while(lo<=hi) {
        mid = (lo+hi)/2;
        if (arr[mid]>=k) {
            hi = mid - 1;
            best = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (best==n/2) return true;
    else return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for (int i=0;i<n;i++) cin>>arr[i];
    sort(arr, arr+n);

    int cnt = 0;
    for (int i=0;i<=100000;i++) 
        if (checkSame(i)) cnt++;

    cout<<cnt;
}