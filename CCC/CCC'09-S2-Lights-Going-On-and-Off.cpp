/*
~~~ CCC '09 S2 - Lights Going On and Off ~~~ 

Key Concepts: Brute Force / Implementation

Apply the XOR function to your current row and all possible values of the previous row
*/
#include <bits/stdc++.h>
using namespace std;

int r, l, initVal[30];
set<int> posVal[30];

int binToDec(string b) {
    int add = 1, res = 0;

    for (int i=b.length()-1;i>=0;i--) {
        res += ((int)b[i]-48)*add;
        add = add << 1;
    }
    return res;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>r>>l;

    string bit;
    for (int i=0;i<r;i++) {
        string bin = "";
        for (int j=0;j<l;j++) {
            cin>>bit;
            bin += bit;
        }
        int num = binToDec(bin);
        posVal[i].insert(num);
        initVal[i] = num;
    }

    for (int i=1;i<r;i++) {
        for (auto v : posVal[i-1]) {
            posVal[i].insert(initVal[i] ^ v);
        }
    }

    cout<<posVal[r-1].size()<<"\n";
}