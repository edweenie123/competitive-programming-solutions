#include <bits/stdc++.h>
using namespace std;

set<int> badRoutes;
vector<int> badRoutesV;
int main() {
    for (int test=0;test<10;test++) {
        badRoutes.clear();
        badRoutesV.clear();
        int minD = 1e9;
        int n;
        cin>>n;
        for (int i=0;i<n;i++) {
            int id, r, d;
            cin>>id>>r;
            for (int j=0;j<r;j++) {
                cin>>d;
                if (d<minD) {
                    badRoutes.clear();
                    minD = d;
                    badRoutes.insert(id);
                } else if (d==minD) badRoutes.insert(id);
            }
        }
        for (auto a : badRoutes) badRoutesV.push_back(a);
        sort(badRoutesV.begin(), badRoutesV.end());
        cout<<minD<<" {";
        for (int i=0;i<badRoutesV.size(); i++) {
            if (i<badRoutesV.size()-1) cout<<badRoutesV[i]<<",";
            else cout<<badRoutesV[i]<<"}"<<endl;
        }
    }
}