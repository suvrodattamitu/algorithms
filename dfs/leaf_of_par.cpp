//https://codeforces.com/contest/1843/problem/D
#include <bits/stdc++.h>
using namespace std;

#define edge(xxxx,yyyy) ((xxxx)*(m+5)+(yyyy))
#define oo 1e18
#define fi first
#define se second
#define sp(iiii) setprecision(iiii)
#define IO ios_base::sync_with_stdio(false); cin.tie(0)
#define ms(aaaa,xxxx) memset(aaaa,xxxx,sizeof(aaaa))
#define cntbit(xxxx) __builtin_popcount(xxxx)
#define getbit(xxxx,aaaa) (((xxxx)>>((aaaa)-1))&1)
#define totbit(xxxx) (32-__builtin_clz(xxxx))
#define totbitll(xxxx) (64-__builtin_clzll(ll(xxxx)))

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,long long> plll;
typedef pair<pair<long long,long long>,pair<long long,long long>> pllll;
typedef pair<pair<long long,long long>,bool> pllb;

const ll base=333333349;
const ll mod=1e9+7;
const ld eps=1e-5;
const ll maxn=50009;

ll t,it,n,i,child[500009],deg[500009],u,v,q;
vector<ll> g[500009];

void dfs(ll x,ll y) {
    if (deg[x] == 1) {
        child[x] = 1;
    }

    for (ll ii:g[x]) {
        if (ii != y) {
            dfs(ii,x);
            child[x] += child[ii];
        }
    }
}

int main(){
    IO;
    #ifndef ONLINE_JUDGE
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #else
    #endif
    cin>>t;
    for (it=1;it<=t;it++) {
        cin>>n;
        deg[1]=1;
        for (i=1;i<n;i++) {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        dfs(1,1);
        cin>>q;
        for (i=1;i<=q;i++) {
            cin>>u>>v;
            cout<<child[u]*child[v]<<'\n';
        }
        for (i=1;i<=n;i++) {
            g[i].clear();
            deg[i]=0;
            child[i]=0;
        }
    }
}

.........................

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a));
#define put(n) (cout << n << endl)
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
typedef vector<ll> vi;
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

vector<vector<ll>> graph;
vector<ll> leaf;

void dfs(ll u, ll par) {
    for(ll v : graph[u]) {
        if(v == par) continue;
        dfs(v, u);
        leaf[u] += leaf[v];
    }
    
    if (leaf[u] == 0) {
        leaf[u] = 1;
    }
}

void solve() {
    ll n;
    get(n);
    
    graph.resize(n+1);
    leaf.assign(n+1, 0);
    
    rep0(i, n-1) {
       ll u, v;
       get2(u, v); --u, --v;
       graph[u].pb(v);
       graph[v].pb(u);
    }
    
    dfs(0, -1);
        
    ll q;
    get(q);
    
    while(q--) {
        ll u, v;
        get2(u, v); --u, --v;
        ll ans = leaf[u] * leaf[v];
        put(ans);
    }
    
    graph.clear();
    leaf.clear();
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int tc = 1;
	get(tc);
	while (tc--) {
		solve();
	}
}
