//https://leetcode.com/problems/find-eventual-safe-states/description/
//https://leetcode.com/problems/array-nesting/description (almost similar)

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
#define get(n) (cin >> n)
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

class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis, safe;
    map<int, int> trmnl_nodes;

    bool dfs(int u, vector<vector<int>>& graph) {
        vis[u] = 1;
        for(int v : graph[u]) {
            if(vis[v] == 0) {
               if(dfs(v, graph)) return 1;
            }

            else if(vis[v] == vis[u]) return 1;
        }
        vis[u] = 3;

        return 0;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = len(graph);
        vis.resize(n, 0);
        
        vector<int> ans;
        rep0(i, n) { 
            vis.resize(n, 0);
            if(!dfs(i, graph)) { //if not cycle;
                ans.pb(i);
            }
        }

        return ans;
    }
};