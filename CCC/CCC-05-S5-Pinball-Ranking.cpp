/*
~~~ CCC '05 S5 - Pinball Ranking ~~~

Key Concepts: High IQ, Fenwick Tree

Idea: we give each score an order i which corresponds to its chronological order
So for the test case, we have:
    score | i
    ------|---
    100   | 1
    200   | 2
    150   | 3
    170   | 4
    50    | 5


Then imagine we have an array A, where A[i] returns 1 if the score with order i has been parsed
                                            returns 0 otherwise

Next, we sort the scores in non-decreasing order and build A in that order

Whenever we add a new score with order i to the array A
    We update A[i] = 1

    Everything in array A has a score <= the current score (because scores have been sorted)
    Thus, sum(A[1..i-1]) is the number of scores which are <= the current score WHEN IT IS ADDED CHRONOLOGICALLY

    Therefore, the current scores rank when it is added chronologically is given by:
        rank = i - sum(A[1..i-1])

To speed things up, we use a binary index tree to represent array A, so that we can:
    Perform sum(A[1..i-1]) in O(log n)
    And     update(i, 1)   in O(log n)

This gives total time complexity of O(n log n) as there are n queries
*/


#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define F first
#define S second
#define PB push_back

const int MAXT = 1e5+1;

int t;
int bit[MAXT];
vector<ii> scores;

void update(int k, int val) {
    while (k<=t) {
        bit[k] += val;
        k += k & -k;
    }
}

int query(int k) {
    int tot = 0;
    while (k>0) {
        tot += bit[k];
        k -= k & -k;
    }
    return tot;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>t;

    int tmp;
    for (int i=1;i<=t;i++) {
        cin>>tmp;
        scores.PB({tmp, i});
    }

    sort(scores.begin(), scores.end());

    double rankTot = 0;
    for (auto s : scores) {
        int order = s.S;
        update(order, 1);
        rankTot += order - query(order-1);
    }
    double ans = rankTot / t;
    printf("%.2f\n", ans);
}