/*
~~~ DMPG '18 S2 - Code Cracking Crisis ~~~

Key Concepts: Implementation

Reverse the encription method
*/
#include<bits/stdc++.h>
using namespace std;

string diary[10], encrp, decrp;

void decript() {
    decrp = encrp.substr(0, 1);
    for (int i=1;i<encrp.length();i++) {
        decrp += to_string(diary[stoi(decrp.substr(i-1, 1))].find(encrp.substr(i, 1)));
    }
}
int main() {
    for (int i=0;i<10;i++) cin>>diary[i];
    cin>>encrp;
    decript();
    cout<<decrp;
}