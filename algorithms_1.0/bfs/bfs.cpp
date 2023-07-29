//https://codeforces.com/problemset/problem/977/E
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define ll long long 
#define MAX 200001

vector<int> adj[MAX];
int vis[MAX];

ll bfs(int src) {
    queue<int> q;
    q.push(src);

    bool flag = 1;
    while(!q.empty()) {
        src = q.front();
        q.pop();

        if(adj[src].size() != 2) {
            flag = 0;
        }

        for(auto v : adj[src]) {
            if(!vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }

    return flag;
}

void solve() {
    int v, e;
    cin >> v >> e;

    int x, y;
    for(int i = 0; i < e; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans = 0;
    for(int i = 1; i <= v; i++) {
        if(!vis[i]) {
            int is_cycled = bfs(i);
            if(is_cycled) ++ans;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1 ;
    //cin >> tc;

    while(tc--) {
        solve();
    }

    return 0;
}