// Solved!

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    string s;
    cin>>n>>t;
    cin>>s;

    vector<int> indices;
    for (int i=0;i<t;i++) {
        for (int j=0; j<n-1;j++) {
            if (s.substr(j,2)=="BG") {
                indices.push_back(j);
            }
        }
        for (auto in : indices) {
            s.replace(in, 2, "GB");
        }
    }
    cout<<s;
}