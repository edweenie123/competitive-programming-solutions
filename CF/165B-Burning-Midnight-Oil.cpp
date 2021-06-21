// Key Concepts: Binary Search

#include <bits/stdc++.h>
using namespace std;

int n, k;

int linesOfCode(int v) {
    int cnt = 0, temp, power = 0;
    while (true) {
        temp = v/pow(k, power);
        if (temp<=0) break;
        cnt += temp;
        power++;
    }
    return cnt;
}

int bs() {
    int min=0, max = n, mid, lines;

    while (min<max) {
        mid = (min+max)/2;
        lines = linesOfCode(mid);
        if (lines==n) return mid;
        if (lines>n) max = mid;
        else min = mid+1;
    }
    if (lines < n) mid++;
    return mid;
}

int main() {
    cin>>n>>k;
    cout<<bs();
}