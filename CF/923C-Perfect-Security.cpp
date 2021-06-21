/*
~~~ 923C - Perfect Security ~~~

Key Concepts: Trie, Greedy

Notice that we always want to minimize the first element of O
    -> remove the key, and then repeat for the 2nd element of O

How can we minimize the values of O efficiently?

    Notice that always want to optimize the most significant bits first
        before optimizing the less significant bits

        Therefore we can model all the keys as a trie (most significant bits at the top)
            and iterate through each bit of the key in the trie

            We always want the bits to match between the message and the key    
                -> if we do this we will minimize the xor

Because iterating through the trie takes O(log (max Element))
    -> the total time complexity is O(n log n)

*/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 3e6 + 5;
const int b = 30;
const ll MOD = 1e9 + 7;

int n;
int mes[MAXN];

int trie[MAXN*2][2]; // stores the id of child
int freq[MAXN*2]; // stores the freq an id is used
int ans[MAXN]; // stores the answers

int nxtId = 2;

void insert(int val) {

    int id = 1; // initially at root

    for (int i=b;i>=0;i--) {
        bool on = (1<<i) & val;

        if (trie[id][on]==-1) // boi has no children
            trie[id][on] = nxtId++;
        
        id = trie[id][on]; // go down child
        freq[id]++;
    }   
}

void remove(int val) {

    int id = 1; // initially at root

    for (int i=b;i>=0;i--) {
        bool on = (1<<i) & val;

        id = trie[id][on]; // go down child
        freq[id]--; // decrement frequency
    }  
}

int bestKey(int val) {

    int id = 1;
    int key = 0;

    for (int i=b;i>=0;i--) {

        bool on = (1<<i) & val;

        bool bitOn = false;            
        int child = trie[id][on]; // this is the child we want

        if (child != -1 && freq[child]) { // check if child exists
            id = trie[id][on];
            bitOn = on;
        } else { // can't get the child we want
            id = trie[id][!on]; 
            bitOn = !on;
        }

        if (bitOn) key |= (1<<i);
    }

    return key;
}

void solve() {
    cin>>n;

    memset(trie, -1, sizeof(trie));

    for (int i=1;i<=n;i++) cin>>mes[i];

    int k;
    
    for (int i=1;i<=n;i++) {
        cin>>k;
        insert(k);
    }

    for (int i=1;i<=n;i++) {
        int key = bestKey(mes[i]);
        ans[i] = mes[i]^key;
        remove(key);
    }

    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}