#include <bits/stdc++.h>
using namespace std;

int n, ren;
int main() {
    cin>>n>>ren;
    int strong = 0, tmp;
    for (int i=1;i<n;i++) {
        cin>>tmp;
        strong = max(strong, tmp);
    }
    cout<<(ren>strong?"YES":"NO")<<"\n";
}