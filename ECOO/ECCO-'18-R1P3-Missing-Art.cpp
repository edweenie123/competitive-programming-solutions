#include <bits/stdc++.h>
using namespace std;

int main() {
 
    for (int test=0;test<10;test++) {
        int n,x,y,z;
        cin>>n>>x>>y>>z;
        vector<string> ans;
        for (int i=0;i<n;i++) {
            string code;
            string convert = "";
            cin>>code;
            for (int c=0;c<code.length();c++) {
                int cInt = stoi(code.substr(c,1));
                if (cInt==0) convert+=to_string(z);
                else if (cInt%2==0) convert+=to_string(cInt+x);
                else convert+= to_string(max(cInt-y,0)); 
            }
            ans.push_back(convert);
        }
        string temp;
        cin>>temp;

        vector<int> fail;
        bool pass = true;
        for (int i=0;i<n;i++) {
            string check;
            cin>>check;
            if (ans[i]!=check) {
                pass = false;
                fail.push_back(i+1);
            }
        }
        if (pass) cout<<"MATCH";
        else {
            cout<<"FAIL: ";
            for (int i=0;i<fail.size();i++) {
                if (i) cout<<",";
                cout<<fail[i];
            }
        }
        cout<<endl;
        cin>>temp;
    }
}