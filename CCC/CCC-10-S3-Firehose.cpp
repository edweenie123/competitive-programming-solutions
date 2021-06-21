/*
~~~ CCC '10 S3 - Firehose ~~~

Key Concepts: Binary Search

We will use binary search to find the min hose length

The hardest part of the problem is to determine if its possible to cover all houses with a particular hose length

    1. we start at house 1 at place a fire hydrant to just cover it, 
    2. then we use bs to find the first house that that isn't covered by that fire hydrant
    3. repeat until all fire hydrants have been used or all houses are covered
    4. repeat steps 1-3 starting at each possible house

We can use a deque to represent the circle of addresses 
*/


#include<bits/stdc++.h>
using namespace std;

const int MAXH = 1e3 + 5;
int h, k;
vector<int> address;
deque<int> a;

int findBestHouse(int add) {
    int lo=0, hi=h-1, mid=-1, best=-1;

    while (lo<=hi) {
        mid = (lo + hi)/2;
        // printf("    the mid is %d\n", mid);
        if (a.at(mid) <= add) {
            lo = mid + 1;
            best = mid;
        } else if (a.at(mid) > add) {
            hi = mid-1;
        }
    }

    return best;
}


bool isPossible(int len) {
    a.clear();

    for (auto e : address) {
        a.push_back(e);
    }

    for (int start=0;start<h;start++) { // start at each possible house
        int maxReach, idx=0;

        for (int i=0;i<k;i++) { // place hydrants, until there are none left
            maxReach = a.at(idx) + 2*len;

            idx = findBestHouse(maxReach);
            if (idx==h-1) {
                return true;
            }
            idx++;
        }

        int begin = a.front();
        a.pop_front();
        a.push_back(begin + 1e6);
    }

    return false;

}


int findMinLen() {
    int lo = 0, hi = 1e6, mid=-1, best=-1;

    while (lo<=hi) {
        
        mid = (lo + hi)/2;

        if (isPossible(mid)) {
            hi = mid -1;
            best = mid;
        } else {
            lo = mid + 1;
        }
    }

    return best;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>h;

    int tmp;
    for (int i=0;i<h;i++) {
        cin>>tmp;
        address.push_back(tmp);
    }
    
    cin>>k;

    sort(address.begin(), address.end());

    int ans = findMinLen();

    cout<<ans<<"\n";
}