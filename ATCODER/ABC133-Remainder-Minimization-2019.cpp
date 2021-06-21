/* 
~~~ AtCoder Beginner Contest 133 - Remainder Minimization 2019 ~~~

Key Concepts: Modular Arthmetic

Realize that (a*b) mod c = ((a mod c)*(b mod c)) mod c
*/

#include <bits/stdc++.h>

using namespace std;

int l, r;
set<int> modNums;
vector<int> modNumsVec;
int findMin() {

    int minVal = 1e9;
    for (auto i : modNumsVec) {
        for (auto j : modNumsVec) {
            if (j==i) continue;
            minVal = min((i*j)%2019, minVal);
        }
    }

    return minVal;
}

int main() {
    cin>>l>>r;

    for (int i=l;i<=r;i++) {
        modNums.insert(i%2019);
        if (modNums.size()==2019) break;
    }
    
    for (auto n : modNums) {
        modNumsVec.push_back(n);
    }
    cout<<findMin();
}