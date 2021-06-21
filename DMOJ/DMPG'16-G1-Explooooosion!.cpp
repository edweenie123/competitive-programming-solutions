/*
~~~ DMPG '16 G1 - Explooooosion! ~~~

Key Concepts: Greedy Algorithm

The greedy algorithm is quite difficult to come up with

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+1;
const ll MOD = 1e9+7;

int n, oneCnt=0, twoCnt=0, divCnt;
priority_queue<ll, vector<ll>, greater<>> nums;
ll maxAns = 1, minAns = 0;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;

    ll tmp;
    for (int i=0;i<n;i++) {
        cin>>tmp; nums.push(tmp);
        if (tmp!=1) minAns += tmp;
        else oneCnt++;
        if (tmp==2) twoCnt++;
    }


    if (n==1&&nums.top()==1) { // corner case: n=1 and pi = 1
        cout<<1<<"\n";
        cout<<1<<"\n";
        return 0;
    } 
    if (oneCnt==n) cout<<1<<"\n"; // corner case: all potencies are 1
    else cout<<minAns<<"\n";

    while (true) {
        ll u = nums.top();
        if (u!=1) break;
        if (oneCnt>=2&&twoCnt>=2) { // corner case: freq[2] >= 2 and freq[1] >=2
            nums.pop(); nums.pop(); // pop 2 1s
            nums.push(3); nums.push(3); // add 2 3s
            divCnt+=2;
            oneCnt-=2; 
            twoCnt-=2;
        } else {
            nums.pop();
            ll v = nums.top();
            if (v==2) {
                for (int i=0;i<divCnt;i++) {
                    nums.pop();
                }
                divCnt=0;
            }

            v = nums.top();

            nums.pop();
            nums.push(v+1);
            oneCnt--;
            
            if (v+1==2) {
                twoCnt++;
                oneCnt--;
            }
            if (v==2) twoCnt--;
        }

    }

    while (!nums.empty()) {
        ll u = nums.top(); nums.pop();
        if (u==2&&divCnt>0) {
            divCnt--;
            continue;
        }
        maxAns = ((maxAns%MOD) * u%MOD)%MOD;
    }

    cout<<maxAns<<"\n";
}