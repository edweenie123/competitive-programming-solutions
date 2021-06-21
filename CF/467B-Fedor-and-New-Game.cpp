// Solved!
// x = XOR of the two armies
// count number of bits in x

#include <bits/stdc++.h>
using namespace std;

vector<int> army;

int cntOnes(int n) {
    int cnt=0;
    while (n) {
        cnt += n & 1;
        n = n >> 1;
    }
    return cnt;
}
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<m;i++) {
        int a;
        cin>>a;
        army.push_back(a);
    }
    int fedor;
    cin>>fedor;
    int friends=0;
    for (auto a : army) {
        if (cntOnes(fedor^a)<=k) friends++;
    }
    cout<<friends<<endl;

}   