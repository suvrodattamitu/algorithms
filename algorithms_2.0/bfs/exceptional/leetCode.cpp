//https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define For(i, a, n) for(ll i = a; i <= n; i++)
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 1; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, 0, sizeof(a))
#define len(x) ((ll)x.size()) 
#define pb push_back
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define SUM(v) accumulate(all(v), 0LL)
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
const ll maxn = 2e5;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;

int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ll n = len(grid);
        if (grid[0][0] || grid[n-1][n-1]) return 0;

        priority_queue <array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq1;
        vvi dis(n, vi(n, oo));
        
        //push all the theif in queue and initialize distance
        rep0(i, n) {
            rep0(j, n) {
                if(grid[i][j]) {
                    pq1.push({0, i, j});
                    dis[i][j] = 0;
                } else {
                    dis[i][j] = oo;
                }
            }
        }

        //store distance 
        while(!pq1.empty()) {
            auto tp = pq1.top();
            ll x = tp[1], y = tp[2], d = tp[0];
            pq1.pop();
            
            rep0(i, 4) {
                ll xx = x + dirX[i], yy = y + dirY[i];
                if(xx >= 0 && xx < n && yy >= 0 && yy < n && d+1 < dis[xx][yy]) {
                    pq1.push({d+1, xx, yy});
                    dis[xx][yy] = d+1;
                }
            }
        }

        priority_queue<array<ll, 3>> pq2;
        vvi vis(n, vi(n, 0));
        
        pq2.push({dis[0][0], 0, 0});
        while(!pq2.empty()) {
            auto tp = pq2.top();
            ll d = tp[0], x = tp[1], y = tp[2];
            pq2.pop();

            if(x == n-1 && y == n-1) {
                return d;
            }

            rep0(i, 4) {
                ll xx = x + dirX[i], yy = y + dirY[i];
                if(xx >= 0 && xx < n && yy >= 0 && yy < n && !vis[xx][yy]) {
                    ll mn_dis = min(d, dis[xx][yy]);
                    pq2.push({mn_dis, xx, yy});
                    vis[xx][yy] = 1;
                }
            }
        }

        return 0;
    }
};