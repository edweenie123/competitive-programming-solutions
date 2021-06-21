#include <bits/stdc++.h>
using namespace std;

map<string, string> ruleMap;
int main() {
    int tests = 10, r, t;
    string a, s1, s2;
    while (tests--) {
        ruleMap.clear();
        cin>>r>>t>>a;
        for (int i=0;i<r;i++) {
            cin>>s1>>s2;
            ruleMap[s1] = s2;
        }
        for (int i=0;i<t;i++) {
            string nxtItr = "";
            for (int j=0;j<a.size();j++) {
                string let(1, a[j]);
                if (ruleMap.find(let) != ruleMap.end()) {
                    nxtItr += ruleMap[let];
                } else nxtItr += let;
            }
            a = nxtItr;
        }
        cout<<a[0]<<a.back()<<" "<<a.size()<<endl;
    }
}