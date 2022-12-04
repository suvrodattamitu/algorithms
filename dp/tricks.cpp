//https://codeforces.com/contest/455/problem/A
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define lens(str) ((ll)str.length())
#define lena(arr) ((ll)arr.size()) 
#define pb push_back
const ll MOD = 1000000007;
const ll N = 1e5+10;
typedef vector<ll> vi;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i: v) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i: v) os << i << ' ';
    return os;
}

ll dp[N], cnt[N];
ll rec(ll x) {
    if(x <= 0) return 0;
	ll& ret = dp[x];
	if (ret != -1) return ret;
	ret = max(rec(x-1), cnt[x]*x + rec(x-2));
	return ret;
}

void solve() {
    ll n;
    get(n);
    
    memset(dp, -1, sizeof(dp));
    
    vi arr(n);
    rep0(i, n) {
       get(arr[i]);
       cnt[arr[i]]++;
    }
    
    ll res = rec(N-10);
    put(res);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1;
	//get(tc);
	
	while(tc--) {
	    solve();
	}

    return 0;
}