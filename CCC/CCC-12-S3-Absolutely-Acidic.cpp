/*
~~~ CCC '12 S3 - Absolutely Acidic ~~~

Key Concepts: Bucket sort, medium iq

Bucket sort the readings and then store the store the highest and 2nd highest frequencies


*/


#include<bits/stdc++.h>
using namespace std;

const int MAXR = 1e3 + 1;
int n;
int freq[MAXR];



int main() {
    cin>>n;
    int tmp;

    for (int i=0;i<n;i++) {
        cin>>tmp;
        freq[tmp]++;
    }


    int largest = 0;
    int largestCnt = 0;
    int secondLargest = 0;

    for (int i=1;i<=1000;i++) {
        if (freq[i] > largest) {
            largest = freq[i];
            largestCnt = 1;
        } else if (freq[i]==largest) {
            largestCnt++;
        } else if (freq[i]>secondLargest) {
            secondLargest = freq[i];
        }
    }

    if (largestCnt>1) secondLargest = largest;


    int idxLeft, idxRight;
    for (int i=1;i<=1000;i++) {
        if (freq[i] == largest) {
            idxLeft = i;
            break;
        }
    }

    for (int i=1000;i>=1;i--) {
        if (freq[i]==secondLargest) {
            idxRight = i;
            break;
        }
    }

    int ans = abs(idxRight - idxLeft); 

    for (int i=1;i<=1000;i++) {
        if (freq[i]==secondLargest) {
            idxLeft = i;
            break;
        }
    }

    for (int i=1000;i>=1;i--) {
        if (freq[i]==largest) {
            idxRight = i;
            break;
        }
    }

    ans = max(ans, abs(idxRight - idxLeft));

    cout<<ans<<"\n";

}