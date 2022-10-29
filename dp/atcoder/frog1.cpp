//https://atcoder.jp/contests/dp/tasks/dp_a
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
const int MOD = 1000000007;
const int N = 1e5+10;
typedef vector<ll> vi;

ll h[N], dp[N];

ll rec(ll n) {
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    
    ll cost = INT_MAX;
    //way one
    cost = min(cost, rec(n-1) + abs(h[n] - h[n-1]));
    //way two
    if(n > 1) {
        cost = min(cost, rec(n-2) + abs(h[n] - h[n-2]));
    }
    
    return dp[n] = cost;
}

void solve() {
	ll n;
	get(n);

    memset(dp, -1, sizeof(dp));
	rep0(i, n) get(h[i]);
	
	ll ans = rec(n-1);
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