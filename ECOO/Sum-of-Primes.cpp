#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int MAXN = 1e7 + 1;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n;
bool marked[MAXN];
// vector<int> primes; int numP;


void sieve() {
    for (int p=2;p*p<=MAXN;p++) {
        if (!marked[p]) {
            for (int i=p*p;i<=MAXN;i+=p) 
                marked[i] = true; 
        }
    }

}

// returns (x,y) such that x+y=num and min(x,y) is maximized
ii twoBoi(int num) {

    int x, y;
    for (x=num/2;x>2;x--) {
        if (marked[x]) continue;
        y = num - x; 
        if (marked[y]) continue;
        
        return ii{x, y};
    }

}

// returns (x,y,z) such that x+y+z=num and min(x,y,z) is maximized
iii threeBoi(int num) {
    int x, y, z;
    ii pot;
    for (x=num/3;x>2;x--) {
        if (marked[x]) continue;
        pot = twoBoi(num-x); y = pot.f, z = pot.s;
        
        if (x>y) continue;
        return iii{x, ii{y, z}};
    }
    // return iii{-1, ii{-1, -1}};
}

void solve() {
    if (!marked[n]) {
        cout<<n<<" = "<<n<<"\n";
    } else if (n%2==0) {
        ii ans = twoBoi(n);
        cout<<n<<" = "<<ans.f<<" + "<<ans.s<<"\n";
    } else {
        iii ans = threeBoi(n);
        cout<<n<<" = "<<ans.f<<" + "<<ans.s.f<<" + "<<ans.s.s<<"\n";
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int TESTS = 5;
    sieve();
  

    while (TESTS--) {
        cin>>n;
        solve();
    }
}