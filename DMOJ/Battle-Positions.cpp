/*
~~~ Battle Positions ~~~

Key Concepts: Difference Array

Use difference array data structure to perform range updates in O(1)
*/

#include <bits/stdc++.h>

using namespace std;

int i, n, j, difArr[100001], arr[100001];
int main() {
    cin>>i>>n>>j;

    int l, r, k;
    for (int w=0;w<j;w++) {
        cin>>l>>r>>k;
        difArr[l-1]+=k;
        difArr[r]-=k;
    }
    int cnt = 0;
    arr[0] = difArr[0]; 
    if (arr[0]<n) cnt++;

    for (int s=1;s<i;s++) {
        arr[s] = arr[s-1]+difArr[s];
        if (arr[s]<n) cnt++;            
    }

    cout<<cnt;
}