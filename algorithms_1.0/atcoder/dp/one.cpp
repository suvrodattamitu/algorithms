//https://atcoder.jp/contests/abc237/tasks/abc237_f
#include <bits/stdc++.h>
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
#define len(x) ((ll)x.size()) 
#define pb push_back
const ll MOD = 998244353; //1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e3 + 8; //1e5+10;
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

int n, m, dp[N][12][12][12];
int rec(int idx, int l1, int l2, int l3) {
    if (idx == n) return l3 <= m;
    
    if (dp[idx][l1][l2][l3] != -1) return dp[idx][l1][l2][l3];
 
    int ans = 0;
    for (int d = 1; d <= m; d++) {
        if (d > l3) continue;
        else if (d > l2) ans += rec(idx+1, l1, l2, d);
        else if (d > l1) ans += rec(idx+1, l1, d, l3);
        else ans += rec(idx+1, d, l2, l3);
        ans %= MOD;
    }
 
    return dp[idx][l1][l2][l3] = ans;
}

void solve() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    int ans = rec(0, m+1, m+1, m+1);
    put(ans);
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tc = 1;
	//get(tc);
	while (tc--) {
		solve();
	}
}