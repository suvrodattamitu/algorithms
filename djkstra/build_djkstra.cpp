//https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/
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
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Graph {
public:
    vector<pair<int, int>> graph[N];
    Graph(int n, vector<vector<int>>& edges) {
        for(auto edge : edges) {
            int x = edge[0], y = edge[1], w = edge[2];
            graph[x].pb({y, w});
        }
    }
    
    void addEdge(vector<int> edge) {
        int x = edge[0], y = edge[1], w = edge[2];
        graph[x].pb({y, w});
    }
    
    int shortestPath(int source, int dest) {
        vi vis(N, 0);
        vi dis(N, oo);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0, source});
        dis[source] = 0;

        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int u = node.second;

            if (vis[u]) continue;
            vis[u] = 1;

            for(auto v : graph[u]) {
                int child_v = v.first;
                int child_wt = v.second;
    
                if(dis[u] + child_wt < dis[child_v]) {
                    dis[child_v] = dis[u] + child_wt;
                    pq.push({dis[child_v], child_v});
                }
            }
        }

        if (dis[dest] == oo) return -1;

        return dis[dest];
    }
};