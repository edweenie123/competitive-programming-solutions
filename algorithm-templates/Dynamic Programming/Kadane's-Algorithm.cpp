/*
~~~ Kadane's Algorithm ~~~


*/

#include <bits/stdc++.h>

using namespace std;

int n, A[1000005];

int kadane() {
    int sum=0, ans=0;

    for (int i=0;i<n;i++) {
        sum += A[i]; // add each element to sum
        if (sum<0) // if sum gets below 0 -> reset it
            sum = 0;
        
        ans = max(ans, sum); // answer is the maximum value of sum
    }
    return sum;
}

int main () {
    cin>>n;
    for (int i=0;i<n;i++) cin>>A[i];

    cout<<kadane()<<endl;
}