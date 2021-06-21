/*
~~~ VMSS '15 #1 - Senpai, Help Me ~~~

Key Concepts: Simple Math
*/

#include<bits/stdc++.h>
using namespace std;

int a;
int main() {
    cin>>a;

    int x, y, min = 1e8;
    for (int i=1;i<=a;i++) {
        if (a%i==0) {
            if (abs(i-(a/i))<min) {
                x = i, y = a/i;
                min = abs(x-y);
            }
        }
    }

    cout<<2*(x+y);
}