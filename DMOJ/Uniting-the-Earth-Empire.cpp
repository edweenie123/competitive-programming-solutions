/*
~~~ VM7WC '15 #2 Gold - Uniting the Earth Empire ~~~

Key Concepts: Data Structures, High IQ


*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> llll; // (height, freq)
const int MAXN = 4e5+1;
int n, sSize;
ll height[MAXN], cnt = 0;
stack<llll> s;

int main() {
    // freopen("input.txt", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0); 
    cin>>n;
    for (int i=0;i<n;i++) cin>>height[i];

    s.push(llll(height[0], 1));
    sSize = 1;
    for (int i=1;i<n;i++) {
       
        if (height[i]>=s.top().first) {
            while (!s.empty()&&height[i]>s.top().first) {
                cnt += s.top().second;
                s.pop();
                sSize--;
            }
            if (!s.empty()) {
                if (s.top().first==height[i]) {
                    llll top = s.top(); 
                    cnt += top.second;
                    s.pop();
                    s.push(llll(top.first, top.second+1));

                    if (sSize>1) cnt++; // this boi is the key to success
                } else cnt++;
            }
        } else {
            cnt++;
        }

        if (s.empty()||s.top().first!=height[i]) {
            s.push(llll(height[i], 1));
            sSize++;
        }
    }

    cout<<cnt<<"\n";
}