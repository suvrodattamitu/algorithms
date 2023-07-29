//https://codeforces.com/contest/1709/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define F first
#define S second
#define pb push_back
#define all(a) (a.begin()), (a.end())
typedef vector<ll> vi;

void solve() 
{
	ll n, m;
	cin >> n >> m;

	vi a(n), pre(n), suf(n);
	rep0(i, n) cin >> a[i];

	pre[0] = 0;
	rep0(i, n) {
		if(a[i-1] > a[i]) {
			pre[i] = pre[i-1] + (a[i-1] - a[i]);
		} else {
			pre[i] = pre[i-1];
		}
	}
	
	suf[n-1] = 0;
	for(int i = n-2; i >= 0; --i) {
		if(a[i+1] > a[i]) {
			suf[i] = suf[i+1] + (a[i+1] - a[i]);
		} else {
			suf[i] = suf[i+1];
		}
	}

	ll s, t;
	while(m--) {
		cin >> s >> t;
		--s; --t;
		
		ll ans = 0;
		if(t >= s) {
    		ans = pre[t] - pre[s];
		} else {
		    ans = suf[t] - suf[s];
		}

    	cout << ans << endl;
	}
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
	//cin >> tc;
    while(tc--) {
		solve();
	}

    return 0;
}