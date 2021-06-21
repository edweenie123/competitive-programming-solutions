// Key Concepts: Implementation
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        if (str.length()>10) {
            cout<<str[0]<<str.length()-2<<str.back();
        } else cout<<str;
        cout<<endl;
    }
}