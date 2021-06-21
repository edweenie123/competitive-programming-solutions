/*
~~~ 1365C - Rotation Matching ~~~

Key Concepts: Greedy

Pretty good problem -> i think its the only good problem during the contest

Insight 1: pretty obv
You only need to perform shifts to one array

Insight 2: also pretty obv
You only need to perform shifts of one type (either right or left)
    -> this is because shifting left is the same as shifting to right n - 1 times

Insight 3: 
Lets assume that we only shift b to match the most pairs with a
    -> every element in b has a desired index it want to go to
            which is the index of the same element in a
    -> thus we can calculate the # of right shifts needed for each element in b to match up w/ a
        -> we store the frequency of each desired # of shifts in a freq array
            freq[i] = # of elements that want to shift i times

Now, its pretty obv that the answer is simply the max element in the freq array

*Because a and b are both permutations, there is only one index each element wants to go to
    -> if they weren't permutations, this problem would be a lot harder

*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n;
vector<int> arr;

int idx[MAXN];
int freq[MAXN]; // # of elements that require i shifts

int main() {
    cin>>n;

    int tmp;
    for (int i=1;i<=n;i++) {
        cin>>tmp;
        idx[tmp] = i;
    }

    for (int i=1;i<=n;i++) {
        cin>>tmp;

        int other = idx[tmp];

        if (other == i) {
            freq[0]++;
        }

        if (other > i) {
            freq[other - i]++;
        }

        if (other < i) {
            freq[n - i + other]++;
        }
    }

    int maxFreq = 0;

    for (int i=0;i<=n;i++) {
        maxFreq = max(maxFreq, freq[i]);
    }   

    cout<<maxFreq<<"\n";
}
