//https://codeforces.com/contest/1303/problem/C
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

const int C = 26;

vector <int> g[C];
bool vis[C], ok;
string ans;

void add_edge (int u, int v) {
	bool fl = 0;
	for (int x: g[u])
		fl |= (x == v);

	if (fl) return;

	g[u].pb(v);
	if (len(g[u]) > 2) ok = 0;
}

void dfs (int v) {
	vis[v] = 1;
	ans += char(v + 'a');

	for (int u : g[v])
		if (!vis[u]) dfs(u);
}

void solve() {
    string s;
	cin >> s;

	for (int i = 0; i < C; i++)
	{
		g[i].clear();
		vis[i] = 0;
	}
	
	ok = 1;
	for (int i = 0; i < len(s) - 1; i++) {
		int a = s[i] - 'a', b = s[i + 1] - 'a';

		add_edge(a, b);
		add_edge(b, a);

		if (!ok) break;
	}

	if (!ok) {
		put("NO");
		return;
	}

	ans = "";
	for (int i = 0; i < C; i++) {
		if (!vis[i] && len(g[i]) < 2) {
		    dfs(i);
		}
	}

	for (int i = 0; i < C; i++) ok &= vis[i];

	if (!ok) {
	    put("NO");
	} else {
		put("YES");
		cout << ans << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tc;
	get(tc);
	while (tc--) {
		solve();
	}
}