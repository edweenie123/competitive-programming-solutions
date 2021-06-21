#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef pair<int, int> ii;

int t, g;

bool isWinner(vector<int> fScore) {
    for (int i=0;i<4;i++) {
        if (i==t-1) continue;
        if (fScore[t-1] <= fScore[i]) return false;
    }
    return true;
}

int ans = 0;
void recur(set<ii> remG, vector<int> points) {
    if (remG.size()==0) {
        if (isWinner(points)) 
            ans++;
        return; 
    }
    
    ii game = *remG.begin();

    set<ii> nextRemG;
    for (auto tmp : remG) nextRemG.insert(tmp);
    nextRemG.erase(game);

    int t1 = game.F, t2 = game.S;

    // Case: t1 wins
    vector<int> tmpPoints; for (int i=0;i<4;i++) tmpPoints.push_back(points[i]);
    tmpPoints[t1-1] += 3;
    recur(nextRemG, tmpPoints);

    //Case: t1 loses
    tmpPoints.clear(); for (int i=0;i<4;i++) tmpPoints.push_back(points[i]);
    tmpPoints[t2-1] += 3;
    recur(nextRemG, tmpPoints);

    //Case: t1 ties
    tmpPoints.clear(); for (int i=0;i<4;i++) tmpPoints.push_back(points[i]);
    tmpPoints[t1-1] += 1;
    tmpPoints[t2-1] += 1;
    recur(nextRemG, tmpPoints);

}

int main() {
    cin>>t>>g;

    vector<int> score(4);
    set<ii> games = {
        {1,2}, {1,3}, {1,4},
        {2,3}, {2,4}, 
        {3,4}
    };

    int a, b, aS, bS;
    for (int i=0;i<g;i++) {
        cin>>a>>b>>aS>>bS;

        if (games.count({a,b})) games.erase({a,b});
        if (games.count({b,a})) games.erase({b,a});

        if (aS>bS) 
            score[a-1] += 3;
        else if (bS>aS)
            score[b-1] += 3;
        else {
            score[a-1] += 1;
            score[b-1] += 1;
        }
    }

    recur(games, score);
    cout<<ans<<"\n";
}