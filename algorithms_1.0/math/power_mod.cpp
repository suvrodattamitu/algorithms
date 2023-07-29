//https://www.codechef.com/problems-old/JOGGING
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double 
#define MOD 1000000007

ll power_mod(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = (res * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

void solve() {
    ll n, x; 
	cin >> n >> x;

    ll ans = power_mod(2, n - 1);
    ans = (ans * x) % MOD;
    cout << ans << endl;
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