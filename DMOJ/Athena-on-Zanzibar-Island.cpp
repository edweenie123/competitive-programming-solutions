/*
~~~ Athena on Zanzibar Island ~~~

Key Concepts: Binary Search

sort the array

For each negative element use binary search to find the closest element to its negative
    - You gotta do a yucky thing with a map to resolve ties

You can also use a two pointer method, which is technically faster


*/



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
vector<int> pos;
vector<int> neg;

unordered_map<int, vector<int>> bestIdx;
vector<ii> answers; // stores all pairs of values that have the minimum abs sum

ll lowestSum = 1e17;

void maybeUpdate(int elem1, int elem2) {
    ll absSum = abs(elem1 + elem2);
    if (absSum < lowestSum) {
        
        answers.clear();
        answers.push_back({elem1, elem2});
        lowestSum = absSum;

    } else if (absSum == lowestSum) 
        answers.push_back({elem1, elem2});
}

ii resolveTies() {
    vector<ii> ansIndices;
    for (auto a : answers) {
        int e1 = a.first, e2 = a.second;

        int e1Idx = bestIdx[e1][0], e2Idx = bestIdx[e2][0]; 
        if (e1 == e2) {
            ii maybe = {e1Idx, bestIdx[e1][1]};
            ansIndices.push_back(maybe);
        } else {
            ii maybe = {min(e1Idx, e2Idx), max(e1Idx, e2Idx)};
            ansIndices.push_back(maybe);
        }
    }

    sort(ansIndices.begin(), ansIndices.end());

    return ansIndices[0];
}


void solve() {
    // handle negative + positive bois first

    for (auto elem : neg) {

        auto iter = lower_bound(pos.begin(), pos.end(), -elem);

        if (iter != pos.end()) 
            maybeUpdate(elem, *iter);

        // try behind
        if (iter != pos.begin()) {
            auto behind = iter-1;
            maybeUpdate(elem, *behind);
        }
    }

    // try pos + pos
    if (pos.size() >= 2) 
        maybeUpdate(pos[0], pos[1]);
    

    // try neg + neg
    if (neg.size() >= 2) 
        maybeUpdate(neg.end()[-1], neg.end()[-2]);

    ii indices = resolveTies();

    cout<<lowestSum<<"\n";
    cout<<indices.first<<" "<<indices.second<<"\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n;
    cin>>n;

    int tmp;
    for (int i=1;i<=n;i++) {
        cin>>tmp;
        bestIdx[tmp].push_back(i);
        
        if (tmp < 0) neg.push_back(tmp);
        else pos.push_back(tmp);
    }

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());

    solve();

}