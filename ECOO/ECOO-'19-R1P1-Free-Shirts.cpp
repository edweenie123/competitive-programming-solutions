#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests = 10, n, m, d, temp;
    multiset<int> eve;
    while (tests--) {
        cin>>n>>m>>d;
        eve.clear();
        int cnt = 0, clean = n;
        for (int i=0;i<m;i++) {
            cin>>temp;
            eve.insert(temp);
        }
        for (int i=0;i<d;i++) {
            if (clean<=0) {
                cnt++;
                clean = n;
            }
            int events = eve.count(i+1);
            clean += events;
            n += events;
            
            clean--;
        }
        cout<<cnt<<endl;
    }
}