/*
~~~ CCC '11 S3 - Alice Through the Looking Glass ~~~

Key Concepts: Recursion

Solution is quite simple, but difficult to think of

- Process -
We "shrink" the cords (x, y) so that they fit into the original 5x5 grid

Let elem = view[y][x]

If elem == 0, it is definitely NOT a crystal
If elem == 1, it is definitely a crystal

If elem == 2, it could be a crystal, but we are not sure:
    repeat the process, except we "zoom" into a 5^(m-1) x 5^(m-1) grid 
*/

#include <bits/stdc++.h>
using namespace std;

int TC;

int view[][5] = {
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 2, 1, 2, 0},
    {0, 1, 1, 1, 0}
};
bool isCrystal(int m, int x, int y) {
    if (m==0) return false;

    // printf("mag is %d with cord (%d, %d)\n", m, x, y);
    int blockSize = pow(5, m-1);
    int shrinkX = x / blockSize, shrinkY = y / blockSize;

    if (view[shrinkY][shrinkX]==1) return true;
    else if (view[shrinkY][shrinkX]==0) return false;

    return isCrystal(m-1, x % blockSize, y % blockSize);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>TC;
    int m, x, y;
    while (TC--) {
        cin>>m>>x>>y;
        cout<<(isCrystal(m, x, pow(5, m) - y - 1) ? "crystal" : "empty")<<"\n";
    }
}