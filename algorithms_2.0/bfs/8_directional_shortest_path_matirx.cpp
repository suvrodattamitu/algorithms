//https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
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

class Solution {
public:
    int dirX[8] = {1,0,-1,0,1,1,-1,-1};
    int dirY[8] = {0,1,0,-1,1,-1,-1,1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;

        int rows = len(grid), cols = len(grid[0]);
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>>dist(rows, vector<int>(cols, 1e9));

        q.push({{0, 0}, 0});
        dist[0][0] = 0;
        while(!q.empty()) {
            auto tp = q.front(); 
            int x = tp.first.first;
            int y = tp.first.second;
            int dis = tp.second;
            q.pop();

            for(ll k = 0; k < 8; k++) {
                ll xx = x + dirX[k];
                ll yy = y + dirY[k];
                if(xx < 0 || yy < 0 || xx >= rows || yy >= cols || grid[xx][yy] == 1) continue;
                if(dist[xx][yy] > dist[x][y] + 1) { // you can use if(dist[xx][yy] > dis + 1) 
                    dist[xx][yy] = dist[x][y] + 1; // you can use dist[xx][yy] = dis + 1
                    q.push({{xx, yy}, dist[xx][yy]});
                }
            }
        }

        if(dist[rows-1][cols-1] == 1e9) return -1;

        return dist[rows-1][cols-1]+1;
    }
};