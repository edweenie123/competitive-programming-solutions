/*
~~~ 1153C - Serval and Parenthesis Sequence ~~~

Key Concepts: Greedy

Pretty decent greedy problem actually;
big facepalm moment when i read the solution

*/



#include<bits/stdc++.h>
using namespace std;

int n;
string s;

string solve() {
    cin>>n>>s;

    if (n%2==1) return ":(";

    string newS = "";

    int begCnt = 0;

    int misCnt = 0;
    for (int i=0;i<n;i++) {
        if (s[i]=='?') misCnt++;
        else if (s[i]=='(') begCnt++;
    }

    int begAvail = n/2 - begCnt;

    if (begAvail<0) return ":(";

    int curSum = 0;

    for (int i=0;i<n;i++) {
        if (s[i]=='?') {
            if (begAvail) {
                begAvail--;
                curSum++;
                newS += '(';
            } else {
                curSum--;
                newS += ')';
            }
        } else if (s[i]=='(') {
            curSum++;
            newS += '(';
        } else {
            curSum--;
            newS += ')';
        }

        if (i!=n-1 && curSum==0) 
            return ":(";
        if (curSum<0) return ":(";
        
    }

    return newS;
}

int main() {
    string ans = solve();
    cout<<ans<<"\n";
}