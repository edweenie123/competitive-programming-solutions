/*
~~~ DMPG '19 B5 - Triangles ~~~

Key Concepts: Geometry

Key Insight:
    Sort all points by their x-cord --> A[n]
    If you form a triangle from A[i], A[i+1], A[i+2]:
        there will never be a another point inside the triangle

    Thus, the problem simplifies to finding 3 consecutive points in A[n] which are not the same color

*/

#include<bits/stdc++.h>
using namespace std;

int n;

vector<array<int, 4>> points;

bool different(int c1, int c2, int c3) {
    if (c1==c2&&c2==c3) return false;
    else return true;
}
int main() {
    cin>>n;

    int x, y, c;
    for (int i=0;i<n;i++) {
        cin>>x>>y>>c;
        points.push_back({x, y, c, i+1});
    }

    sort(points.begin(), points.end());

    for (int i=0;i<points.size()-2;i++) {
        int c1 = points[i][2], c2 = points[i+1][2], c3 = points[i+2][2];
        if (different(c1, c2, c3)) {
            cout<<points[i][3]<<" "<<points[i+1][3]<<" "<<points[i+2][3]<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}