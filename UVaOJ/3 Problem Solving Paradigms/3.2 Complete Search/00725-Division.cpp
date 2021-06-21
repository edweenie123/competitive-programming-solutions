/*
~~~ UVa 00725 - Division ~~~

Key Concepts: Iterative Complete Search

The range of fghij is 1234 - 98765
    - Iterate through this range and check if abcde and fghij are unique digits

*/


#include <bits/stdc++.h>

using namespace std;

int abcde, fghij, n;

bool isUnique(int a, int b) {
    set<int> digits;

    while (a) {
        digits.insert(a%10);
        a /= 10;
    }

    while (b) {
        digits.insert(b%10);
        b /= 10;
    }
    
    if (digits.size()==10) return true;
    return false;
}

int main() {
    bool space = false;
    while (cin>>n) {
        if (n==0) break;
        if (space) cout<<"\n";
        space = true;
        bool found = false;
        for (int i=1234;i<=100000/n;i++) {
            
            int val1, val2;

            fghij = i;
            abcde = fghij * n;

            if (abcde < 10000) val1 = abcde * 10;
            else val1 = abcde;

            if (fghij < 10000) val2 = fghij * 10;
            else val2 = fghij;

            if (isUnique(val1, val2)) {
                found = true;
                string ans1, ans2;

                if (abcde < 10000) ans1 = "0" + to_string(abcde);
                else ans1 = to_string(abcde);

                if (fghij < 10000) ans2 = "0" + to_string(fghij);
                else ans2 = to_string(fghij);

                cout<<ans1<<" / "<<ans2<<" = "<<n<<"\n";
            }
        }

        if (!found) cout<<"There are no solutions for "<<n<<".\n";
        
    }
}