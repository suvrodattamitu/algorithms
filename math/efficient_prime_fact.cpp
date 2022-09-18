//https://codeforces.com/problemset/problem/1165/D
//failed in codechef
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<long long> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	sort(a.begin(), a.end());

	long long x = a[0] * a[n-1];
	vector<long long> b;

	//without 1 and x all divisors are found
	for(int i = 2; i * 1ll * i <= x; i++) { // i  * i * 1ll gives tle
		if(x%i == 0) {
		    b.push_back(i);
			if(i != x/i) {
                b.push_back(x/i);
            } 
		}	
	}
	
	sort(b.begin(), b.end());

	if(a == b) cout << x << endl;
	else cout << -1 << endl;
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