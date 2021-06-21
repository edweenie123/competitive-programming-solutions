/*
~~~ 487A - Fight the Monster ~~~

Key Concepts: BF, Implementation

The idea is very simple, but the implementation is kinda yucky

Insight 1:
Your attack should be at most 200 (since this will always kill the monster in 1 round)
Your defense should be at most 100 (since the monsters attack will never exceed 100)

Insight 2:
if you know your attack:
    you know the exact number of rounds it will take for you to kill the monster

If you know the # of rounds (r):
    if you also know your defense:
        -> you know the minimum amount of health you need to survive r rounds

Therefore, we can iterate through all possible values of attack and defense
    which yeilds the minimum cost

Time Complexity O(100*200)

*/


#include<bits/stdc++.h>
using namespace std;

int main() {
    int hy, ay, dy;
    int hm, am, dm;

    cin>>hy>>ay>>dy;
    cin>>hm>>am>>dm;

    int h, a, d;
    cin>>h>>a>>d;

    int startAtt = dm + 1;
    int delta = max(startAtt - ay, 0);

    int ans = 1e9;

    for (int i=delta;i<=max(0, dm+100-ay);i++) { // attack plus
        for (int j=0;j<=max(0, am-dy);j++) { // defense plus
            
            int realAtkY = ay + i - dm;
            int rounds = (hm / realAtkY) + (hm % realAtkY != 0);

            int realAtkM = max(0, am - dy - j);

            int minH = rounds * realAtkM + 1; // this is the min health you need
            int hDelta = max(0, minH - hy);

            ans = min(ans, i*a + j*d + hDelta*h);
        }
    }

    cout<<ans<<"\n";
}