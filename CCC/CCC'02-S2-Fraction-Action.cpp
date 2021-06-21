/*
~~~ CCC '02 S2 - Fraction Action ~~~

Key Concepts: Simple Math

*/

#include <bits/stdc++.h>

using namespace std;

int nu, de, whole;

int main() {
    cin>>nu>>de;

    whole = nu/de;

    if (whole*de==nu) {
        cout<<whole;
        return 0;
    }

    nu -= whole*de;

    int divisor=2;

    while (divisor<=nu) {
        if (nu%divisor==0&&de%divisor==0) {
            nu /= divisor;
            de /= divisor;
        }
        divisor++;
    }

    if (whole!=0)cout<<whole<<" ";
    cout<<nu<<"/"<<de<<endl;
}