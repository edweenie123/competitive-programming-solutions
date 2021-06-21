// Key Concepts: Binary Search

#include <bits/stdc++.h>
using namespace std;

int n, d, temp;
vector<int> prices;
long long m;

int bs(long long coins) {
	int min=0, max=n, mid, ans=-1;

	while (min<max) {
		mid = (min+max)/2;
		if (prices[mid]<=coins) {
			if (mid>ans) ans=mid;
			min = mid+1;
		} else {
			max = mid;
		}
	}
	return ans+1;
}

int main() {
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>temp;
		prices.push_back(temp);
	}
	sort(prices.begin(), prices.end());
	cin>>d;
	for(int i=0;i<d;i++) {
		cin>>m;
		int ans = bs(m);
		cout<<ans<<endl;
	}

}
