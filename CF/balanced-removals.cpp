#include<bits/stdc++.h>
using namespace std;

struct point {
    int id;
    int x, y, z;
};

bool cmp(point a, point b) {
    if (a.x==b.x) {
        if (a.y==b.y) 
            return a.z < b.z;
        return a.y < b.y;
    }
    return a.x < b.x;
}

int n;
vector<point> points;

int main() {
    cin>>n;

    int x, y, z;
    for (int i=1;i<=n;i++) {
        cin>>x>>y>>z;
        points.push_back(point{i, x, y, z});
    }

    sort(points.begin(), points.end(), cmp);

    for (int i=0;i<points.size();i+=2) {
        cout<<points[i].id<<" "<<points[i+1].id<<"\n";
    }
}