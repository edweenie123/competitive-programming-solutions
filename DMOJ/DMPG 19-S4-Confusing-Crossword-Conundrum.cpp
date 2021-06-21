/*
~~~ DMPG '19 S4 - Confusing Crossword Conundrum ~~~

Key Concepts: BFS Optimization

*/

#include<bits/stdc++.h>
using namespace std;

int n, m, q;

vector<vector<string>> allWords(100000); // letter -> words that start with that letter
vector<vector<int>> synonyms(100000); // word -> all synonyms for the word

unordered_map<string, int> wordToNum;

string optimal[26][100000];

void BFS(char src) {
    int ascii = (int)src-65;

    sort(allWords[ascii].begin(), allWords[ascii].end());  

    queue<int> q;
    
    for (auto w : allWords[ascii]) {
        q.push(wordToNum[w]);
        optimal[ascii][wordToNum[w]] = w;
    }

    while(!q.empty()) {
        int vert = q.front();
        q.pop();

        for (auto adj : synonyms[vert]) {
            if (optimal[ascii][adj].empty()) {
                q.push(adj);
                optimal[ascii][adj] = optimal[ascii][vert];
            } 
        }
    }
}

void precompute() {
    for (int i=65;i<=91;i++) 
        BFS((char)i);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>q;

    string word;
    for (int i=0;i<n;i++) {
        cin>>word;
        allWords[(int)word[0]-65].push_back(word);
        wordToNum[word] = i;
    }

    string s1, s2;
    for (int i=0;i<m;i++) {
        cin>>s1>>s2;
        synonyms[wordToNum[s1]].push_back(wordToNum[s2]);
        synonyms[wordToNum[s2]].push_back(wordToNum[s1]);
    }

    precompute();

    int ascii;
    string fin;
    char let;
    for (int i=0;i<q;i++) {
        cin>>fin>>let;
        ascii = (int)let-65;

        if (optimal[ascii][wordToNum[fin]].empty()) cout<<-1<<"\n";
        else cout<<optimal[ascii][wordToNum[fin]]<<"\n";
    }
}