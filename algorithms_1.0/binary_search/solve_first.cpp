//https://www.codechef.com/CCLS2022/submit/WCESTR
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>

using namespace std;
#define ll long long

void solve() {
	ll n, k;
	cin >> n >> k;

	if(k >= n) cout << n << endl;
	else {
		ll low = 0, high = k, ans, mid;
		while (low <= high)
		{
			mid = (low+high)/2;
			
			ll sum = 0, t = mid;
			sum = mid + ((k - mid) * 4); 
			if (sum >= n) {
			    low = mid+1;
				ans = mid;
			} else {
				high = mid-1;
			}
		}

		cout << ans << endl;
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
	cin >> tc;

    while(tc--) {
		solve();
	}

    return 0;
}