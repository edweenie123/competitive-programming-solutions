#include <bits/stdc++.h>
using namespace std;


long long fib[60];

void precompute() {
    fib[1] = 1;
    fib[2] = 1;
    for (int i=3;i<60;i++) {
        fib[i] = fib[i-1]+fib[i-2];
    }
}

int main() {
    precompute();
    for (int tests=0;tests<10;tests++) {
        long long x, y;
        cin>>x>>y;

        long long fx=0, fy=0;

        int rot = 0;
        for (int i=1;i<60;i++) {
            if (x>=fx&&x<=fx+fib[i]&&y<=fy&&y>=fy-fib[i]) {
                cout<<i<<endl;
                break;
            }
            if (rot==0) {
                fx-=fib[i+1];
                fy+=fib[i-1];
            } else if (rot==1) {
                fy+=fib[i+1];
            } else if (rot==2) {
                fx+=fib[i];
            } else {
                fx-=fib[i-1];
                fy-=fib[i];
            }
            rot += 1;
            rot %= 4;
        }
    }
}