//https://leetcode.com/problems/network-delay-time/description/
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

class Solution {
public:
    ll djkstra(int source, int n, vector<pair<int, int>> g[N]) {
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

            for(auto v : g[u]) {
                int child_v = v.first;
                int child_wt = v.second;
    
                if(dis[u] + child_wt < dis[child_v]) {
                    dis[child_v] = dis[u] + child_wt;
                    pq.push({dis[child_v], child_v});
                }
            }
        }

        ll ans = 0LL;
        rep1(i, n) {
            if(dis[i] == oo) return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> g[N];
        for(auto vec : times) {
            g[vec[0]].pb({vec[1], vec[2]});
        }

        int ans = djkstra(k, n, g);
        return ans;
    }
};