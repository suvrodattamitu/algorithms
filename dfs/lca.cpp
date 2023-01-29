//https://www.youtube.com/watch?v=il2HXsJPGO4
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
typedef vector<vector<ll>> vii;
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

vi p;
vii graph;
void dfs(ll u, ll parent = -1) {
    p[u] = parent;
    for(ll v : graph[u]) {
        if(v != parent) {
            dfs(v, u);
        }
    }
}

vi path(ll u) {
    vi routes;
    
    while(p[u] != -1) {
        routes.pb(p[u]);
        u = p[u];
    }
    
    reverse(all(routes));
    
    return routes;
}

void solve() {
    ll n, q;
    cin >> n >> q;
   
    graph.resize(n+1);
    p.resize(n+1, -1);
   
    ll x, y;
    rep0(i, n-1) {
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
   
   dfs(1);
   
   // cout << p[6] << " " << p[9] << endl;
   
  ll a, b;
  while(q--) {
    cin >> a >> b;
    vi path_a = path(a);
    vi path_b = path(b);
    
    // put(path_a);
    // put(path_b);
    
    ll mn_len = min(len(path_a), len(path_b));
    
    ll lca = -1;
    rep0(i, mn_len) {
        if(path_a[i] == path_b[i]) {
            lca = path_a[i];
        } else {
            goto x;
        }
    }
    
    x: put(lca);
  }
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

/*
input :
// n q

//n-1
13 2
1 2
1 3
1 13
2 5
5 6
5 7
5 8
8 12
3 4
4 9
4 10
10 11

//q
6 7
11 12

output: 
5
1
*/