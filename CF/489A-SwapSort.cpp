// For the ith element, we swap it with the minimum element
// Sorting will take at most n-1 swaps

#include <bits/stdc++.h>
using namespace std;

int arr[3000];
vector<array<int,2>> swaps;
int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>arr[i];

    int numSwaps = 0;
    for (int i=0;i<n;i++) {
        int min=i;
        for (int j=i;j<n;j++) {
            if (arr[j]<arr[min]) {
                min = j;
            }
        }
        if (min!=i) {
            swaps.push_back({i, min});
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            numSwaps++;
        }
    }
    cout<<numSwaps<<endl;
    for(auto s: swaps) {
        cout<<s[0]<<" "<<s[1]<<endl;
    }
    
}