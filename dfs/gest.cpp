#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define elif else if
#define int long long
#define rt return
const int BINF = 9e8, LINF = 2e9, mod = 1e9 + 7, P = 179, Q = 1791791791;
const int MAXN = 1e5 + 7;
vector<int> g[MAXN];
int vis[MAXN];
void dfs(int v) {
	vis[v] = 1;
	for (int u : g[v])
		if (!vis[u])
			dfs(u);
}
void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int ans = n;
	for (int i = 0; i < n; ++i) 
		if (!vis[i]) {
			--ans;
			dfs(i);
		}
	cout << k - ans;
	return;
}
signed main() {
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}