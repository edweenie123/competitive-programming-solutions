#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> ii;

// sorts in decreasing order
typedef tree<ii, null_type, greater<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

const int MAXT = 1e5 + 3;

double t;
ordered_set allScores;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>t;

    int score, idx=0;
    double rankSum = 0;

    for (int i=0;i<t;i++) {
        cin>>score;

        // find all scores greater than current one
        int rank = allScores.order_of_key({score, 1e9}) + 1;
        rankSum += rank;

        allScores.insert({score, idx++});
    }

    double ans = rankSum / t;
    ans = (ans * 100.0) / 100.0;

    cout<<fixed<<setprecision(2);
    cout<<ans<<"\n";
}