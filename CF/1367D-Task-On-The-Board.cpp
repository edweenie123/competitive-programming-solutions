/*
~~~ 1367D - Task On The Board ~~~

Key Concepts: Greedy, yucky implementation

The greedy strategy isn't that hard to come up with but the implementation yucky

Insight 1: 
In the original array, there will be at least 1 i such that b[i] = 0
    -> it is very intuitive that the largest char should go in all these indices

    -> after we place the largest char in all these indices, 
        we can update the b array to account for the placed characters
            (b[j] -= dist(j, i))

Insight 2:
There is an edge case where this doesn't work!!

Consider s = cbbb
         b = [0, 0, 0]

In this case, the there aren't enough of the largest character to fill up all the 0's
    -> therefore, we have to continously look at the NEXT LARGEST char and check if it has a high enough freq
        to fill up all the 0's

*/




#include<bits/stdc++.h>
using namespace std;

#define print(x) cout<<(#x)<<" = "<<(x)<<"\n";
const int MAXM = 50 + 5;

int b[MAXM];
char ret[MAXM]; // return string
int freq[30];

string solve() {
    string s; int m;
    cin>>s>>m;

    for (int i=1;i<=m;i++) {
        cin>>b[i];
        ret[i] = ' ';
    }

    for (int i=0;i<30;i++) freq[i] = 0;
    for (auto c : s) freq[c-'a'+1]++;
    
    sort(s.begin(), s.end(), greater<char>());
    int sIdx = 0;
    int selec = 0; // number of chars selected 

    while (true) {
        if (selec == m) break;

        int zeroCnt = 0;

        // count # of 0's in b that haven't been filled yet
        for (int i=1;i<=m;i++)
            if (b[i]==0 && ret[i]==' ') zeroCnt++;
        
        // find the char that can fill up all the 0's
        while (true) {
            if (freq[s[sIdx]-'a'+1] >= zeroCnt) {
                break;
            }

            char last = s[sIdx];
            while (last == s[sIdx]) {
                sIdx++;
            }
        }
        
        vector<int> newIdx;
        // fill in all the 0's with a chosen char
        for (int i=1;i<=m;i++) {
            if (b[i]==0 && ret[i] == ' ') {
                ret[i] = s[sIdx];
                selec+=1;
                newIdx.push_back(i);
            }

        }
        
        // update the b values for the rest of the indices
        for (auto i : newIdx) {
            for (int j=1;j<=m;j++) {
                if (b[j] != 0) b[j] -= abs(i - j);
            }
        }

        // find next largest char
        char last = s[sIdx];
        while (last == s[sIdx]) {
            sIdx++;
        }
    }

    string ans = "";

    for (int i=1;i<=m;i++) ans += ret[i];

    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TC; cin>>TC;

    while (TC--) {
        string ans = solve();
        cout<<ans<<"\n";
    }
}