//https://leetcode.com/problems/maximal-square/description/
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
#define get2(a,b)get(a)get(b)
#define get3(a,b,c)get2(a,b)get(c)
#define get4(a,b,c,d)get2(a,b)get2(c,d)
#define get5(a,b,c,d,e)get4(a,b,c,d)get(e)
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
    int rows, cols, dp[305][305];
    bool is_valid(int i, int j, vector<vector<char>>& matrix) {
        if(i >= 0 && i < rows && j >= 0 && j < cols) return (matrix[i][j] == '1');
        return false;
    }

    int rec(int i, int j, vector<vector<char>>& matrix) {
        if(dp[i][j] != -1) return dp[i][j];
        
        if(is_valid(i, j, matrix)) {
            //min(min(a, b), c)
            return dp[i][j] = 1 + min( min(rec(i, j+1, matrix),  rec(i+1, j, matrix)),  rec(i+1, j+1, matrix) ); 
        }

        return dp[i][j] = 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        rows = len(matrix);
        cols = len(matrix[0]);

        memset(dp, -1, sizeof(dp));

        int mx = 0;
        rep0(i, rows) {
            rep0(j, cols) {
                if(matrix[i][j] == '1') {
                    int cur_mx = rec(i, j, matrix);
                    mx = max(mx, cur_mx);   
                }
            }
        }

        return (mx*mx);
    }
};