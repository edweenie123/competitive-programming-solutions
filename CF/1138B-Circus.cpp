/*
~~~ 1138B - Circus ~~~

Key Concepts: Brute Force, Math

Interesting bf + math problem;
    -> i feel like its possible to solve in O(n)??

Insight 1:
There are only really 4 types of people
    a : acrobat and circus boi
    b : only circus boi
    c : only acrobat boi
    d : useless boi who can't do anything

Lets define delta as the 
    # of acrobats in the 2nd perforance - # of circus bois in the 1st performance

Of course, we want delta to be 0

Initially we set delta = a + c because we haven't picked anyone in the first performance yet
    -> so we assume everyone goes to the 2nd performane

Let see how selecting each type of boi affects delta:

    Select...
        a -> delta -= 2
        b -> delta -= 1
        c -> delta -= 1
        d -> delta stays same
    
    We can see that b and c have no functional difference

    Thus we can bf over the number of d's we take
        and figure out some way to reach a delta of 0
            using some number of a's b's and c's


                => i think there is so math formula you can use here???

            But you can also bf over the number of a's we take here
                cause the bounds are small

*/



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 5e3 + 5;
const ll MOD = 1e9 + 7;

int circ[MAXN], acro[MAXN];

void solve() {
    int n;
    cin>>n;

    char t;
    
    for (int i=1;i<=n;i++) {
        cin>>t;
        circ[i] = t - '0';
    }

    for (int i=1;i<=n;i++) {
        cin>>t;
        acro[i] = t - '0';
    }

    int delta = 0;
    int a=0, b=0, c=0, d=0;

    for (int i=1;i<=n;i++) {
        if (circ[i] && acro[i]) a++, delta++;
        else if (circ[i]) b++;
        else if (acro[i]) c++, delta++;
        else d++;
    }

    bool flag = false;

    int doubles, singles, zeros;

    // bf over the number of d's to take
    for (int i=0;i<=min(d, n/2);i++) {
        int moves = n/2 - i;

        // bf over the number of a's to take

        for (int j=0;j<=min(a, moves);j++) {
            
            int newMoves = moves - j;

            // b's and c's are identical??

            int newDel = delta - 2*j;

            if (newMoves == newDel && b+c >= newMoves) {
                
                // found answer 

                flag = true;

                doubles = j;
                singles = newMoves;
                zeros = i;

            }
        }
    }

    if (flag) {

        for (int i=1;i<=n;i++) {
            // print(singles);
            if (acro[i] && circ[i] && doubles) {
                cout<<i<<" ";
                doubles--;
            } else if (((acro[i] && !circ[i]) || (!acro[i] && circ[i])) && singles) {
                cout<<i<<" ";
                singles--;
            } else if (!acro[i] && !circ[i] && zeros) {
                cout<<i<<" ";
                zeros--;
            }
        }

        cout<<endl;
        return;
    }

    cout<<-1<<endl;

}

int main() {
    solve();
}