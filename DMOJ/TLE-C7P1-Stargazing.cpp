// Key Concepts: Implementation

#include <bits/stdc++.h>
using namespace std;

set < array<int, 2> > starPosU = {{0, 0}};
vector < array<int, 2> > starPos = {{0, 0}};
int main() {
    int n;
    cin>>n;

    for (int i=0;i<n-1;i++) {
        int p, relX, relY;
        cin>>p>>relX>>relY;

        int x = starPos[p-1][0] + relX;
        int y = starPos[p-1][1] + relY;
        array<int, 2> pos = {x,y};
        starPos.push_back(pos);
        starPosU.insert(pos);
    }
    cout<<starPosU.size()<<endl;
}