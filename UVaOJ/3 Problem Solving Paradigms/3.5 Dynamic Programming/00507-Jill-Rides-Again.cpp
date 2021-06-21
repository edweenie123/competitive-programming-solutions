/*
~~~ UVa 00507 - Jill Rides Again ~~~

Key Concepts: Kadane's Algorithm

Use Kadane's Algorithm (considered DP) to find the stops with yield the Maximum Range Sum Query
*/

#include <bits/stdc++.h>

using namespace std;

int b, s, niceness[20005];

pair<int,int> answer = {-1, -1};

void kadane() {
    int i=1, j=1, sum=0, ans=0, maxDif = 0;

    for (int n=0;n<s-1;n++) {
        sum += niceness[n];
        if (sum<0) {
            i=n+2;
            j=n+2;
            sum = 0;
        } else {
            j++;
            if (sum>ans) {
                maxDif = j-i;
                answer = make_pair(i, j);
            } else if (sum==ans) {
                if (j-i>maxDif) {
                    maxDif = j-i;
                    answer = make_pair(i, j);
                }
                
            }
            ans = max(sum, ans);
        }
        // cout<<"maxDif "<<maxDif<<" ans "<<answer.first<<" "<<answer.second<<endl;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin>>b;
    for (int t=1;t<=b;t++) {
        cin>>s;
        for (int i=0;i<s-1;i++) cin>>niceness[i];

        answer = {-1, -1};
        kadane();
        
        if (answer.first==-1) {
            cout<<"Route "<<t<<" has no nice parts"<<endl; 
        } else {
            cout<<"The nicest part of route "<<t<<" is between stops "<<answer.first<<" and "<<answer.second<<endl;
        }
    }
}