/*
~~~ UVa 11413 - Fill the Containers ~~~

Key Concepts: Binary Search, Greedy

isPossibleCapacity() checks if it is possible to pour all vessels without overflowing the containers
    - Binary Search the optimal capacity (search space: capacity can be between 1 and 1B)
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int vessels[1005];

bool isPossibleCapacity(int c) {
    int contLeft = m, currCont = 0;

    for (int i=0;i<n;i++) {
        if (currCont + vessels[i] > c) {
           contLeft--;

           if (contLeft<=0) return false; 
           currCont = 0;
        }
        currCont += vessels[i];
        if (currCont>c) return false;
    }

    return true;
}

int bs() {
    int min = 1, max = 1e9, mid;
    
    int best = max+1;

    while (min<=max) {
        mid = (min+max)/2;
        // cout<<"mid "<<mid<<endl;
        if (isPossibleCapacity(mid)) {
            best = mid;
            max = mid-1;
        } else {
            min = mid+1;
        }
    }

    return best;
}

int main() {
    // freopen("input.txt", "r", stdin);
    while (cin>>n>>m) {
        
        for (int i=0;i<n;i++) 
            cin>>vessels[i];
        
        cout<<bs()<<endl;
    }
}