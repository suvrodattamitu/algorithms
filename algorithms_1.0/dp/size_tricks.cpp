//https://atcoder.jp/contests/abc275/tasks/abc275_d
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define rrep0(i, n) for(int i = n-1; i >= 0; i--)
#define rrep1(i, n) for(int i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define lens(str) ((int)str.length())
#define lena(arr) ((int)arr.size()) 
#define pb push_back
const int MOD = 998244353;
const ll N = 1e8+10;
typedef vector<ll> vi;

unordered_map<ll, ll> dp;

ll f(ll n) {
    if(n == 0) return 1;
    
    if(dp.count(n)) return dp[n];
    
    dp[n] = f(n/2) + f(n/3);
    
    return dp[n];
}

void solve() {
    ll n;
    get(n);
    
    ll ans = f(n);
    put(ans);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1 ;
	//get(tc);
	
	while(tc--) {
	    solve();
	}

    return 0;
}