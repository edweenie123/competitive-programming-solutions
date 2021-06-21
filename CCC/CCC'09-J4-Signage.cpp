/*
~~~ CCC '09 J4 - Signage ~~~

Key Concepts: Stupid Implementation

*/

#include <bits/stdc++.h>
using namespace std;

int w;

vector<string> words = {
    "WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"
};

int main() {
    cin>>w;

    int wordInd = 0;
    while (true) {
        if (wordInd==6) break;
        int charUsed = 0;

        vector<string> line;
        for (int i=wordInd;i<words.size();i++) {
            string c = words[i];
            if (charUsed + c.length() > w - line.size()) break;

            line.push_back(c);
            charUsed += c.length(); 
        }
        wordInd += line.size();
        // for (auto c : line) cout<<c<<" ";
        int spaces[20] = {0};

        int spacesLeft = w - charUsed;
        // printf("spaces left %d line size %d\n", spacesLeft, line.size());


        for (int i=0;i<spacesLeft;i++) {
            if (line.size()==1) spaces[0]++;
            else spaces[i%(line.size()-1)]++;
        } 

        string out = "";
        for (int i=0;i<line.size()-1;i++) {
            out += line[i];
            for (int j=0;j<spaces[i];j++) out += ".";
            // cout<<"out ->"<<out<<endl;
        }
        out += line.back();
        if (line.size()==1) for (int j=0;j<spaces[0];j++) out += ".";

        cout<<out<<endl;

    }
}