//https://codeforces.com/problemset/problem/630/H
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

#define ll long long 

#define MOD 1000000007
const int N = 101;

ll fact[N], invfact[N], inv[N];

void init()
{
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = -inv[MOD%i] * (MOD / i) % MOD;
    if (inv[i] < 0) inv[i] += MOD;
  }
  invfact[0] = 1;
  for (int i = 1; i < N; i++) {
    invfact[i] = invfact[i - 1] * inv[i] % MOD;
  }
}

ll nCk(ll n, ll k)
{
  return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

ll nPk(ll n, ll k)
{
  return fact[n] * invfact[n - k] % MOD;
}

void solve() {
	init();
	ll n;
	cin >> n;

	ll k = 5;
	ll ans = nCk(n, k) * nCk(n, k) * fact[k];
	cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int tc = 1 ;
    
    while(tc--) {
		solve();
	}

    return 0;
}

/*
3 7 4

"3377", "3737", "3773", "7337", "7373", "7733". 3 and 7
"4477", "4747", "4774", "7447", "7474", "7744". 4 and 7
"3344", "3434", "3443", "4334", "4343", "4433". 3 and 4
*/