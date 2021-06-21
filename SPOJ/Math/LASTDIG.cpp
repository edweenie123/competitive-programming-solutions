#include <bits/stdc++.h>
using namespace std;

int lastDig(long long a, long long b) {
    int aLast = a % 10;
    int lastNums[10][4] = 
    {
        {0,0,0,0},
        {1,1,1,1},
        {2,4,8,6},
        {3,9,7,1},
        {4,6,4,6},
        {5,5,5,5},
        {6,6,6,6},
        {7,9,3,1},
        {8,4,2,6},
        {9,1,9,1}
    };

    if (b==0) {
        return 1; 
    }
    int index = b%4;
    return lastNums[aLast][index-1];

}
int main () {
    int t;
    cin>>t;
    while (t--) {
        long long a,b;
        cin>>a>>b;
        cout<<lastDig(a, b)<<endl;
    }
}