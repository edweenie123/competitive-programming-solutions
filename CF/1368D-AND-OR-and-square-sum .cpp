/*
~~~ 1368D - AND, OR and square sum ~~~

Key Concepts: Greedy, Math, bitmasks

Insight 1:
Lets look closer at what an operation does...

Consider
    ai = 000011
    aj = 110000

When we perform the operation it becomes
    ai = 000000
    aj = 110011

Through this, we find that an operation is basically just moves bits from one num to another

Insight 2:
Because we wanna maximize the SQUARE sum 
    -> we want to contruct the largest number possible

This is because (a+b) >= a**2 + b**2 

Therefore, we always want to move bits from a smaller number to a bigger number
    -> we can do this optimally using a greedy strategy

Here is the strat:
    1) sort the numbers in increasing order
    2) iterate through each number i
    3) if i has the j'th bit on -> move that bit to the largest num that has the j'th bit off
           -> to do this quickly, we use a vector to store which numbers have which bits missing 
    4) after iterating through all the numbers, we should have the optimal answer


*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<ll> vals;

vector<int> rowIdx[20 + 5]; // stores indices of all rows with a 0

int main() {
    cin>>n;
    
    ll tmp;
    for (int i=0;i<n;i++) {
        cin>>tmp, vals.push_back(tmp);
    }

    sort(vals.begin(), vals.end());

    for (int i=0;i<n;i++) {    
        // find all bits that are off
        for (int j=0;j<21;j++)
            if (!(vals[i] & (1ll<<j)))
                rowIdx[j].push_back(i);
    }

    for (int i=0;i<n;i++) {
        
        // find all bits that are on
        for (int j=0;j<21;j++) {
            if (vals[i] & (1ll<<j)) {
                // give this bit to the higest number that is missing the bit

                if (rowIdx[j].empty()) continue;
                int biggest = rowIdx[j].back(); 

                if (biggest <= i) continue;

                rowIdx[j].pop_back();

                vals[biggest] += (1ll<<j);
                vals[i] -= (1ll<<j);
            }
        }
    }

    ll ans = 0;

    for (int i=0;i<n;i++) 
        ans += vals[i] * vals[i];

    cout<<ans<<"\n";
}