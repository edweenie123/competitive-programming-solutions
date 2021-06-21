// Greedy approach
// Distribute the sum in a way that would max/min the number

#include <bits/stdc++.h>
using namespace std;

int m,s;

int maxDigits[100] = {0};
string findMax() {
    int sumLeft = s;
    for (int i=0;i<m;i++) {
        if (sumLeft>=9){
            maxDigits[i]=9; 
            sumLeft-=9;
        }    
        else{
            maxDigits[i] = sumLeft;
            break;
        }
    }
    string ans = "";
    for (int i=0;i<m;i++) {
        ans += to_string(maxDigits[i]);
    }
    return ans;
}

int minDigits[100] = {0};
string findMin() {
    int sumLeft = s;
    for (int i=m-1;i>=0;i--) {
        if (sumLeft > 9){
            minDigits[i]=9;
            sumLeft-=9;
        } else{
            if (i!=0){
                minDigits[i] = sumLeft-1;
                sumLeft = 1;
            } else {
                minDigits[i] = sumLeft;
            }
        } 
    }
    string ans = "";
    for (int i=0;i<m;i++) {
        ans += to_string(minDigits[i]);
    }
    return ans;
}
int main() {
    cin>>m>>s;
    if (9*m<s||(s==0&&m!=1)) {
        cout<<-1<<" "<<-1<<endl;
    } else {
        cout<<findMin()<<" "<<findMax()<<endl;
    }
}