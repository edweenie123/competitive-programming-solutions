/*
~~~ DMOPC '18 Contest 1 P2 - Sorting ~~~

Key Concepts: Implementation, Sorting knowledge

Make the insight that if it is possible for all elements to jump to its correct indices:
    then it is possible to sort the array

Thus all we need to do is check if an element CAN jump to its correct indice:
    This is possible when i % k == nums[i] % k

*/

#include<bits/stdc++.h>
using namespace std;

int n, k;
int nums[101];

bool isPossible() {
    for (int i=1;i<=n;i++) {
        if (i%k!=nums[i]%k)
            return false;
    }
    return true;
}
int main() {
    cin>>n>>k;

    for (int i=1;i<=n;i++) 
        cin>>nums[i];
    
    cout << (isPossible() ? "YES" : "NO") << endl;
}