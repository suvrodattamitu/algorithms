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

ll n, a[100005], b[100005], c[100005], dp[100005][4];
ll rec(int idx, int prev) {
    if(idx == n) return 0;
    if(dp[idx][prev] != -1) return dp[idx][prev];
    
    ll ans = INT_MIN;
    if(prev == 0) {
        ans = max(ans, b[idx] + rec(idx+1, 1));
        ans = max(ans, c[idx] + rec(idx+1, 2));
    } else if(prev == 1) {
        ans = max(ans, a[idx] + rec(idx+1, 0));
        ans = max(ans, c[idx] + rec(idx+1, 2));
    } else if(prev == 2) {
        ans = max(ans, a[idx] + rec(idx+1, 0));
        ans = max(ans, b[idx] + rec(idx+1, 1));
    } else {
        ans = max(ans, c[idx] + rec(idx+1, 2));
        ans = max(ans, b[idx] + rec(idx+1, 1));
        ans = max(ans, a[idx] + rec(idx+1, 0));
    }
    
    return dp[idx][prev] = ans;
}

void solve() {
    get(n);
    rep0(i, n) cin >> a[i] >> b[i] >> c[i];
    
    memset(dp, -1, sizeof(dp));
    ll ans = rec(0, 3);
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