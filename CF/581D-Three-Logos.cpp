/*
~~~ 581D - Three Logos ~~~

Key Concepts: Brute force, bitmask, geometry

The idea is simple, but the bf implementation is nasty

Insight 1:
Notice that the arrangement of the logos can only come in two different flavors

Type 1: -> all on top of each other
    AAA
    BBB
    CCC

Type 2: -> two on the same level and one at the bottom
    AABBB
    AABBB
    CCCCC
    CCCCC
    CCCCC

We can BF over all possible orders of the rectangles and every rotation 
    using std::next_permutation and bitmasks respectively


*/


#include<bits/stdc++.h>
using namespace std;

#define print(x) cout<<(#x)<<" = "<<(x)<<"\n";
struct rect {
    int w, h;
    char id;
};

vector<rect> r;

// try making type 1
bool type1(rect r1, rect r2, rect r3) {

    if (r1.w != r2.w || r2.w != r3.w) // all widths must be the same
        return false;

    if (r1.h + r2.h + r3.h == r1.w)
        return true;
    
    return false;
}

// try making type 2
bool type2(rect r1, rect r2, rect r3) {
    if (r1.h != r2.h) return false;
    if (r1.w + r2.w != r3.w) return false;
    if (r3.w != r1.h + r3.h) return false;

    return true;
}


int main() {
    int x1, y1, x2, y2, x3, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    r.push_back(rect{x1, y1, 'A'});
    r.push_back(rect{x2, y2, 'B'});
    r.push_back(rect{x3, y3, 'C'});

    vector<int> ord = {0, 1, 2};

    do {

        for (int bm=0;bm<8;bm++) { // try all rotations of the rectangles
            vector<rect> r_ = {r[ord[0]], r[ord[1]], r[ord[2]]};

            if (bm & (1<<0)) swap(r_[0].w, r_[0].h);
            if (bm & (1<<1)) swap(r_[1].w, r_[1].h);
            if (bm & (1<<2)) swap(r_[2].w, r_[2].h);


            if (type1(r_[0], r_[1], r_[2])) {
                cout<<r_[0].w<<"\n";

                for (auto a : r_) {
                    for (int i=0;i<a.h;i++) {
                        for (int j=0;j<a.w;j++)
                            cout<<a.id;
                    cout<<"\n";
                    }
                }

                return 0;
            }

            if (type2(r_[0], r_[1], r_[2])) {
                cout<<r_[2].w<<"\n";

                string line = "";
                for (int i=0;i<r_[0].w;i++) line += r_[0].id;
                for (int i=0;i<r_[1].w;i++) line += r_[1].id;
                for (int i=0;i<r_[0].h;i++) cout<<line<<"\n";

                for (int i=0;i<r_[2].h;i++) {
                    for (int j=0;j<r_[2].w;j++) cout<<r_[2].id;
                    cout<<"\n";
                }

                return 0;
            }

        }
        

    } while (next_permutation(ord.begin(), ord.end()));

    cout<<-1<<"\n";
}