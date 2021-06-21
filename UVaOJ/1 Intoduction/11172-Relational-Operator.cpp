/*
~~~ UVa 11172 - Relational Operator ~~~

Extremely simple implementation
*/

#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
    cin>>t;
    int a, b;
    while(t--) {
        cin>>a>>b;
        if (a>b) cout<<">";
        else if (a<b) cout<<"<";
        else cout<<"=";
        cout<<endl;
    }
}