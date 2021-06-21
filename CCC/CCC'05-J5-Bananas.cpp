/*
~~~ CCC '05 J5 - Bananas ~~~

Key Concepts: Recursion

Use recursion to create a function which determines if a string is an A-word
    - "A" || "B" + ML-word + "S"

Then use that function to determine if a string is a monkey language word
    - A-word || A-word + "N" + ML-word
*/

#include <bits/stdc++.h>
using namespace std;

string word;
bool isML (string);

bool isAWord(string w) {
    if (w=="A")
        return true;
    else if (w.length() > 2) {
        if (w[0]=='B' && isML(w.substr(1, w.length()-2)) && w.back()=='S')
            return true;
    }
    return false;
}

bool isML(string w) {
    if (isAWord(w)) 
        return true;
    else {
        for (int i=1;i<w.length();i++) {
            if (w[i]=='N') {
                if (isAWord(w.substr(0, i))) {
                    if (isML(w.substr(i+1, w.length()-i+1))) {
                        return true;
                    } else return false;
                }
            }
        }
        return false;
    }
}

int main() {
    while (true) {
        cin>>word;
        if (word=="X") break;
        isML(word) ? cout<<"YES" : cout<<"NO";
        cout<<endl;
    }
}

