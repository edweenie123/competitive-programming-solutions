/*
~~~ DMPG '19 S1 - Candy Shop Tycoon ~~~

Key Concepts: Brute force

Simple brute force to check if it is possible to achieve C candies
*/
#include <bits/stdc++.h>
using namespace std;

int a, b, c, g, cnt;

bool possible() {
    for (int i=0;i<101;i++) {
        for (int j=0;j<101;j++) {
            for (int k=0;k<101;k++) {
                cnt = i*a+b*j+c*k;
                if (cnt==g)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cin>>a>>b>>c>>g;
    possible() ? cout<<"QUEST CLEARED" : cout<<"TRY AGAIN";
}