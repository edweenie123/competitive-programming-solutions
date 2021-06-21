/*
~~~ 1370E - Binary Subsequence Rotation ~~~

Key Concepts: Data Structure, BS, Greedy

I'm so triggered at this problem
    -> i would have solved this during the contest
        if i knew that you should never erase an iterator before using it
    
Insight 1: 
For all indices i such that a[i] == b[i], we can ignore all of them
    -> we basically pretend they don't exist

Thus we are left with two cases:
    case 0: a[i] = 0 && b[i] = 1
    case 1: a[i] = 1 && b[i] = 0

Insight 2: 
Consider the subsequece of length 2 that contains a case 0 and case 1
    -> when we perform an operation on this, both elements in the subsequence get resolved

We can extrapolate this idea even further to find that if we choose a subsequence that looks like this:
    case 0, case 1, case 0, case 1, ..., case 0, case 1 

        -> all elements in the subsequence get resolved in a SINGLE operation

    This also holds true for the subsequence with the form:
        case 1, case 0, case 1, case 0, ... case 1, case 0

Insight 3:
In order to find the minimum number of operation,
    we greedily find the longest subsequences in the form described in insight 2
        using a set and binary search

*/



#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int n;
string a, b;
 
set<int> zero;
set<int> one;
 
int solve() {
    if (a==b) return 0;
    
    // check if a and b are anagrams
    int aCnt = 0;
    int bCnt = 0;
    for (int i=0;i<n;i++) if (a[i] == '1') aCnt++;
    for (int i=0;i<n;i++) if (b[i] == '1') bCnt++;
    if (aCnt != bCnt) return -1;
    
    // find all the differences between a and b
    for (int i=0;i<n;i++) {
        if (a[i] == '1' && b[i] == '0') one.insert(i);
        else if (a[i] == '0' && b[i] == '1') zero.insert(i);
    }
 
    int cnt = 0;
    while (true) {
 
        int oneF = *one.begin();
        int zeroF = *zero.begin();
 
        if (oneF < zeroF) {
            int idx = 0;
 
            while (true) {
                auto nextO = one.lower_bound(idx);
                auto nextZ = zero.lower_bound(*nextO);
                
                if (nextO == one.end() || nextZ == zero.end()) 
                    break;
                
                idx = *nextZ;
 
                one.erase(nextO);
                zero.erase(nextZ);
            } 
        } else {
            int idx = 0;
 
            while (true) {
                auto nextZ = zero.lower_bound(idx);
                auto nextO = one.lower_bound(*nextZ);
                
                if (nextO == one.end() || nextZ == zero.end()) 
                    break;

                idx = *nextO; 
 
                zero.erase(nextZ);
                one.erase(nextO);
            }
        }

        cnt++; // performed an operation

        if (zero.empty()) break;
    }
 
    return cnt;
}
 
int main() {
    cin>>n;
 
    cin>>a>>b;
 
    int ans = solve();
    cout<<ans<<'\n';
}