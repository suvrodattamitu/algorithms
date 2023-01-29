//https://atcoder.jp/contests/abc285/tasks/abc285_d
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF ll(1e18)
// #define mod 998244353
// #define mod2 1000000007
#define eps 1e-9
#define abs(x) ((x)>=0?(x):-(x))
#define y1 solai
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<pll, ll> plll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N=200100;
ll n,k,ans,w[N];
vector<ll>v[N];
string s,t;
map<string,ll>m;

void dfs(ll x)
{
	w[x]=1;
	for(ll to:v[x])
	{
		if(w[to]==1)
			ans=0;
		if(!w[to])
			dfs(to);
	}
	w[x]=2;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	ans=1;
	for(ll i=1;i<=n;i++)
	{
		cin>>s>>t;
		if(!m.count(s))
			m[s]=++k;
		if(!m.count(t))
			m[t]=++k;
		v[m[s]].pb(m[t]);
	}

	for(ll i=1;i<=k;i++)
		if(!w[i])
			dfs(i);
	if(ans)
		cout<<"Yes";
	else
		cout<<"No";
}

/*
cycle detection
#include <bits/stdc++.h>
using namespace std;


#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ld double
#define pb push_back
#define sz(a) (int)a.size()
#define forn(i, n) for (int i = 0; i < n; ++i)
#define pii pair <int, int>
#define vec pt
#define vc vector
#define all(a) a.begin(), a.end()
#define int long long

template<class T>
bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
using pq = priority_queue<T, vc<T>, greater<T>>;



const int K = 11;
const int N = 1e5;
const int inf = 1e18;

map <string, int> used;
map <string, vector <string>> g;

void dfs (string u, string p) {
    used[u] = 1;
    for (string v : g[u]) {
        if (v == p) continue;
        if (used[v]) {
            cout << "No\n";
            exit(0);
        }
        dfs(v, u);
    }
}

void solve () {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s, t;
        cin >> s >> t;
        g[s].pb(t);
        g[t].pb(s);
    }
    for (auto [x, y] : g) {
        if (!used[x])
            dfs(x, "");
    }
    cout << "Yes\n";
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
*/