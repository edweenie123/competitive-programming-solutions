/*
WIP
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;

set<int> empt;
vector<int> pos;

int lastPerson() {
    // int ppl = k+1;

    while(true) {
        if (pos.size()==1) {
            return pos[0];
        }
        
        vector<int> newPos;

        for (int i=0;i<pos.size();i++) {
            int s = pos[i];
            
            if (empt.find(s)!=empt.end()) {
                empt.erase(s);
            } else {
                int p = pos[i] + 1;
                if (p>n) p = 1;
                newPos.push_back(p);
            }
        }
        pos = newPos;        
    }
}

int main() {
    cin>>n>>k;

    int temp;
    for (int i=0;i<k;i++) {
        cin>>temp;
        empt.insert(temp);
    }

    for (int i=0;i<k;i++) {
        cin>>temp;
        pos.push_back(temp);
    }

    cout<<lastPerson();
}