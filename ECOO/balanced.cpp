/*
~~~ ECOO '18 R3 P1 - Balanced ~~~

The key to this problem to the count the number of unbalanced lines instead of balanced ones.

To do this, you have to realize that unbalanced lines are always in the form:
    g b*n g b*n g b*n g b*x

Where n is some even number (including 0) and b*x are just the left over bois. T

Thus, all we have to do is count the number of ways of ordering the ppl in that form for all values of n.

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e6 + 5;
const ll MOD = 1e9 + 7;

int b, g;
ll fact[MAXN];

void computeFact() {
    fact[0] = 1;

    for (ll i=1;i<MAXN;i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

int main() {
    // cin.sync_with_stdio(0); cin.tie(0);
    
    int t = 10;
    computeFact();

    while (t--) {
        cin>>b>>g;

        if (g==1) {
            cout<<0<<"\n";
            continue;
        }

        ll balanced = fact[b+g];
        ll excessBois, arrange;

        ll notBalanced = 0;
        for(ll gap = 0;; gap += 2){
            excessBois = b - (g - 1) * gap;
            
            if(excessBois < 0){
                break;
            }

            arrange = (fact[g] * fact[b]) % MOD; // arrange the ppl in groups
            arrange =  arrange * (excessBois + 1) % MOD; // arrange the excess bois

            notBalanced = (notBalanced + arrange) % MOD;
        }

        balanced = (balanced - notBalanced + MOD) % MOD;

        cout<<balanced<<"\n";
    }
    
}