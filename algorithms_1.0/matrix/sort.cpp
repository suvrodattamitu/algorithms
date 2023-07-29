//https://leetcode.com/contest/weekly-contest-323/problems/delete-greatest-value-in-each-row/
#include<bits/stdc++.h>
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
#define lens(str) ((ll)str.length())
#define lena(arr) ((ll)arr.size()) 
#define pb push_back
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        
        rep0(i, row) {
            sort(all(grid[i]), greater<int>());
        }
        
        int ans = 0;
        rep0(i, col) {
            int mx = 0;
            rep0(j, row) {
                mx = max(mx, grid[j][i]);
            }
            ans += mx;
        }
        
        return ans;
    }
};