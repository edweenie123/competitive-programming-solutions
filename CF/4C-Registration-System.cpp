// Key Concepts: Hashing

#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> database;
int main() {
    cin>>n;
    string name;
    while (n--) {
        cin>>name;
        if (!database.count(name)) {
            cout<<"OK"<<endl;
            database[name] = 1;
        } else {
            string numName = name + to_string(database[name]);
            database[name]++;
            cout<<numName<<endl;
        } 
    }
}