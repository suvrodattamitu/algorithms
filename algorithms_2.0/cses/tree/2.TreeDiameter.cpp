#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define For(i, a, n) for(ll i = a; i <= n; i++)
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 1; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a));

//output
#define put(a) (cout << a << endl)
#define put2(a, b) (cout << a << " " << b << endl)
#define spaced(n) (cout << n << " ")
#define ln() (cout << "\n")

//input
#define get(n) (cin >> n);
#define get2(a,b)get(a)get(b)
#define get3(a,b,c)get2(a,b)get(c)
#define get4(a,b,c,d)get2(a,b)get2(c,d)
#define get5(a,b,c,d,e)get4(a,b,c,d)get(e)

#define len(x) ((ll)x.size()) 
#define pb push_back
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
const ll maxn = 2e5;

typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef pair<ll, ll> pii;

void out(){cout << '\n';}
template<class T>void out(const T& a){cout << a << '\n';}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){cout << head << ' ';out(tail...);}

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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}

template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}

template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...);
#endif

vii graph;
vi down_path, diameter;
void dfs1(ll src, ll par) {
    ll max_down_path = 0, is_leaf = 1;
    for(ll child : graph[src]) {
        if(child == par) continue;
        is_leaf = 0;
        dfs1(child, src);
        max_down_path = max(max_down_path, down_path[child]);
    }
    
    if(is_leaf) {
        down_path[src] = 0;
    }
    
    else {
        down_path[src] = 1 + max_down_path;
    }
}

void dfs2(ll src, ll par) {
    ll ans = 0;
    vi childs_down_paths;
    for(ll child : graph[src]) {
        if(child == par) continue;
        dfs2(child, src);
        childs_down_paths.pb(down_path[child]);
        ans = max(ans, diameter[child]);
    }
    
    ll childs = len(childs_down_paths);
    sort(all(childs_down_paths));
    
    if(childs == 0) {
        diameter[src] = 0;
    } else if(childs == 1) {
        diameter[src] = 1 + childs_down_paths[0];
    } else {
        diameter[src] = 2 + childs_down_paths[childs-1] + childs_down_paths[childs-2];
    }
    
    diameter[src] = max(ans, diameter[src]);
}

void solve() {
    ll n;
    get(n);
    
    graph.resize(n+1);
    down_path.resize(n+1, 0);
    diameter.resize(n+1, 0);
    
    ll x, y;
    rep0(i, n-1) {
        get2(x, y);
        graph[x].pb(y);
        graph[y].pb(x);
    }
    
    dfs1(1, 0);    
    dfs2(1, 0);
    
    put(diameter[1]);
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