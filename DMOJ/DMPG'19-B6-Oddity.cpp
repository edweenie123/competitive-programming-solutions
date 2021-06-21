/*
~~~ DMPG'19 B6 - Oddity ~~~

Key Concepts: Simple Math

Key Insight:
    Si = # of stamps of friend i
    t = # of stamps that Alice has

    if Si+t is odd --> there are an odd # of distinct stamps between Alice and friend i
    else --> it is not possible to have an odd # of distinct stamps

    The problem simplfies to checking if Si is odd or even:
        if even: Alice only needs 1 stamp (output cheapest stamp)
        if odd: Alice needs 2 stamps (output cheapest stamp + 2nd cheapest stamp)
*/

#include<bits/stdc++.h>
using namespace std;

int n, k, c[500];
int main() {
    cin>>n>>k;
    for (int i=0;i<k;i++) cin>>c[i];

    sort(c, c+k);

    int cnt=0, temp, even;

    for (int i=0;i<k;i++) {
        cin>>temp;
        if (temp) cnt++;
    }
    cnt % 2==0 ? even=1 : even=0;

    int newEven, isPos=1;
    for (int i=1;i<n;i++) {
        cnt=0;
        for (int j=0;j<k;j++) {
            cin>>temp;
            if (temp) cnt++;
        }
        cnt % 2==0 ? newEven=1 : newEven=0;

        if (even!=newEven&&isPos) {
            cout<<-1<<endl;
            isPos=0;
        }
    }
    if (isPos) {
        if (even) cout<<c[0]<<endl;
        else cout<<c[0]+c[1]<<endl;
    }
}