/*
~~~ 1365B - Trouble Sort ~~~

Key Concepts: Sorting, yucky

I kinda guessed the solution during the contest and got it right somehow

Insight 1:
If all elements have the same type
    -> obviously we can't swap anything
    -> thus, the array must already be sorted for it to be possible

Insight 2: - the important one
If consider the follow sequence: a, b, c
    a and b are of the same type and c is a different type

We can obv swap c with either a and b, but what if we want to swap a and b?

Play around with the sequences of moves and you find that its possible using:
    a, b, c -> c, b, a -> b, c, a, b, a, c

This means that if we have at least one element of a different type
    -> we can swap any two elements => it is possible to sort the array

Therefore, all we need to do is check the above condition


*/

#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int main() {
    int TC; cin>>TC;

    while (TC--) {
        arr.clear();
        cin>>n;

        int tmp;
        
        bool alreadySort = true;

        int cnt0 = 0;
        int cnt1 = 0;

        for (int i=0;i<n;i++) {
            cin>>tmp;
            arr.push_back(tmp);
        }

        for (int i=0;i<n;i++) {
            cin>>tmp;
            if (tmp==0) cnt0++;
            if (tmp==1) cnt1++;
        }

        for (int i=1;i<n;i++) {
            if (arr[i] < arr[i-1]) alreadySort = false;
        }

        if (alreadySort) {
            cout<<"Yes\n";
            continue;
        } else {
            if (cnt0 == 0 || cnt0 == n) {
                cout<<"No\n";
            } else {
                cout<<"Yes\n";
            }
        }

    }
}
