// Solved!
#include <bits/stdc++.h>
using namespace std;

int main (){
    while (true) {
        int c;
        cin>>c;
        if (c==-1) break;
        int candies[c] = {0};
        int sum=0;
        for (int i=0; i<c; i++) {
            int n;
            cin>>n;
            sum+=n;
            candies[i]=n;
        }
        if (sum%c==0) {
            int equal = sum/c;
            int moveC = 0;
            for (auto b: candies) {
                if (b>equal){
                    moveC += b-equal;
                }
            }
            cout<<moveC<<endl;
        } else cout<<-1<<endl;
    }
}