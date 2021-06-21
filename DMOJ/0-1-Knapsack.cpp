/*
~~~ 0-1 Knapsack ~~~

Time Complexity: O(NS) N = # items, S = capcity of knapsack
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100+5;
const int MAX_S = 1e5 + 5;

int n, s;

long long value[MAX_N], weight[MAX_N], V[2][MAX_S];

long long knapsack() {
    for (int i=0;i<MAX_S;i++) 
        V[0][i] = 0;
 
    for (int i=1;i<=n;i++) {
        for (int w=0;w<=s;w++) {
            if (weight[i]<=w) 
                V[1][w] = max(V[0][w], value[i] + V[0][w-weight[i]]);
            else 
                V[1][w] = V[0][w];    
        }
        for (int w=0;w<=s;w++) V[0][w] = V[1][w];
    }

    return V[1][s];
}

void getInput() {
    cin>>n>>s;
    
    for (int i=1;i<=n;i++) 
        cin>>weight[i]>>value[i];
    
}

int main() {
    getInput();
    cout<<knapsack()<<endl;
}