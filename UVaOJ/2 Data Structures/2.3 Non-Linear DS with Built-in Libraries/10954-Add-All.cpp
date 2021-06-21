/*
~~~ UVa 10954 Add All ~~~

Key Concepts: Priority Queue

Greedy Solution
    - Always add the 2 smallest numbers you have
    - After adding, remember push the sum into the priority queue 
*/

#include <bits/stdc++.h>

using namespace std;

int n, a, b, cost, temp;


int main() {
    while (true) {
        cin>>n;
        if (n==0) break;

        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i=0;i<n;i++) {
            cin>>temp;
            pq.push(temp);
        }

        cost = 0;
        for (int i=0;i<n-1;i++) {
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();

            cost += a+b;
            pq.push(a+b);
        }
        cout<<cost<<endl;
    }
}