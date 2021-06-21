/*

~~~ DMOPC '19 Contest 7 P2 - Dinner Party ~~~

Key Concepts: brute force, big brain (kinda)


Key Insight:
Imagine if the people were not seated ina circle, but instead in a linear line

The problem would be come trivial:
    You simply fully satisfy the first person (satisfying the 2nd person as a consequence)
    And then you repeat for the next person

To make this work for a circle we try every possible # of times you serve the 0th person (person before the 1st person)

And now we just treat the people as a line and use the same algorithm above to solve it

Time Complexity -> O(a[0th person] * n)

To speed this up we can start this process from the person w/ the smallest appetite

Because "The sum of all ai does not exceed 1 000 000.":
    The new time complexity is O(n) -> i think


*/


#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 1;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int n, arr[MAXN];
int newLine[MAXN];

vector<iii> instruc; // ((p1, p2), numInstruction)

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    int minIdx=-1, minVal=1e6 + 20, sumArr = 0;
    for (int i=0;i<n;i++) {
        cin>>arr[i];
        sumArr += arr[i];

        if (arr[i]<minVal) 
            minVal = arr[i], minIdx = i;
        
    }

    // try taking every amt possible from arr[minIdx]
    for (int take=0;take<=minVal;take++) {
        // reset line
        instruc.clear();
        for (int i=0;i<n;i++) newLine[i] = arr[i];


        int idx = minIdx + 1;
        idx %= n;

        // try intially taking a certain amount 
        newLine[minIdx] = arr[minIdx] - take;
        newLine[idx] = arr[idx] - take;

        // add instructions
        instruc.push_back(iii{ii(minIdx, idx), take});
        

        bool isPossible = true;
        for (int i=0;i<n-1;i++) {
            int nextIdx = (idx + 1) % n;
            
            
            if (newLine[idx] > newLine[nextIdx]) {
                isPossible = false; break;
            }
            
            // fully satisfy the idx'th person (the idx+1'th person gets satisfied as well)
            newLine[nextIdx] -= newLine[idx];
            instruc.push_back(iii{ii{idx, nextIdx}, newLine[idx]});
            newLine[idx] = 0;

            idx = nextIdx;
        }


        if (!isPossible) continue;
        
        // the last person must be satisfied
        if (newLine[minIdx]!=0) continue;

        cout<<"YES\n";
        cout<<sumArr/2<<"\n"; // # instructions is always sum/2

        for (auto in : instruc) {
            for (int i=0;i<in.second;i++) {
                cout<<in.first.first<<" "<<in.first.second<<"\n";
            }
        }

        return 0;
    }

    cout<<"NO\n";

}