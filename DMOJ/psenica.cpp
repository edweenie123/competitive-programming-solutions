#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int MAXN = 1e5+1;
int n, freq[MAXN];
vector<ii> wheat; // (height, freq)
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    int val;
    for (int i=0;i<n;i++) {
        cin>>val;
        freq[val]++;
    }

    for (int i=0;i<MAXN;i++) {
        if (freq[i]>0) wheat.push_back(ii(i, freq[i]));
    }

    sort(wheat.begin(), wheat.end());

    int left = 0, right = wheat.size() - 1;
    int winner = -1, turn = 0;

    for (int i=0;i<MAXN;i++) {
        if (right-left+1<3) {
            winner = !(turn % 2);
            // printf("%d wins on turn %d\n", winner, turn);
            break;
        }

        if (turn%2==0) {
            wheat[left].second--;
            wheat[left+1].second++;

            if (wheat[left].second==0) left++;
            // if (right-left+1<3) {
            //     winner = !(turn % 2);
            //     left--;
            //     break;
            // }
        } else {
            wheat[right].second--;
            wheat[right-1].second++;
            if (wheat[right].second==0) right--;
            // if (right-left+1<3) {
            //     winner = !(turn % 2);
            //     right++;
            //     break;
            // }
        }

        turn++;
    }

    // if (winner==-1) winner = n%2;

    cout<<(winner==0 ? "Mirko" : "Slavko")<<"\n";
    cout<<wheat[left].first<<" "<<wheat[right].first<<"\n";
}