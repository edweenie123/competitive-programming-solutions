/*
~~~ 768C - Jon Snow and his Favourite Number ~~~

Key Concepts: BF, Frequency array

The key observation is that the max value of each element is at most 1023

    Therefore, we can generate a frequency array of size 1023 to represent the array

    Instead of performing the operation on the entire array...
        we perform the operation on the frequency array!

    This leads to time complexity of (2^10 * k)

*/


#include<bits/stdc++.h>
using namespace std;

int n, k, x;

vector<int> freq(1024);
vector<int> newFreq(1024);

int main() {
    cin>>n>>k>>x;

    int tmp;
    for (int i=0;i<n;i++) {
        cin>>tmp; freq[tmp]++;
    }

    int behind = 0;

    for (int i=0;i<k;i++) {
        behind = 0;

        newFreq = freq;
        
        for (int j=0;j<1024;j++) {
            if (freq[j]==0) continue;

            int numUpdate = 0;

            if (behind%2==0) 
                numUpdate = freq[j] / 2 + (freq[j]%2!=0); // ceil(freq[j]/2)
            else 
                numUpdate = (freq[j] / 2); // floor(freq[j]/2)
            

            newFreq[j] -= numUpdate;
            newFreq[j^x] += numUpdate;

            behind += freq[j];
        }

        freq = newFreq;
    }

    int minElem = 1e9;
    int maxElem = -1;

    for (int i=0;i<1024;i++) {
        if (freq[i]!=0) {
            minElem = min(minElem, i);
            maxElem = max(maxElem, i);
        }
    }

    cout<<maxElem<<" "<<minElem<<"\n";
}