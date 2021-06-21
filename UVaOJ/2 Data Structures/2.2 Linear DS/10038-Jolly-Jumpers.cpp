/*
~~~ UVa 10038 - Jolly Jumpers ~~~

Key Concepts: Arrays

Use 1D boolean flags to store differences
*/

#include <bits/stdc++.h>

using namespace std;

bool flags[3001];
int n;
int arr[3001];

bool isJolly() {
    for (int i=0;i<n-1;i++) {
        int dif = abs(arr[i]-arr[i+1]);
        if (dif>n-1) return false;
        flags[dif]=1;
    }

    for (int i=1;i<n;i++) {
        if (!flags[i]) return false;
    } 
    return true;
}

int main() {
    while (cin>>n) {  
        memset(flags, 0, sizeof(flags));
        for (int i=0;i<n;i++) cin>>arr[i];

        isJolly() ? cout<<"Jolly" : cout<<"Not jolly";
        cout<<endl;
    }
}