#include <bits/stdc++.h>
using namespace std;

int n, m;
int findMax() {
    int s = n-(m-1)-1;
    int max = ((s+1)*s)/2;
    return max;
}
int minArr[1000000001] = {0};
int findMin() {
    int ppl = n;
    int i = 0;
    while(ppl > 0) {
        minArr[0] += 1;
        i += 1;
        if (i==m) i=0;
        ppl -= 1;
    }
    int min=0;
    for (int i=0;i<m;i++) {
        min += ((minArr[i]-1)+1)*(minArr[i]-1)/2;
    }
    return min;
}
int main() {
    cin>>n>>m;
    int max = findMax();
    int min = findMin();
    cout<<min<<" "<<max<<endl;
}