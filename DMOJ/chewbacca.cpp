/*
~~~ COCI '15 Contest 4 #4 Chewbacca ~~~

Key Concepts: Tree

Find the distance between 2 vertices in a k-node tree

We repeatedly find the parent of the greater vertice until we traverse to a common ancestor

Key formula: parent of k-node tree = ceil((n-1) / k)
*/

#include <bits/stdc++.h>
using namespace std;

long long n, k, q;

long long parent(long long num) {
    return (num-1) / k + ((num-1)%k!=0);
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>q;
    for (int i=0;i<q;i++) {
        long long x, y; cin>>x>>y;
        if (k==1) cout<<abs(x-y)<<endl;
        else {
            int dist = 0;
            while (true) {
                if (x==y) break;
                dist++;
                if (x>y) x = parent(x);
                else y = parent(y);
            }

            cout<<dist<<endl;
        }
        
    }
}