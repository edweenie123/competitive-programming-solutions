/*
~~~ 519D - A and B and Interesting Substrings ~~~

Key Concepts: PSA, Map, Insight?

Weird problem

Let's contructs a PSA for the values of the string

The condition for an interesting subarray is as follows:
    Let the subarray be defined as [i, j]

    The subarray is interesting if:
        1. s[i] = s[j] AND 
        2. psa[j-1] - psa[i] = 0 -> psa[j-1] = psa[i]

With this in mind lets try to find the number of interesting subsequences that end at index p => x
    For this p, we want to find the number of starting indices k
        such that s[p] = s[k] and psa[p-1] = psa[k] (these are the condiction for interesting array)

        also k < p

    How do we find the # of k efficiently?
        We use a map to store the frequency of each prefix sum
        If we iterate through the indices in order -> it gurantees that k < p

My explanation is pretty bad



*/



#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;

int val[26];
long long psa[MAXN];
vector<int> idx[26];

map<ll, int> psaFreq;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int v;
    for (int i=0;i<26;i++) {
        cin>>val[i];
    }

    string s; cin>>s;
    s = ' ' + s;

    // build psa for s
    for (int i=1;i<s.length();i++) {
        psa[i] = psa[i-1] + val[s[i] - 'a'];
    }

    for (int i=1;i<s.length();i++) {
        idx[s[i]-'a'].push_back(i); // get idx of each char type
    }

    ll ans = 0;

    for (int i=0;i<26;i++) {

        psaFreq.clear(); 

        for (auto p : idx[i]) {

            // want to find # of k such that 
            // psa[p-1] - psa[k] = 0 -> psa[p-1] = psa[k]

            int numK = psaFreq[psa[p-1]];
            ans += numK;

            psaFreq[psa[p]]++;
        }
    }

    cout<<ans<<"\n";


}