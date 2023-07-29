//https://leetcode.com/problems/minimum-path-sum/description/
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
    int dp[205][205];
    int rec(int r, int c, vector<vector<int>>& grid) {
        if(r == 0 && c == 0)  return grid[r][c];
        if(dp[r][c] != -1) return dp[r][c];

        int ans = INT_MAX;
        if(r-1 >= 0) ans = min(ans, grid[r][c] + rec(r-1 , c,  grid));
        if(c-1 >= 0) ans = min(ans, grid[r][c] + rec(r , c-1, grid));
        return  dp[r][c] = ans;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int rows = len(grid);
        int cols = len(grid[0]);

        memset(dp, -1, sizeof(dp));

        int ans = rec(rows-1, cols-1, grid);
        return ans;
    }
};