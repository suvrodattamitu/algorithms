//https://codeforces.com/problemset/problem/1106/D
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <queue>

#define N 300010
using namespace std;

typedef long long LL;

priority_queue<int, vector<int>, greater<int>> Q;
vector<int> g[N];
vector<int> seq;
bool vis[N];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vis[1] = true;
	Q.push(1);
	while (!Q.empty()){
		int now = Q.top();
		Q.pop();
		seq.push_back(now);
		for (auto p : g[now]){
			if (!vis[p]){
				Q.push(p);
				vis[p] = true;
			}
		}
	}
	
	for (auto p : seq){
		printf("%d ", p);
	}
	return 0;
}

