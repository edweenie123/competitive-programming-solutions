/*
~~~ 1371E1 - Asterism (Easy Version) ~~~

Key Concepts: Number theory?, Math, brute force

Pretty weird problem

Insight 1:
There can be at most 2000 values for x
    -> because max value of all elements is 2000

Insight 2:
For a given x value, we can check if it is good in O(n)
    Using this weird algorithm:

        we sort the enemies in decreasing order

        For each enemy, we find the # of locations
            it can be within our permutation such that the permutation will be valid
                let this number be k
        
        Notice that the product of all the k's is the total # of valid permutations

        if any of the k's are divisible by p
            then that implies the total # of valid permutations is also div by p
        
        Therefore we just have to check if any of the k values are div by p
            to determine if a given x is valid

Time Complexity: O(n^2)



*/



#include<bits/stdc++.h>
using namespace std;
    
const int MAXN = 2e3 + 5;

int n, p;
vector<int> cand;
vector<int> goodx;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>p;

    int tmp;
    for (int i=0;i<n;i++) {
        cin>>tmp; cand.push_back(tmp);
    }

    sort(cand.begin(), cand.end(), greater<int>());
    
    for (int x=1;x<=MAXN;x++) {
        bool isValid = true;

        int maxLev = x + n - 1;

        for (int i=0;i<cand.size();i++) {
            int posLoc = min(maxLev - cand[i] + 1, n);
            int ways = posLoc - i;
            
            if (ways % p == 0 || ways<1) {
                isValid = false;
                break;
            }
        }

        if (isValid) 
            goodx.push_back(x);
    }

    cout<<goodx.size()<<"\n";
    for (auto x : goodx)
        cout<<x<<" ";
    cout<<"\n";
}