/*
~~~ 1368B - Codeforces Subsequences ~~~

Key Concepts: Math, insight

Very ez problem if you see the insight

Insight 1:
We can create more subsequences in the most efficient way by increasing the frequency of each char

Insight 2:
To be the most efficient -> we want the frequency of each char to be as close a possible together
    -> this is quite intuitive

Therefore we can simply increase the frequency of each char one by one until we have at least k subsequences

The number of subsequences = product of all frequency of problem

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k;
int freq[10];

int main() {
    cin>>k;

    for (int i=0;i<10;i++) 
        freq[i] = 1;


    int idx = 0;
    while (true) {

        ll prod = 1;

        for (int i=0;i<10;i++)
            prod *= freq[i];
        
        if (prod >= k) break;

        freq[idx]++;
        idx++;

        idx %= 10;
    }

    string s = "";
    string ori = "codeforces";
    for (int i=0;i<10;i++) {
        for (int j=0;j<freq[i];j++) s += ori[i];
    }

    cout<<s<<"\n";
    
}