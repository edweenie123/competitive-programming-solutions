#include<bits/stdc++.h>
using namespace std;

// checks if a given arrangment of pieces is valid
bool isValid(string argmt) {
    string rk = "";
    vector<int> bishopPos;
    int idx = 1;
    for (auto c : argmt) {
        if (c=='R' || c=='K') rk += c;

        if (c=='B') bishopPos.push_back(idx);
        idx++;
    }

    if (rk != "RKR") return false;
    if (bishopPos[0]%2 == bishopPos[1] %2) return false;

    return true;
}


// int ans;
map<string, int> dp;
set<string> seen;
// tries all possible ways of filling empty spots
int recur(map<char, int> left, string bois, int cnt) {
    // if (dp.count(bois)) {
    //     return dp[bois];
    // }

    if (cnt==0 && isValid(bois) && !seen.count(bois)) {
        seen.insert(bois);

        return 1;
    }

    int count = 0;

    for (int i=0;i<8;i++) {
        if (bois[i]=='_') {
            for (auto l : left) {
                if (l.second!=0) {

                    string newString = bois.substr(0, i) + l.first + bois.substr(i+1);
                    left[l.first]--;

                    count += recur(left, newString, cnt - 1); 
                    
                    left[l.first]++;
                }
            }
        }
    }

    return dp[bois] = count;

}

int main() {
    int t = 10;

    string chess;
    while(t--) {
        cin>>chess;

        seen.clear();

        map<char, int> initial = {
            {'K', 1}, {'Q', 1}, {'R', 2}, {'N', 2}, {'B', 2}
        };

        int unknCnt = 0;

        for (auto c : chess) {
            if (c!='_') {
                initial[c]--;
            } else {
                unknCnt++;
            }
        }
        int ans = recur(initial, chess, unknCnt);

        cout<<ans<<"\n";        
    }
}