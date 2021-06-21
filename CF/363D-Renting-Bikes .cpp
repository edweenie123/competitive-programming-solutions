/*
~~~ 363D - Renting Bikes ~~~

Key Concepts: Greedy, Binary Search

I came up with the wrong greedy idea at the beginning cause im stupid

Insight 1: 
If we can afford to have x bois who rent out bikes
    then it is guaranteed that we can have x-1 bois rent out bikes as well

Therefore, we can BS over the # of bikes that we rent out to find the maximum

Insight 2: 
For a given x number of bikes, we can check if it is possible using the following greedy strategy...
    We give the x cheapest bikes to the x richest bois (bois w/ most personal money)
        every time we buy a bike, we try to use all of a boi's personal money
            and use the shared money for the rest of the bike
    
    If we run out of shared money -> then x bikes is impossible
    otherwise -> it is possible

Insight 3:
To get the minimum total amount of personal money used
    -> we find the excess money left over from the greedy start in insight 2
        and subtract that from the total personal money used
    
    This is pretty simple to proove

*/


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int n, m, a;

vector<int> pMoney;
vector<int> bike;


ii isPossible(int k) {
    int moneyLeft = a;
    
    int totP = 0;

    for (int i=0;i<k;i++) {
        int richBoi = pMoney[n-k+i];

        if (richBoi > bike[i]){
            totP += bike[i];
            continue;
        } 
        else {
            moneyLeft -= bike[i] - richBoi;
            if (moneyLeft < 0) return {false, -1};

            totP += richBoi;
        }
    }

    return {true, max(0, totP - moneyLeft)};
}

ii bs() {
    int lo = 0, hi = min(n, m), mid;
    ii best;

    while (lo<=hi) {

        mid = (lo + hi) / 2;
        ii res = isPossible(mid);
        if (res.first) {
            lo = mid + 1;
            best = {mid, res.second};
        } else {
            hi = mid - 1;
        }
    }

    return best;
}

int main() {
    cin>>n>>m>>a;

    int tmp;
    for (int i=0;i<n;i++) {
        cin>>tmp; pMoney.push_back(tmp);
    }

    for (int i=0;i<m;i++) {
        cin>>tmp; bike.push_back(tmp);
    }
    sort(pMoney.begin(), pMoney.end());
    sort(bike.begin(), bike.end());

    ii ans = bs();

    cout<<ans.first<<" "<<ans.second<<"\n";  
}