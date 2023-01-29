//https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
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
    int dp[301][301];
    int rec(int cur_i, int cur_j, vector<vector<int>>& matrix) {
        if(cur_i >= len(matrix) || cur_j >= len(matrix[0]) || matrix[cur_i][cur_j] == 0) return 0;
        
        if(dp[cur_i][cur_j] != -1) return dp[cur_i][cur_j];

        int cur_ans = 1 + min({ rec(cur_i + 1, cur_j, matrix), rec(cur_i, cur_j + 1, matrix), rec(cur_i + 1, cur_j + 1, matrix) });

        return dp[cur_i][cur_j] = cur_ans;
    }

    int countSquares(vector<vector<int>>& matrix) {
        int row = len(matrix);
        int col = len(matrix[0]);

        memset(dp, -1, sizeof(dp));

        int ans = 0;
        rep0(i, row) {
            rep0(j, col) {
                ans += rec(i, j, matrix);
            }
        }

        return ans;
    }
};