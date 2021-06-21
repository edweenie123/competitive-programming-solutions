/*
~~~ Longest Common Subsequence ~~~

Given 2 strings, we want to find the length of their LCS

- Algorithm (recursion) - 


*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
string a, b;

map<pii, int> memo; // memoization table (m, n) --> LCS(m ,n)

int LCS(int m, int n) {
    if (m==-1||n==-1) // reached end of one of the strings
        return 0;

    pii key = {m, n};

    if (memo.find(key)==memo.end()) { // check if already computed LCS(key)
        if (a[m]==b[n]) // last character is the same
            memo[key] = LCS(m-1, n-1) + 1;
        else
            memo[key] = max(LCS(m-1, n), LCS(m, n-1));
    }
    
    return memo[key];
}

int main() {
    cout<<"String A:"<<endl;
    cin>>a;
    cout<<"String B:"<<endl;
    cin>>b;
    cout<<"The LCS is of length "<<LCS(a.length()-1, b.length()-1);
}