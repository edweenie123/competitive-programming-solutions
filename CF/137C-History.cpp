/*
~~~ 137C - History ~~~

Key Concepts: Sortings

Pretty simple sorting problem,

If you sort the events by their starting time
    -> and you iterate through the array 
        it is guaranteed that that all events already processed start before the current element
            -> therefore you just have to check if there exists something that ends after the current element
                which you can update as you iterate through the array

*/


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int n;
vector<ii> eve;

int main() {
    cin>>n;

    int a, b;
    for (int i=0;i<n;i++) {
        cin>>a>>b;
        eve.push_back({a, b});
    }

    sort(eve.begin(), eve.end());

    int maxEnd = 0;
    int ans = 0;
    for (int i=0;i<n;i++) {
        if (eve[i].second < maxEnd) ans++;
        maxEnd = max(maxEnd, eve[i].second);
    }

    cout<<ans<<"\n";
}