#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define For(i, a, n) for(ll i = a; i <= n; i++)
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a));
#define put(n) (cout << n << endl)
#define spaced(n) (cout << n << " ")
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
 
vector<vector<int>> graph;
vector<int> visited, parent;
 
int has_cycled = 0, start_node = -1, end_node = -1;
void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    
    while(!q.empty()) {
        int tp = q.front(); 
        q.pop();
        
        for(int v : graph[tp]) {
            if(!visited[v]) {
                q.push(v);
                visited[v] = 1;
                parent[v] = tp;
            } else {
                if(parent[tp] != v) {
                    has_cycled = 1;
                    start_node = v;
                    end_node = tp;
                }
            }
        }
    }
}
 
void solve() {
    ll n, m;
    get2(n, m);
    
    graph.resize(n+1);
    visited.resize(n+1, 0);
    parent.resize(n+1, -1);
 
    rep0(i, m) {
        ll x, y;
        get2(x, y);
        
        graph[x].pb(y);
        graph[y].pb(x);
    }

    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            bfs(i);
        }
    }
    
    if(has_cycled) {
        vector<int> path1;
        
        int node = end_node;
        while (node != -1) {
            path1.push_back(node);
            node = parent[node];
        }
        
        vector<int> path2;
        node = start_node;
        while (node != -1) {
            path2.push_back(node);
            node = parent[node];
        }
        
        //lca finding
        int mn_len = min(len(path1), len(path2));
        int lca = -1, tmpl = mn_len;
        while(tmpl >= 0) {
            if(path1[len(path1) - tmpl] == path2[len(path2) - tmpl]) {
                lca = path1[len(path1) - tmpl];
                break;
            }
            
            tmpl--;
        }
        
        vector<int> cycle;
        rep0(i, len(path1)) {
            cycle.pb(path1[i]);
            if(path1[i] == lca) break;
        }
        
        vector<int> arr;
        rep0(i, len(path2)) {
            if(path2[i] == lca) break;
            arr.pb(path2[i]);
        }
        
        reverse(all(arr));
        
        rep0(i, len(arr)) {
            cycle.pb(arr[i]);
        }
        
        cycle.pb(end_node);
        
        put(len(cycle));
        put(cycle);
    }
    
    else if(!has_cycled) {
        put("IMPOSSIBLE");
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

