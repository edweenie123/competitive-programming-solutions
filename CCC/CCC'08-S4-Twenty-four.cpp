/*
~~~ CCC '08 S4 - Twenty-four ~~~

Key Concepts: Recursive Backtracking 

Very ugly solution -> simply brute force all possible operations 
    - choose all pairs of cards left and multiply/divide/add/subtract them
*/

#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> c) {
    if (c.size()==1) {
        if (c[0]>24) return -1e8;
        return c[0];
    }

    int ans = 0;
    for (int i=0;i<c.size();i++) {
        for (int j=i+1;j<c.size();j++) {
            int y1 = c[i], y2 = c[j];
            vector<int> yo;
            for (int t=0;t<c.size();t++) 
                if (t!=i&&t!=j) yo.push_back(c[t]);

            for (int i=0;i<6;i++) {
                vector<int> newC;
                for (auto a : yo) newC.push_back(a);
                if (i==0) newC.push_back(y1+y2);
                if (i==1) newC.push_back(y1-y2);
                if (i==2) newC.push_back(y1*y2);
                if (i==3) {
                    if (y2==0) continue;
                    if (y1%y2!=0) continue;
                    newC.push_back(y1/y2);
                }
                if (i==4) newC.push_back(y2-y1);
                if (i==5) {
                    if (y1==0) continue;                    
                    if (y2%y1!=0) continue;
                    newC.push_back(y2/y1);
                }
                ans = max(findMax(newC), ans);
            }
        }
    }
    return ans;
}
int main() {
    // freopen("input.txt", "r", stdin);
    int n; cin>>n;

    for (int i=0;i<n;i++) {
        vector<int> cards;
        int car;
        for (int j=0;j<4;j++) {
            cin>>car; cards.push_back(car);
        }
        int ans = findMax(cards);
        cout<<ans<<endl;
    }
}