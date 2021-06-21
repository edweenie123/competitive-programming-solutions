/*
~~~ UVa 11995 - I Can Guess the Data Structure! ~~~

Key Concepts: Priority Queue, Queue, Stack

Assume the DS can be only of the three (PQ, Q, S)

If the DS returns a value that PQ/Q/S does not: remove it 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin>>n) {
        bool pos[3] = {1, 1, 1};

        stack<int> s; queue<int> q; priority_queue<int> pq;
        int type, num;
        for (int i=0;i<n;i++) {
            cin>>type;
            cin>>num;
            if (type==1) {
                if (pos[0]) s.push(num);
                if (pos[1]) q.push(num);
                if (pos[2]) pq.push(num); 
            } else {
                if (pos[0]) {
                    if (!s.empty()&&s.top()==num) s.pop();
                    else pos[0]=0;
                }
                if (pos[1]) {
                    if (!q.empty()&&q.front()==num) q.pop();
                    else pos[1]=0;
                }
                if (pos[2]) {
                    if (!pq.empty()&&pq.top()==num) pq.pop();
                    else pos[2]=0;
                }
            }
        }

        int on = pos[0]+pos[1]+pos[2];
        if (on==0) cout<<"impossible"<<endl;
        else if (on>1) cout<<"not sure"<<endl;
        else {
            if (pos[0]) cout<<"stack"<<endl;
            if (pos[1]) cout<<"queue"<<endl;
            if (pos[2]) cout<<"priority queue"<<endl;
        }

    }
}