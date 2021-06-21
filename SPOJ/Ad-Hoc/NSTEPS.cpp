// Solved!
#include <bits/stdc++.h>
using namespace std;

int nums[1000000][2];

void genNums() {
    int c = 0;
    int x = 0;
    int y = 0;
    nums[0][0]=0;
    nums[0][1]=0;
    for (int i=1;i<=200000;i++){
        if (c==0) {
            x += 1;
            y += 1;
        } else if (c==1) {
            x += 1;
            y -= 1;
        } else if (c==2) {
            x += 1;
            y += 1;
        } else if (c==3) {
            x -= 1;
            y += 1;
        }
        nums[i][0] = x;
        nums[i][1] = y;
        c += 1;
        if (c > 3) c=0;
    }
}

int main () {
    int t;
    cin>>t;

    genNums();

    while (t--) {
        int x,y;
        cin>>x>>y;
        bool found = false;
        for (int i=0; i<=200000;i++) {
            if (nums[i][0]==x&&nums[i][1]==y) {
                found = true;
                cout<<i<<endl;
                break;
            }
        }
        if (!found) {
            cout<<"No Number"<<endl;
        }
    }
}