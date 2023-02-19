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

int parent[N], sz[N];
void make(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find(int v) {
    if(parent[v] == v) 
        return parent[v];
    return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void solve() {
    int n, e, q;
    cin >> n >> e >> q;

    vector<tuple<int, int, int, int>> edges;
    int u, v, wt;
    rep0(i, e) {
        cin >> u >> v >> wt;
        edges.emplace_back(wt, u, v, -1);
    }

    rep0(i, q) {
        cin >> u >> v >> wt;
        edges.emplace_back(wt, u, v, i);
    }

    sort(all(edges));

    for(int i = 1; i <= n; i++) make(i);
    
    vector<string> ans(q);
    for(auto [wt, u, v, i] : edges) { //let's do kruskal things
        if(i == -1) Union(u, v);
        else if(find(u) == find(v)) ans[i] = "No"; //will make cycle, dont add
        else ans[i] = "Yes"; //add this
    }

    rep0(i, q) put(ans[i]);
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