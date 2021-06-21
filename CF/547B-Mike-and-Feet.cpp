/*
~~~ 547B - Mike and Feet ~~~

Key Concepts: Stack, Suffix Max

Hard problem to understand imo

The main idea is to find the largest window that that uses each bear's height as the group strength

    To do this we need two steps:
        1. find how far we can go the left before we encounter a shorter bear => l[i]
        2. find how far we can go to the right before we count a shorter bear => r[i]

    We can do this in O(n) for all bears using a stack -> not too hard to come up with

With this done, we know the largest group size for every bear if that bear's height is the group strength

    Lets call this the window size of a bear

The key oberservation you need to make here is that 

    If you want to find the maximum strength of size x
        you care about all the bears w/
            a window size >= x
        
        All of these bears could the maximum strength boi
    
    Because we always care about the bears in a suffix
        -> we can use a suffix array to store the max element in every suffix

*/




#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define print(x) cout<<(#x)<<" = "<<x<<endl
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

int arr[MAXN];
int l[MAXN];
int r[MAXN];

int bestOfSize[MAXN];
int sufMax[MAXN];

void solve() {
    int n;
    cin>>n;

    for (int i=1;i<=n;i++) cin>>arr[i];

    stack<ii> s;

    for (int i=1;i<=n;i++) {
        int val = arr[i];
        while (true) {
            if (s.empty()) {
                l[i] = 1;
                s.push({val, i});
                break;
            }

            if (val <= s.top().fi) {
                s.pop();
            } else {
                l[i] = s.top().se + 1;
                s.push({val, i});
                break;
            }
        }
    }

    while (s.size()) s.pop();

    for (int i=n;i>=1;i--) {
        int val = arr[i];
        while (true) {
            if (s.empty()) {
                r[i] = n;
                s.push({val, i});
                break;
            }

            if (val <= s.top().fi) {
                s.pop();
            } else {
                r[i] = s.top().se - 1;
                s.push({val, i});
                break;
            }
        }
    }

    for (int i=1;i<=n;i++) {
        int len = r[i] - l[i] + 1;
        bestOfSize[len] = max(bestOfSize[len], arr[i]);
    }

    for (int i=n;i>=1;i--) {
        sufMax[i] = max(sufMax[i+1], bestOfSize[i]);
    }

    for (int i=1;i<=n;i++) {
        cout<<sufMax[i]<<" ";
    } cout<<endl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    solve();
}