#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
#define pb push_back

int cur;
void dfs(int v, vi &vis, vvi &g)
{
    vis[v] = 1;
    cur++;
    for (auto u : g[v])
    {
        if (!vis[u]) {
            dfs(u, vis, g);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    
    vii g(n);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    for(int i = 0; i < n; i++)
    {
        if (g[i].size() != 2)
        {
            cout << "NO\n";
            return;
        }
    }
    
    vi vis(n);
    for(int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cur = 0;
            dfs(i, vis, g);
            if (cur % 2)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
