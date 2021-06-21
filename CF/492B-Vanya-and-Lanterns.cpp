// Key Concepts: Greedy Algorithms, Binary Search

#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<int> lan;

bool checkIfLit(double d) {
	if (lan[0]>d) {
        return false;
    } 
	if (l-lan.back()>d) {
        return false;
    }
    
	for (int i=0;i<n-1;i++) {
		if (lan[i+1]-lan[i]>2*d) {
			return false;
		}
	}
	return true;
}

double bs() {
	long double min = 0, max = l*1e11, ans = 1e100, mid;

	for (int i=0;i<50;i++) {
		mid = (min + max)/2;
		if (checkIfLit(mid/1e10)) {
			if (mid/1e10 < ans) ans = mid;
			max = mid;
		} else 
            min = mid+1;
	}
	return ans/1e10;
}

int main() {
  cin>>n>>l;
  int temp;
  for (int i=0;i<n;i++) {
	  cin>>temp;
	  lan.push_back(temp);
  }
  cout.precision(14);
  sort(lan.begin(), lan.end());
  long double ans = bs();
  cout<<ans<<fixed<<endl;
}