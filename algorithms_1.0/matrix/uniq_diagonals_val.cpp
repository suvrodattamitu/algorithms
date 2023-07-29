//https://leetcode.com/contest/weekly-contest-347/problems/difference-of-number-of-distinct-values-on-diagonals/
#include<bits/stdc++.h>
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
#define get(n) (cin >> n);
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
    int rows, cols;
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        rows = len(grid);
        cols = len(grid[0]);
        
        vector<int> row(cols, 0);
        vector<vector<int>> ans(rows, row);
        
        rep0(i, rows) {
            rep0(j, cols) {
                set<int> a,b;
                for(int k = 1; i-k >= 0 && j-k >= 0; k++) a.insert(grid[i-k][j-k]);
                
                for(int k =1; i+k < rows && j+k < cols; k++) b.insert(grid[i+k][j+k]);
                
                ans[i][j] = abs((int)(len(a) - len(b)));    
            }
        }
                    
        return ans;
    }
};