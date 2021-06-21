/*
~~~ DMPG '15 B4 - Maximum Product ~~~

Key Concepts: Greedy Algorithm

If # of negative integers is even, include every card exept 0
else include every negative number except the greatest one

Corner Case - the only card available is negative:
Must include this card, since minimum # of cards = 1
If there is a 0 available, include it as well (0*neg>neg)
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;

int main() {
    int num, maxNeg=-6, negCount=0;
    bool hasZero=false;
    cin>>n;
    
    for (int i=0;i<n;i++) {
        cin>>num;
        if (num==0) {
            hasZero=true;
            continue;
        } 
        if (num<0) {
            negCount++;
            if (num>maxNeg) maxNeg = num;
        }
        nums.push_back(num);
    }

    int product=0;

    if (negCount%2!=0) {
        for (auto i : nums) {
            if (i==maxNeg) {
                maxNeg=-6;
                continue;
            }
            if (product==0) product = i;
            else product *= i;
        }
    } else {
        for (auto i : nums) {
            if (product==0) product = i;
            else product *= i;
        }
    }

    if (nums.size()==1&&!hasZero) product = nums[0];
    cout<<product;
}