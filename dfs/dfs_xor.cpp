//https://codeforces.com/contest/1592/problem/C
#include<iostream>
#include<vector>
using namespace std;

#define ll long long 
const int N = 1e5 + 5;
 
int n, k, a[N], res, tot;
vector<int> adj[N];

void dfs(int u, int p) {
	for (auto v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            a[u] ^= a[v];
        }
    }

	if (a[u] == tot) {
		res ++, a[u] = 0;
    }
}

void solve() {
    cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
        adj[i].clear();
    }
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
	tot = 0;
	for (int i = 1; i <= n; i++) {
		tot ^= a[i];
    }
	if (tot == 0) {
		// break to two part (always done)
		return cout << "YES\n", (void) 0;
	}
	if (k == 2) {
		cout << "NO\n";
	} else {
		// three part best ??
		res = 0;
		dfs(1, 1);
		cout << (res >= 3 ? "YES\n" : "NO\n");
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1 ;
    cin >> tc;

    while(tc--) {
        solve();
    }

    return 0;
}