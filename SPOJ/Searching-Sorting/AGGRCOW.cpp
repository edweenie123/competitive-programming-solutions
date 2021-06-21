/*
Key Concepts: Greedy Algorithms, Binary Search 

cowsHappy(dist) determines if its possible to separate the cows by dist - Greedy Algorithm
Use binary search to find the optimal distance
*/

#include <bits/stdc++.h>
using namespace std;

int n, c;

bool cowsHappy(int pos[], int dist) {
    int cows = 1;
    int lastCow = pos[0];
    for(int i=1;i<n;i++) {
        if (pos[i]-lastCow>=dist) {
            cows+=1;
            lastCow=pos[i];
            if (cows==c) return true;
        }
    }
    return false;
}

int bs(int pos[]) {
    int min = pos[0];
    int max = pos[n-1];
    int maxDist = -1;
    while (true) {
        // cout<<"min:"<<min<<" max:"<<max<<endl;
        int mid = (min+max)/2;
        // cout<<"mid:"<<mid<<endl;
        if (cowsHappy(pos, mid)) {
            if (mid>maxDist) {
                maxDist = mid;
                // cout<<"newDist:"<<maxDist<<endl;
            } else if (mid==maxDist) return mid;
            min = mid;
        } else {
            max = mid;
        }
    }
}

int main() {
    int t;
    cin>>t;
    while (t--) { 
        cin>>n>>c; // stalls, cows
        int pos[n];
        for(int i=0;i<n;i++) cin>>pos[i];
        sort(pos, pos+n);
        int answer = bs(pos);
        cout<<answer<<endl;
    }
}