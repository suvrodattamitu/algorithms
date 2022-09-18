//https://codeforces.com/contest/1689/problem/C
//https://www.youtube.com/watch?v=i3CZflE8MT4&t=250s

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <math.h>
#include <string>
using namespace std;

#define ll long long

vector<vector<ll>> adj(300005);
ll child[300005];
ll dp[300005][3];

/*
1. how many child of a parent using dfs
*/
void dfs(ll now, ll parent) {
    child[now] = 1;

    for(auto v: adj[now]) {
        if(v != parent) {
            dfs(v, now);
            child[now] += child[v];
            //cout << now << " " << child[now] << endl << endl; , how many child of a parent
        }
    }
}

ll rec(ll i, ll p, ll f) {
    vector<ll> v;
    for(auto j: adj[i]) {
        if(j != p){
            v.push_back(j);
        }
    }

    if(dp[i][f] != -1) return dp[i][f];
    if(v.size() == 0) return 0;
    if(v.size() == 1) return child[v[0]]-1; // coz we have always child counted with root, so remove root(-1)
    return dp[i][f] = max(child[v[0]]+rec(v[1], i, 1), child[v[1]]+rec(v[0], i, 0)) - 1; //remove root from counting(-1)
}

void solve() {
    ll n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
		adj[i].clear();
	}

    for(int i = 0; i < n-1; i++) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1); //or dfs(1, 1)

    memset(dp, -1, sizeof(dp));
    int ans = rec(1, -1, 4); //or rec(1, 1, 3)

    cout << ans << endl;
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