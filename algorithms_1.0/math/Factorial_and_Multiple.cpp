//https://www.youtube.com/watch?v=lljQBhGdZws
//https://atcoder.jp/contests/abc280/tasks/abc280_d

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll k, ans = 1;
	
	cin >> k;
	
	for(ll p = 2; (p*p) <= k; p++) {
		ll a = 0;
		while(k%p == 0) k /= p, a++;
		
		ll n;
		for(n = p; ;n += p) {
			ll x = n;
			//finding contribution
			while(x%p == 0) x /= p, a--;
			
			if(a <= 0) break;
		}
		
		ans = max(ans, n);
	}
	
	ans = max(ans, k);
	
	cout << ans <<endl;
	
	return 0;
}

