//https://atcoder.jp/contests/abc281/tasks/abc281_d
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
const long long oo = 1e16;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

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

vi arr(110);
ll n, k, d, dp[110][110][110];
ll rec(ll i, ll taken, ll rem) {
    if(taken == k) return (rem == 0) ? 0 : -oo;
    if(i == n) return -oo;
    if(dp[i][taken][rem] != -1) return dp[i][taken][rem];
    ll cur_ans = max(rec(i+1, taken, rem), rec(i+1, taken+1, (rem+arr[i])%d) + ((rem+arr[i])/d)); 
    return dp[i][taken][rem] = cur_ans;
}

void solve() {
    cin >> n >> k >> d;
    memset(dp, -1, sizeof(dp));
    rep0(i, n) get(arr[i]);
    ll ans = rec(0, 0, 0);
    if(ans < 0) ans =-1;
	else ans *= d;
	put(ans);
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