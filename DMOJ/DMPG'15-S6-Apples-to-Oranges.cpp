/*
~~~ DMPG '15 S6 - Apples to Oranges ~~~

Key Concepts: BFS (or similar SSSP) 

Starting with 1 Apple as a source, use BFS to test out all possible exchanges
If at any point, we achieve more than 1 apple, the infinite apple plan is feasible 

To avoid infinite loops, we can use a map to store the most of a fruit we have had
If an exchange leads to a smaller amount of a particular fruit than the most we have had in the past don't add it to the queue

For some reason, you have to round the quantity of the fruits to the nearest 10 digits, or it won't pass
*/

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

typedef pair<string, long double> psd;

int n, m;
map<string, vector<psd>> exRate; // fruit --> [[f1, e1], [f2, e2]...]
map<string, long double> bestEx; //fruit --> best quant for fruit

bool BFS() {
    queue<psd> q; 
    q.push(make_pair("APPLES", 1));
    bestEx["APPLES"] = 1;

    while (!q.empty()) {
        psd node = q.front();
        q.pop();
        
        string type = node.f;
        long double quant = node.s;
        
        for (auto choice : exRate[type]) {
            string newType = choice.f;
            long double newQuant = round(quant * choice.s * 10000000000)/10000000000;

            if (bestEx.find(newType)==bestEx.end()) {
                q.push(make_pair(newType, newQuant));
                bestEx[newType] = newQuant;
            } else if (bestEx[newType]<newQuant) {
                if (newType=="APPLES") 
                    return true;
                q.push(make_pair(newType, newQuant));
                bestEx[newType] = newQuant;
            }
        }

    }   
    return false;
}

int main() {
    cin>>n>>m;
    
    string temp;
    for (int i=0;i<n;i++) 
        cin>>temp;
    
    string f1, f2;
    long double ex;
    for (int i=0;i<m;i++) {
        cin>>f1>>f2>>ex;
        if (exRate.find(f1)==exRate.end()) 
            exRate[f1] = {make_pair(f2, ex)};
        else 
            exRate[f1].push_back(make_pair(f2, ex));
        
    }
    BFS() ? cout<<"YA" : cout<<"NAW";
}