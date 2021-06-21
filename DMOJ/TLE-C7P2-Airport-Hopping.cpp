// Key Concepts: Greedy Algorithms

#include <bits/stdc++.h>
using namespace std;

array < vector < array <int, 3> >, 100001 > flights;
int main() {
    int n, m;
    cin>>n>>m;
    int a, b, c;
    for (int i=0;i<m;i++) {
        cin>>a>>b>>c;
        flights[a].push_back({b, c});
    }
    int day = 0, hour = 0;
    for (int s=1;s<n;s++) {
        int fDelta = 1e9;
        for (auto f : flights[s]) {
            int newDelta;
            if (hour < f[0]) {
                newDelta = f[0] - hour + f[1];
            } else {
                newDelta = f[0] - hour + 24 + f[1];
            }
            
            if (newDelta < fDelta) fDelta = newDelta;
            
            // cout<<"f "<<f[0]<<" "<<f[1]<<" fdel "<<newDelta<<endl; 
        }
        hour += fDelta;
        if (hour >= 24) {
            day += hour / 24;
            hour = hour % 24;
        }
        // cout<<"Day "<<day<<" Hour "<<hour<<endl;

    }
    cout<<"Day "<<day<<" Hour "<<hour+1<<endl;
}