/*
~~~ VM7WC '15 #2 Silver - 4 Nations, 1 Secret ~~~

Key Concepts: Implementation (sorta string algorithms)

Find the longest palindrome found within a string
*/

#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int main() {
    cin>>n>>s;

    int halfLenOdd = 0, maxLen = 0;
    int halfLenEven = 0;
    string ans;
    for (int i=0;i<n;i++) {
        halfLenOdd = halfLenEven = 0;
        for (int j=1;j<=i;j++) {
            if (s[i-j]==s[i+j]) halfLenOdd++;
            else break;
        }
        if (2*halfLenOdd+1>maxLen) {
            maxLen = 2*halfLenOdd+1;
            ans = s.substr(i-halfLenOdd, maxLen);
        }

        for (int j=0;j<=i;j++) {
            if (s[i-j]==s[i+j+1]) halfLenEven++;
            else break;
        }

        if (2*halfLenEven>maxLen) {
            // cout<<"halfLenEven: "<<halfLenEven<<endl;
            maxLen = 2*halfLenEven;
            ans = s.substr(i-halfLenEven+1, maxLen);
            // cout<<"new ans "<<ans<<endl;
        } 
        // cout<<"i "<<i<<endl;
    }

    cout<<ans<<"\n";
    cout<<maxLen<<"\n";
}