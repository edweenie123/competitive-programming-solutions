// Solved!
#include <iostream>

using namespace std;

long long int factorial(int n) {
    long long int f[101];
    f[0] = 1;
    for (int i=2;i<=n;i++) {
        f[i-1] = f[i-2] * i;
    }

    return f[n-1];
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << factorial(n) << endl;
    }
}