//https://atcoder.jp/contests/abc284/tasks/abc284_e
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
const ll MOD = 100000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
//const ll N = 1e5+10;
const int N=210000;
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

vii graph(N);
vi vis(N, 0);
ll ans = 0;

void dfs(int x) {
	vis[x]=1;
	++ans;
	if (ans>=1000000) {
		printf("%d\n",ans);
		exit(0);
	}
	for (auto v:graph[x]) if (!vis[v]) {
		dfs(v);
	}
	vis[x]=0;
}

int main() {
    int n, m;
    scanf("%d%d", &n,&m);
	for (int i=1;i<=m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		graph[u].pb(v);
		graph[v].pb(u);
	}
	dfs(1);
	printf("%d\n",ans);
}