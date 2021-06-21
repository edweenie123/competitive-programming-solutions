/*
~~~ UVa 573 - The Snail ~~~

Key Concepts: Simulation
*/

#include <bits/stdc++.h>
using namespace std;

float h, u, d, f;

void snail() {
    float dec = u * (f/100);
    int day = 0;
    float curH=0;
    while (true) {
        day++;

        curH += u;
        if (curH>h) {
            cout<<"success on day "<<day<<endl;
            break;
        }
        curH -= d;
        if (curH<0) {
            cout<<"failure on day "<<day<<endl;
            break;
        } 
        u = max((float)0, u-dec);
    }
}

int main() {
    while (true) {
        cin>>h>>u>>d>>f;
        if (h==0) break;
        snail();
    }
}