/*
~~~ Cat Girls ~~~

Key Concepts: Dynamic Programming 

- Main Idea -
dp[i] denotes the maximum cuteness you can get when considering cat girls with indices 1-i

When a new cat girl is added to the line, we can either ignore it or take a picture of the newest cat girl

Thus, dp[i] = max(dp[i-1], opt) where opt is the maximum cuteness you can obtain if you include the right-most cat girl

To compute opt in O(log n) we store the pose-widths in a prefix sum array and use binary search to find L
    - where L is the index of the left-most cat girl in the photo to maximize total cuteness

Once this process is complete, we can compute opt (sum of cuteness from indices L->END)
    - Finding the sum of cutenesses can be further optimized by storing cutenesses in a prefix sum array as well

- Minor Details -
We can use the varible 'id' to keep track of the index of the right-most cat girl

After each cat girl can be processed, we increment id by 1

If a can girl leaves the line, we can simply decrement id by 1
    - This works because a cat girl will always exit from the right of the line: 
        Therefore, all the dp information computed before that cat girl is still valid
*/

#include <bits/stdc++.h>
using namespace std;

int n, id=1;
long long w, pose[500005], cute[500005], dp[500005];

int bs() {
    int low = 0, high = id, mid;

    int best = 0;
    while (low<=high) {
        mid = (low+high)/2;

        if (pose[id]-pose[mid]>w) low = mid+1;
        else {
            best = mid;
            high = mid-1;
        }
    }

    // printf("best %d\n", best);
    return best;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    cin>>n>>w;

    char t;
    int p, c;

    for (int i=0;i<n;i++) {
        cin>>t;

        if (t=='A') {
            cin>>p>>c;

            pose[id] = pose[id-1] + p;
            cute[id] = cute[id-1] + c;
            
            int bestL = bs();
            long long takeCG = cute[id] - cute[bestL];
            
            // cout<<"take that boi: "<<takeCG<<endl;
            dp[id] = max(dp[id-1], takeCG);

            cout<<dp[id]<<endl;

            id++;
        } else 
            id--;
        
    }
}