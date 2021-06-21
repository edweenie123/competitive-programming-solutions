/*
~~~ GlobeX Cup '18 J2 - Mark Gambling ~~~

Key Concepts: Implementation

Simply check if more than half of the marks are greater than the average
*/
#include <bits/stdc++.h>
using namespace std;

int marks[100000];
int main() {
    int n, sum=0, cnt=0;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>marks[i];
        sum+=(float)marks[i];
    }
    float avrg = sum/(float)n;
    for (int i=0;i<n;i++) {
        if (marks[i]>avrg) cnt++;
    }
    if (cnt>n/2) cout<<"Winnie should take the risk";
    else cout<<"That's too risky";
}