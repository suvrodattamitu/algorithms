//https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 1; i--)
#define all(a) (a.begin()), (a.end())
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

class dsu {
public:
    int n;
    vector <int> root, sz;
    int comp;
  
    dsu(int n) {
      root.resize(n+1);
      sz.resize(n+1, 1);
      for (int i = 0; i < n; ++i) root[i] = i;
      comp = n;
    }
    
    int get_root(int u) {
      return (u == root[u]? u: (root[u] = get_root(root[u])));
    }
    
    bool connected(int u, int v) {
      if (get_root(u) == get_root(v))
        return true;
      return false;
    }
    
    void merge(int u, int v) {
      if (connected(u, v))
        return ;
      u = get_root(u);
      v = get_root(v);
      comp--;
      if (sz[v] > sz[u])
        swap(u, v);
      root[v] = u;
      sz[u] += sz[v];
    }
    
    int get_size(int i) {
        return sz[get_root(i)];
    }
    
    int count() {
      return comp;
    }
};

class Solution {
public:
    vector<int> mst_parts;
    int MST(int n, vector<vector<int>>& edges, int include, int exclude) {
        dsu d(n);

        int cost = 0;
        if(include != -1) { // this edge must be included first, cz its mandatory edge
          auto edge = edges[include];
          int a = edge[0], b = edge[1], w = edge[2], e_no = edge[3];
          d.merge(a, b);
          cost += w;
        }

        rep0(i, len(edges)) {
            if(i == include || i == exclude) continue;
            auto edge = edges[i];
            int a = edge[0], b = edge[1], w = edge[2], e_no = edge[3];

            if(!d.connected(a, b)) {
                mst_parts[e_no] = 1;
                cost += w;
                d.merge(a, b);
            }
        }

        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int e_sz = len(edges);
        mst_parts.resize(e_sz+1, 0);
        rep0(i, e_sz) {
            edges[i].pb(i);
        }

        sort(all(edges), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        int mst_cost = MST(n, edges, -1, -1);
        
        // till now we done just mst, here begin actual code for this problem
        vector<int> pseudo;
        vector<int> critical;
        rep0(i, e_sz) {
          int cur_edge_no = edges[i][3];

          //exclude current edge
          int excluded_cost = MST(n, edges, -1, i);
          if(excluded_cost != mst_cost) {
            critical.pb(cur_edge_no);
          } else { //check and confirm it is equal to mst_cost
            int included_cost = MST(n ,edges , i , -1);
            if (included_cost == mst_cost){
              pseudo.pb(cur_edge_no);
            }
          }
        }

        return {critical , pseudo};
    }
};