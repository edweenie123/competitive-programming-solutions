// Key Concepts: Binary Search
// Compute partial sums for all piles -> pSum[i]=p1+p2+...+pi
// Use binary search to find i such that pSum[i-1]<q<=pSum[i]

#include <bits/stdc++.h>
using namespace std;

int n, m, q, temp;
vector <long long int> pSums;

int bs() {
    int low = 0, high = n, mid;
    if (q<pSums[0]) return 1;

    while (low<high) {
        mid = (low+high)/2;
        if (pSums[mid-1]<q&&q<=pSums[mid]) return mid+1;
        else if (q<=pSums[mid-1]) high = mid;
        else low = mid+1;
    }
    return mid+1;
}

int main() {
    cin>>n;
    cin>>temp;
    pSums.push_back(temp);
    for (int i=1;i<n;i++) {
        cin>>temp;
        pSums.push_back(pSums.back()+temp);
    }  
    cin>>m;
    for (int i=0;i<m;i++) {
        cin>>q;
        cout<<bs()<<endl;
    }
}