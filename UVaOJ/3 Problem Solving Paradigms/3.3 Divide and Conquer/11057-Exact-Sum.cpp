/*
~~~ UVa 11057 - Exact Sum ~~~


*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10000];
vector<pair<int, int>> ans;

int main() {
    // freopen("input.txt", "r", stdin);
    bool space = false;
    while(cin>>n) {
        if (space) cout<<endl;
        space = true;

        memset(arr, 0, sizeof(arr));
        vector<int> prices;
        int p;
        for (int i=0;i<n;i++) {
            cin>>p;
            arr[p]++;
            prices.push_back(p);
        }

        cin>>m;

        ans.clear();

        for (int i=0;i<n;i++) {
            if (arr[m-prices[i]]) {
                if (prices[i]==m-prices[i]&&arr[m-prices[i]]<2) continue;
                ans.push_back(make_pair(prices[i], m-prices[i]));
            }
        }

        int minDif = 1e8;
        pair<int,int> fanswer;
        for (auto a : ans) {
            int dif = abs(a.first-a.second);
            if (dif<minDif) {
                minDif = dif;
                if (a.first<a.second)
                    fanswer = make_pair(a.first, a.second);
                else
                    fanswer = make_pair(a.second, a.first);
            }
        }

        cout<<"Peter should buy books whose prices are "<<fanswer.first<<" and "<<fanswer.second<<"."<<endl;
    }
}