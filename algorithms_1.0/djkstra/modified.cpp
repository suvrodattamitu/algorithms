//https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/
//https://www.youtube.com/watch?v=w9oMct1YeAg : 10:15 minutes

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
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int m = grid.size(), n = grid[0].size(); 
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; 
        vector<vector<int>> d(m, vector<int>(n, INT_MAX)); 

        pq.push({0, 0, 0}); 
        d[0][0] = 0; 
        while (!pq.empty()) {
            auto [t, i, j] = pq.top(); 
            pq.pop(); 
            if (i == m-1 && j == n-1) return t; 
            int dir[5] = {-1, 0, 1, 0, -1}; 
            for (int k = 0; k < 4; ++k) {
                int ii = i + dir[k], jj = j + dir[k+1]; 
                if (ii >= 0 && ii < m && jj >= 0 && jj < n) {
                    int diff = grid[ii][jj] - t; 
                    if (diff < 0) diff = 0; 
                    else if (diff & 1) diff = diff/2*2; // or diff = diff - 1 , cz for odd we need exact amount of time to go to a cell
                    int vv = t + 1 + diff; // if even we need 1 more unit time cz we have to come and go to the grid
                    if (d[ii][jj] > vv) {
                        d[ii][jj] = vv; 
                        pq.push({vv, ii, jj}); 
                    }
                }
            }
        }
        
        return -1; 
    }
};

/*
example
t-6 , though it is 6 we need 7 unit of time
a->b 1
a<-b 2
a->b 3
a<-b 4
a->b 5
a<-b 6
a->b 7
*/