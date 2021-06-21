// Solved!
#include <bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        int fiveCount = 0;
        while (true) {
            if (x <= 1) {
                break;
            }
            fiveCount += x / 5;
            x /= 5;
        }
        cout << fiveCount << endl;
    }
}