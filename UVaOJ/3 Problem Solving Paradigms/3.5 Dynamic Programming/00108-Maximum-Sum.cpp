/*
~~~ UVa 00108 - Maximum Sum ~~~

Key Concepts: DP

Find the Maximum Sub-Matrix sum

A[i][j] stores the sum from points (0, 0) and (i, j)
    - This way, the sum of (i, j) -> (k, l) can be computed in O(1)

*/

#include <bits/stdc++.h>

using namespace std;

int n, A[100][100];


int findMax() {
    int maxSum = -127*100*100, sum;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            for (int k=i;k<n;k++) {
                for (int l=j;l<n;l++) {
                    // compute sum in O(1)
                    sum = A[k][l];

                    if (i > 0) sum -= A[i - 1][l];
                    if (j > 0) sum -= A[k][j - 1];
                    if (i >0&&j>0) sum += A[i-1][j-1];

                    maxSum = max(maxSum, sum);
                }
            }
        }
    }

    return maxSum;
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin>>n;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>A[i][j];
            if (j>0) A[i][j] += A[i][j-1]; // if possible add from left
            if (i>0) A[i][j] += A[i-1][j]; // if possible add from top
            if (i>0&&j>0) A[i][j] -= A[i-1][j-1]; // avoid double counting
        }
    }
    cout<<findMax()<<endl;
}