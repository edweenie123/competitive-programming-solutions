// Greedy approach
// 1. Sort skills levels, 
// 2. Iterate through all possible pairs
// 3. if dif in skill level <= 1, create pair, move on to next person

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    vector<int> boys, girls;
    cin>>n;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x; 
        boys.push_back(x);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int x;
        cin>>x; 
        girls.push_back(x);
    } 

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    int numPairs=0;
    for (int b=0;b<n;b++) {
        for (int g=0;g<m;g++) {
            if (abs(boys[b]-girls[g])<=1) {
                numPairs++;
                girls[g] = 10000;
                break;
            }
        }
    }
    cout<<numPairs<<endl;
}