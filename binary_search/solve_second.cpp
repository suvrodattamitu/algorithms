//https://www.codechef.com/JULY222D/problems/BURGERS2
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <string>

using namespace std;

#define ll long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define F first
#define S second
#define pb push_back
#define all(a) (a.begin()), (a.end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int,int> mpp;
typedef pair<ll,ll> pll;

void solve() 
{
	ll x, y, n, r;
	cin >> x >> y >> n >> r;

	ll mn = min(x, y);

	ll total = mn*n;
	if(r < total) {
		cout << -1 << endl;
		return;
	}

	if(mn == y) {
		if(total <= r) {
			cout << 0 << " " << n << endl;
		} else {
			cout << -1 << endl;
		}

		return;
	}


	ll low = 0, high = n, ans = 0;

	while(low <= high) {
		ll mid = (low+high) / 2;

		ll total = (mid * y) + ((n-mid) * x);
		if(total <= r) {
		    low = mid + 1;
			ans = mid;
		} else {
		    high = mid - 1;
		}
	}
	
	ll curTotal = ((n - ans) * x) + (ans * y);
	if(curTotal > r) {
	    cout << -1 << endl;
	    return;
	}

	cout << n - ans << " " << ans << endl;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
	cin >> tc;
    while(tc--) {
		solve();
	}

    return 0;
}