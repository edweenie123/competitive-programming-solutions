/*
~~~ MWC '15 #2 P2: Towering Towers ~~~

Key Concepts: Stacks

The stack only contains the towers which actually matter
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
int n;
stack<ii> s;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    s.push(ii(0, 1e9));
    for (int i=0;i<n;i++) {
        int b; cin>>b;
        while (true) {
            if (s.top().second>b||s.empty()) break;
            s.pop();
        }

        cout<<i-s.top().first<<" ";
        s.push(ii(i, b));
    }
}