// WAs randomly -- idk how to fix

#include <bits/stdc++.h>
using namespace std;

long long n, p, m, u, v, temp;
long long tanks[200000][2];

vector<long long> pAttack, mAttack;
long long prefixP[200000], prefixM[200000];

void computePrefix() {
    prefixP[0] = pAttack[0];
    prefixM[0] = mAttack[0];

    for (int i=1;i<p;i++) 
        prefixP[i] = pAttack[i]+prefixP[i-1];
    for (int i=1;i<m;i++) 
        prefixM[i] = mAttack[i]+prefixM[i-1];
}

long long bs1(long long bound) {
    long long min=0, max=p, mid=0;

    while (min<max) {
        mid = (min+max)/2;
        if (pAttack[mid]-bound<=0) {
            min = mid+1;
        } else if (pAttack[mid-1]-bound<=0) {
            return mid;
        } else {
            max = mid;
        }
    }
    return mid;
}

long long bs2(long long bound) {
    long long min=0, max=m, mid=0;

    while (min<max) {
        mid = (min+max)/2;
        if (mAttack[mid]-bound<=0) {
            min = mid+1;
        } else if (mAttack[mid-1]-bound<=0) {
            return mid;
        } else {
            max = mid;
        }
    }
    return mid;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>p>>m;
    for (int i=0;i<n;i++) {
        cin>>u>>v;
        tanks[i][0] = u;
        tanks[i][1] = v;
    }
    for (int i=0;i<p;i++) {
        cin>>temp;
        pAttack.push_back(temp);
    }
    for (int i=0;i<m;i++) {
        cin>>temp;
        mAttack.push_back(temp);
    }
    sort(pAttack.begin(), pAttack.end());
    sort(mAttack.begin(), mAttack.end());
    computePrefix();

    long long minDamage = 1e15, totalDamage;
    long long bestTank=-1, d1, d2, negateIndP, negateIndM;
    for (int i=0;i<n;i++) {
        d1 = tanks[i][0];
        d2 = tanks[i][1];

        negateIndP = bs1(d1);
        negateIndM = bs2(d2);
        totalDamage = prefixP[p-1]-prefixP[negateIndP-1]-d1*(p-negateIndP) + prefixM[m-1]-prefixM[negateIndM-1]-d2*(m-negateIndM); 

        // cout<<"Neg: "<<negateIndP<<" total: "<<totalDamage<<endl;
    
        if (totalDamage<minDamage) {
            minDamage = totalDamage;
            bestTank = i+1;
        }
    }
    cout<<bestTank<<endl;
}