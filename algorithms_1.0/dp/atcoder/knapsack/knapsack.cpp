//https://atcoder.jp/contests/dp/tasks/dp_d
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
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
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

ll wt[105], v[105], dp[105][100005];
ll rec(int idx, int w_left) {
    if(idx < 0) return 0;
    if(w_left == 0) return 0;
    if(dp[idx][w_left] != -1) return dp[idx][w_left];
    
    //don't choose this item 
    ll ans = rec(idx-1, w_left);
   
    //choose this item 
    if(w_left-wt[idx] >= 0)
        ans = max(ans, rec(idx-1, w_left-wt[idx]) + v[idx]);
   
    return dp[idx][w_left] = ans;
}

void solve() {
    ll n, w;
    cin >> n >> w;
    
    rep0(i, n) {
       cin >> wt[i] >> v[i]; 
    }
    
    memset(dp, -1, sizeof(dp));
    
    ll ans = rec(n-1, w);
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