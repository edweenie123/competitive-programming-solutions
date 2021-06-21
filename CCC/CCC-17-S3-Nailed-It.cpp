/*
~~~ CCC '17 S3 - Nailed It! ~~~

Key Concepts: Counting Sort

Pretty good question

We first using counting sort to store all the wood lengths

We then iterate through the frequency table to generate the total # of boards we could make of each height
    boardHFreq[i] stores the # of boards we can make with a height of i

Then length of the longest fence is thus the largest element in the boardHFreq
    - the number of different heights this longest fence can have is simply the frequency of this largest element


*/


#include<bits/stdc++.h>
using namespace std;

const int MAXL = 2e3+5;

int n;
int woodHFreq[MAXL];
int boardHFreq[MAXL*2];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    int tmp;
    for (int i=0;i<n;i++) {
        cin>>tmp;
        woodHFreq[tmp]++;
    }

    for (int i=1;i<=2000;i++) {
        for (int j=i;j<=2000;j++) {
            if (i==j)
                boardHFreq[i+i] += woodHFreq[i] / 2;
            else 
                boardHFreq[i+j] += min(woodHFreq[i], woodHFreq[j]);
        }
    }

    int longest = 0;
    int numLongest = 0;

    for (int i=2;i<=4000;i++) {
        if (boardHFreq[i] > longest) {
            longest = boardHFreq[i];
            numLongest = 1;
        } else if (boardHFreq[i] == longest) {
            numLongest++;
        }
    }

    cout<<longest<<" "<<numLongest<<"\n";
}