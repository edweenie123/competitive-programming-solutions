/*
~~~ 380C - Sereja and Brackets ~~~

Key Concepts: Segment Tree

The solution of the algorithm stems from the following question:

If you know the maximum length for two contigous segments,
    can you find the maximum length when you merge the segments?

When you append two valid bracket sequences together, the concatenation is also valid
    so its tempting to just say the maximum length when you merge the segments is just
        len1 + len2 where len1 is the length for the first segment and len2 is the length for the second segment

However, this method of merging the segment is incorrect, 
    Consider the following counter example:

        left = "()(" => maxLen = 2
        right = ")()" => maxLen = 2

    The above algorithm will return 4, but the answer is actually 6

    Thus, we must also consider the leftover '(' and ')' in each segment 

    Once you know this, the merging process is pretty intuitive 
        (look at code if you don't understand)
    
Once you know all of this, you can implement a segment tree to answer the queries in log n
    every node in the segment tree is a segment

*/


#include<bits/stdc++.h>
using namespace std;

string s;
int n, m;

const int MAXN = 1e6 + 5;

struct nodeInfo {
    int len; // length of longest subsequence
    int begLeft; // '(' leftover
    int endLeft; // ')' leftover
};

nodeInfo seg[MAXN * 4];

void build(int node, int l, int r) {
    if (l==r) {
        seg[node] = {0, s[l]=='(', s[l]==')'};
    } else {
        int mid = (l + r) / 2;
        build(node*2, l, mid);
        build(node*2+1, mid+1, r);

        nodeInfo c1 = seg[node*2], c2 = seg[node*2+1];

        int extra = min(c1.begLeft, c2.endLeft);

        int newLen = c1.len + c2.len + extra*2;
        int newBegLeft = c1.begLeft + c2.begLeft - extra;
        int newEndLeft = c1.endLeft + c2.endLeft - extra;
        seg[node] = {newLen, newBegLeft, newEndLeft};
    }
}

nodeInfo query(int node, int l, int r, int ql, int qr) {
    if (ql>r || qr < l) return {0, 0, 0};

    if (l>=ql&&qr>=r) 
        return seg[node];
    
    int mid = (l+r) / 2;

    nodeInfo c1 = query(node*2, l, mid, ql, qr);
    nodeInfo c2 = query(node*2+1, mid+1, r, ql, qr);

    int extra = min(c1.begLeft, c2.endLeft);

    int newLen = c1.len + c2.len + extra*2;
    int newBegLeft = c1.begLeft + c2.begLeft - extra;
    int newEndLeft = c1.endLeft + c2.endLeft - extra;

    return nodeInfo{newLen, newBegLeft, newEndLeft};
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin>>s; n = s.length();
    s = ' ' + s; // add dummy value

    cin>>m;
    build(1, 1, n);

    int l, r;  
    while (m--) {
        cin>>l>>r;
        int ans = query(1, 1, n, l, r).len;
        cout<<ans<<"\n";
    }
}