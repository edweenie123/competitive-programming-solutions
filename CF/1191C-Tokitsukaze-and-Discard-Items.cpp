/*
~~~ 1191C - Tokitsukaze and Discard Items ~~~

Key Concepts: Implementation

omg im so bad at implementation problems

the equation for upper is the key 

i hate this question

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, k;

vector<ll> special;

int main() {
    cin>>n>>m>>k;

    ll tmp;
    for (int i=0;i<m;i++) 
        cin>>tmp, special.push_back(tmp);
    
    int idx = 0;
    int ans = 0;
    int cnt = 0;

    while (true) {
        if (idx >= m) break;

        // this is the magic equation to get the largest idx in the block
        ll upper = ((special[idx] - cnt - 1) / k + 1) * k + cnt;

        while (true) {
            if (special[idx] > upper || idx >= m) break;

            cnt++;
            idx++;
        } 

        ans++;  
    }

    cout<<ans<<"\n";
}